<?php

/**
 * Implements hook_views_default_views().
 */
function custom_currencies_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'currencies_rates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'custom_currencies_rates';
  $view->human_name = 'Currencies rates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Currencies rates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'date' => 'date',
    'rate' => 'rate',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rate' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Custom currencies rates: Currency ID */
  $handler->display->display_options['relationships']['cid']['id'] = 'cid';
  $handler->display->display_options['relationships']['cid']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  /* Field: Custom currencies: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'custom_currencies';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'cid';
  /* Field: Custom currencies rates: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'long';
  /* Field: Custom currencies rates: Rate */
  $handler->display->display_options['fields']['rate']['id'] = 'rate';
  $handler->display->display_options['fields']['rate']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['fields']['rate']['field'] = 'rate';
  $handler->display->display_options['fields']['rate']['precision'] = '0';
  /* Sort criterion: Custom currencies rates: Date */
  $handler->display->display_options['sorts']['date']['id'] = 'date';
  $handler->display->display_options['sorts']['date']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['sorts']['date']['field'] = 'date';
  $handler->display->display_options['sorts']['date']['order'] = 'DESC';
  $handler->display->display_options['sorts']['date']['granularity'] = 'day';
  /* Sort criterion: Custom currencies: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'custom_currencies';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'cid';
  /* Filter criterion: Custom currencies rates: Currency ID */
  $handler->display->display_options['filters']['cid']['id'] = 'cid';
  $handler->display->display_options['filters']['cid']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['filters']['cid']['field'] = 'cid';
  $handler->display->display_options['filters']['cid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['operator_id'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['label'] = 'Currency';
  $handler->display->display_options['filters']['cid']['expose']['operator'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['identifier'] = 'cid';
  $handler->display->display_options['filters']['cid']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Custom currencies rates: Date */
  $handler->display->display_options['filters']['date']['id'] = 'date';
  $handler->display->display_options['filters']['date']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['filters']['date']['field'] = 'date';
  $handler->display->display_options['filters']['date']['operator'] = 'between';
  $handler->display->display_options['filters']['date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date']['expose']['operator_id'] = 'date_op';
  $handler->display->display_options['filters']['date']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date']['expose']['operator'] = 'date_op';
  $handler->display->display_options['filters']['date']['expose']['identifier'] = 'date';
  $handler->display->display_options['filters']['date']['expose']['remember_roles'] = array(
    2 => '2',
  );

  /* Display: Table view */
  $handler = $view->new_display('page', 'Table view', 'page_table');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="/currencies-rates/chart">View chart</a>';
  $handler->display->display_options['path'] = 'currencies-rates';
  $handler->display->display_options['menu']['title'] = 'Currencies rates';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Table';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_table');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_json';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'custom_currencies.json';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom currencies: Code */
  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'custom_currencies';
  $handler->display->display_options['fields']['code']['field'] = 'code';
  $handler->display->display_options['fields']['code']['relationship'] = 'cid';
  $handler->display->display_options['fields']['code']['label'] = 'code';
  $handler->display->display_options['fields']['code']['element_label_colon'] = FALSE;
  /* Field: Custom currencies: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'custom_currencies';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'cid';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Custom currencies rates: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'date';
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'long';
  /* Field: Custom currencies rates: Rate */
  $handler->display->display_options['fields']['rate']['id'] = 'rate';
  $handler->display->display_options['fields']['rate']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['fields']['rate']['field'] = 'rate';
  $handler->display->display_options['fields']['rate']['label'] = 'rate';
  $handler->display->display_options['fields']['rate']['precision'] = '0';
  $handler->display->display_options['fields']['rate']['separator'] = '';
  $handler->display->display_options['path'] = 'currencies-rates.json';
  $handler->display->display_options['displays'] = array(
    'page_table' => 'page_table',
    'default' => 0,
    'page_chart' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'currencies-rates';
  $handler->display->display_options['segment_size'] = '25';

  /* Display: Chart */
  $handler = $view->new_display('page', 'Chart', 'page_chart');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'google_chart_tools_views';
  $handler->display->display_options['style_options']['width'] = '600';
  $handler->display->display_options['style_options']['height'] = '400';
  $handler->display->display_options['style_options']['isstacked'] = 0;
  $handler->display->display_options['style_options']['pointsize'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="/currencies-rates">View table</a>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom currencies rates: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'long';
  /* Field: Custom currencies rates: Rate */
  $handler->display->display_options['fields']['rate']['id'] = 'rate';
  $handler->display->display_options['fields']['rate']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['fields']['rate']['field'] = 'rate';
  $handler->display->display_options['fields']['rate']['precision'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Custom currencies rates: Currency ID */
  $handler->display->display_options['filters']['cid']['id'] = 'cid';
  $handler->display->display_options['filters']['cid']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['filters']['cid']['field'] = 'cid';
  $handler->display->display_options['filters']['cid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['cid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['operator_id'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['label'] = 'Currency';
  $handler->display->display_options['filters']['cid']['expose']['operator'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['identifier'] = 'cid';
  $handler->display->display_options['filters']['cid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Custom currencies rates: Date */
  $handler->display->display_options['filters']['date']['id'] = 'date';
  $handler->display->display_options['filters']['date']['table'] = 'custom_currencies_rates';
  $handler->display->display_options['filters']['date']['field'] = 'date';
  $handler->display->display_options['filters']['date']['operator'] = 'between';
  $handler->display->display_options['filters']['date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date']['expose']['operator_id'] = 'date_op';
  $handler->display->display_options['filters']['date']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date']['expose']['operator'] = 'date_op';
  $handler->display->display_options['filters']['date']['expose']['identifier'] = 'date';
  $handler->display->display_options['filters']['date']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['path'] = 'currencies-rates/chart';
  $handler->display->display_options['menu']['title'] = 'Currencies rates';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  $views[$view->name] = $view;
  return $views;
}

