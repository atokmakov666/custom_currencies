<?php


/**
 * Implements hook_views_data_alter().
 */
function custom_currencies_views_data_alter(&$data) {
  $data['custom_currencies']['table']['group'] = 'Custom currencies';
  $data['custom_currencies_rates']['table']['group'] = 'Custom currencies rates';
  $data['custom_currencies_rates']['cid']['relationship'] = array(
    'label'=> t('Custom currency'),
    'base' => 'custom_currencies',
    'base field' => 'cid',
    'handler' => 'views_handler_relationship',
  );
  $data['custom_currencies_rates']['cid']['filter'] = array(
    'handler' => 'views_handler_filter_custom_currency_name',
  );
}
