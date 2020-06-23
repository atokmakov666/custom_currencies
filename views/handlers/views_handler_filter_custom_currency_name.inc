<?php

/**
 * @file
 * Definition of views_handler_filter_node_type.
 */

/**
 * Filter by node type.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_custom_currency_name extends views_handler_filter_in_operator {

  /**
   * {@inheritdoc}
   */
  public function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Custom currency');
      //TODO: fix it - https://www.drupal.org/project/entity/issues/1823926
      $currencies = entity_load('custom_currencies', FALSE, array(), TRUE);
      $options = array();
      foreach ($currencies as $currency) {
        $options[$currency->cid] = $currency->name;
      }
      asort($options);
      $this->value_options = $options;
    }
  }

}
