<?php

define('CUSTOM_CURRENCIES_URL', 'https://www.cbr.ru/scripts/XML_val.asp');
define('CUSTOM_CURRENCIES_RATE_URL', 'https://www.cbr.ru/scripts/XML_daily.asp');

function custom_currencies_fetch_currencies() {
  $count = 0;
  $entity_type = 'custom_currencies';
  $url = CUSTOM_CURRENCIES_URL;
  try {
    $xml = simplexml_load_file($url);
  } catch (Exception $e) {
    watchdog(
      'custom_currencies',
      t('Unable to fetch data from @url for reason @res'),
      array('@url' => $url, '@res' => $e->getMessage()),
      WATCHDOG_ERROR
    );
    return $count;
  }
  $codes = custom_currencies_get_codes();
  foreach ($xml->Item as $item) {
    $code = (string) $item['ID'];
    if (!isset($codes[$code])) {
      $data = array(
        'code' => $code,
        'name' => $item->Name,
      );
      $entity = entity_create($entity_type, $data);
      $wrapper = entity_metadata_wrapper($entity_type, $entity);
      $wrapper->save();
      $count++;
    }
  }
  return $count;
}

function custom_currencies_fetch_currencies_rates($date = NULL) {
  $count = 0;
  $entity_type = 'custom_currencies_rates';
  $url = CUSTOM_CURRENCIES_RATE_URL;
  if ($date) {
    $url .= '?date_req=' . date('d/m/Y', $date);
  }

  try {
    $xml = simplexml_load_file($url);
  } catch (Exception $e) {
    watchdog(
      'custom_currencies_rates',
      t('Unable to fetch data from @url for reason @res'),
      array('@url' => $url, '@res' => $e->getMessage()),
      WATCHDOG_ERROR
    );
    return $count;
  }

  if (!count($xml->Valute)) {
    return $count;
  }

  $timestamp = strtotime( (string) $xml['Date']);

  $codes = custom_currencies_get_codes();
  $ids = array_flip($codes);

  $rates = custom_currencies_get_rates_by_date($timestamp);
  $existing_rates = array();
  foreach ($rates as $rate) {
    if (isset($ids[$rate->cid])) {
      $existing_rates[$ids[$rate->cid]] = $rate->rid;
    }
  }

  foreach ($xml->Valute as $item) {
    $code = (string) $item['ID'];
    if (!isset($codes[$code])) {
      watchdog(
        'custom_currencies',
        t('Undefined currency code @code'),
        array('@code' => $code),
        WATCHDOG_NOTICE
      );
      continue;
    }

    $value = (float) str_replace(',', '.', (string) $item->Value);
    $data = array(
      'cid' => $codes[$code],
      'date' => $timestamp,
      'rate' => $value / $item->Nominal,
    );
    if (!isset($existing_rates[$code])) {
      $entity = entity_create($entity_type, $data);
      $wrapper = entity_metadata_wrapper($entity_type, $entity);
      $wrapper->save();
      $count++;
    } //TODO: update existing rates
  }
  return $count;
}

function custom_currencies_get_codes() {
  $codes = array();
  $currencies = entity_load('custom_currencies', FALSE, array(), TRUE);
  foreach ($currencies as $currency) {
    $codes[$currency->code] = $currency->cid;
  }
  return $codes;
}

function custom_currencies_get_rates_by_date($timestamp) {
  $entity_type = 'custom_currencies_rates';
  $result = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $entity_type)
        ->propertyCondition('date', $timestamp);
  $list = $query->execute();
  if (isset($list[$entity_type])) {
    $result = entity_load($entity_type, array_keys($list[$entity_type]));
  }
  return $result;
}

function custom_currencies_batch_process(&$context) {
  $count = custom_currencies_fetch_currencies();
  $context['message'] = t('@count currencies were fetched', array('@count' => $count));
}

function custom_currencies_rates_batch_process($timestamp, &$context) {
  $count = custom_currencies_fetch_currencies_rates($timestamp);
  $date = format_date($timestamp, 'short');
  $context['message'] = t(
    '@count currencies rates for date @date were fetched',
    array('@count' => $count, '@date' => $date)
  );
}

function custom_currencies_rates_batch_finished($success, $results, $operations) {
  drupal_set_message(t('The currencies rates was fetched'));
}