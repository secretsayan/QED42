<?php
/**
 * @file
 * custom_mongo_features.features.inc
 */

/**
 * Implements hook_default_example_task_type().
 */
function custom_mongo_features_default_example_task_type() {
  $items = array();
  $items['mongo_cities'] = entity_import('example_task_type', '{
    "type" : "mongo_cities",
    "label" : "Mongo Cities",
    "weight" : 0,
    "description" : ""
  }');
  return $items;
}
