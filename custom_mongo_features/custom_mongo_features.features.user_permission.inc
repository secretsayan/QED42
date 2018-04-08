<?php
/**
 * @file
 * custom_mongo_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function custom_mongo_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer example_task types'.
  $permissions['administer example_task types'] = array(
    'name' => 'administer example_task types',
    'roles' => array(),
    'module' => 'example_task',
  );

  // Exported permission: 'create example_task entities'.
  $permissions['create example_task entities'] = array(
    'name' => 'create example_task entities',
    'roles' => array(),
    'module' => 'example_task',
  );

  // Exported permission: 'edit any example_task entities'.
  $permissions['edit any example_task entities'] = array(
    'name' => 'edit any example_task entities',
    'roles' => array(),
    'module' => 'example_task',
  );

  // Exported permission: 'edit own example_task entities'.
  $permissions['edit own example_task entities'] = array(
    'name' => 'edit own example_task entities',
    'roles' => array(),
    'module' => 'example_task',
  );

  // Exported permission: 'view example_task entities'.
  $permissions['view example_task entities'] = array(
    'name' => 'view example_task entities',
    'roles' => array(),
    'module' => 'example_task',
  );

  return $permissions;
}
