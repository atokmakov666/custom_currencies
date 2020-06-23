<?php

function custom_currencies_batch_form($form, &$form_state) {
  $form = array(
    'date_from' => array(
      '#type' => 'date',
      '#field_prefix' => t('From'),
      '#default_value' => '',
    ),
    'date_to' => array(
      '#type' => 'date',
      '#field_prefix' => t('to'),
      '#default_value' => '',
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Fetch')
    ),
  );
  return $form;
}

function custom_currencies_batch_form_submit($form, &$form_state) {
  $date_from = $form_state['values']['date_from'];
  $date_to = $form_state['values']['date_to'];
  $ts_from = strtotime("{$date_from['year']}-{$date_from['month']}-{$date_from['day']}");
  $ts_to = strtotime("{$date_to['year']}-{$date_to['month']}-{$date_to['day']}");
  if ($ts_from > time()) {
    $ts_from = time();
  }
  if ($ts_to > time()) {
    $ts_to = time();
  }
  if ($ts_from > $ts_to) {
    // swap dates
    list($ts_from, $ts_to) = array($ts_to, $ts_from);
  }

  $batch = array(
    'title' => t('Fetch currencies rates'),
    'operations' => array(array('custom_currencies_batch_process', array())),
    'finished' => 'custom_currencies_rates_batch_finished',
    'file' => drupal_get_path('module', 'custom_currencies') . '/custom_currencies.inc',
  );
  for ($timestamp = $ts_from; $timestamp <= $ts_to; $timestamp += 24 * 60 * 60) {
    $batch['operations'][] = array('custom_currencies_rates_batch_process', array($timestamp));
  }
  batch_set($batch);
  batch_process();
}