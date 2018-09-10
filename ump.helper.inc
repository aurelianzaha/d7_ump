<?php

/**
 * @file
 * Helper functions for UMP module.
 */

/**
 * Helper function to get the UMP rules defined.
 */
function ump_get_user_rules() {
  global $user;
  $rules = array();
  $guids = variable_get("user_management_pro_rules");
  if (is_array($guids)) {
    foreach ($guids as $guid) {
      $rule = variable_get("user_management_pro_" . $guid);
      if (isset($user->roles[$rule["select_role"]])) {
        array_push($rules, $rule);
      }
    }
  }
  return $rules;
}

/**
 * Helper function to return array of defined UMP permissions.
 */
function ump_get_permissions() {
  $permission_array = array();
  $guids = variable_get("user_management_pro_rules");
  foreach ($guids as $guid) {
    $rule = variable_get("user_management_pro_" . $guid);

    if ($rule["allow_to_create_enable"] == 1) {
      $permission_array[$rule["select_role"]]["create"][$rule["allow_to_create_role"]] = 1;
      if ($rule["allow_to_create_overtake"] == 1) {
        $permission_array[$rule["select_role"]]["create"][$rule["allow_to_create_role"]] = array("overtake" => $rule["allow_to_create_overtake_field"]);
      }
    }
    if ($rule["allow_to_view_enable"] == 1) {
      $permission_array[$rule["select_role"]]["view"][$rule["allow_to_view_role"]]["which"] = $rule["allow_to_view_which"];
    }
    if ($rule["allow_to_edit_enable"] == 1) {
      $permission_array[$rule["select_role"]]["edit"][$rule["allow_to_edit_role"]]["which"] = $rule["allow_to_edit_which"];
      if ($rule["allow_to_edit_which"] == "if_share_common_field") {
        $permission_array[$rule["select_role"]]["edit"][$rule["allow_to_edit_role"]]["common_field"] = $rule["allow_to_edit_common_field"];
      }
    }
    if ($rule["allow_to_delete_enable"] == 1) {
      $permission_array[$rule["select_role"]]["delete"][$rule["allow_to_delete_role"]]["which"] = $rule["allow_to_delete_which"];
    }
  }

  return $permission_array;
}

/**
 * Helper function to return creator UID.
 */
function ump_user_created_by_get_uid($uid) {
  $query = db_select('user_created_by_data', 'ucbd')->fields('ucbd', array('creator_uid'))->condition('uid', $uid);
  $creator_uid = $query->execute()->fetchField();
  return $creator_uid;
}
