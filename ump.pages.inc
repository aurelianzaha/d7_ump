<?php

function ump_user_page () {
  $return = "";
  
  $table["header"] = array (
    "Name",
    "Roles",
    "Operations",
  );
  $table["rows"] = array ();
  $table["attributes"] = array ();
  $table["caption"] = "";
  $table["colgroups"] = array ();
  $table["sticky"] = true;
  $table["empty"] = "No users found";
  
  $guids = variable_get("user_management_pro_rules");
  $ump_permissions = ump_get_permissions ();
  //var_dump ($ump_permissions);
  foreach ($guids as $guid) {
    $rule = variable_get("user_management_pro_".$guid);
    if ($rule["allow_to_view_enable"] == 1) {
      $query = 'SELECT ur.uid
        FROM {users_roles} AS ur
        WHERE ur.rid = :rid';
      $result = db_query($query, array(':rid' => $rule["allow_to_view_role"]));
      $uids = $result->fetchCol();
      $users = user_load_multiple($uids);    
      foreach ($users as $load_user) {

        if (drupal_valid_path('user/'.$load_user->uid)) {
            $roles = "";
            $edit = "";
            $delete = "";
            if (drupal_valid_path('user/'.$load_user->uid.'/edit')) {
                $edit = l ('Edit', 'user/'.$load_user->uid.'/edit');
            }
            if (drupal_valid_path('user/'.$load_user->uid.'/delete')) {
                $delete = l ('Delete', 'user/'.$load_user->uid.'/delete');
            }

            foreach ($load_user->roles as $load_user_key => $load_user_value) {
              $roles .= $load_user_value."<br>";
            }

            $row = array (
              $load_user->name,
              $roles,
              $edit . " " . $delete,
            );
            array_push($table["rows"], $row);            
        }
      }      
    }     
  }
  
  $return .= theme_table($table);
  if (ump_check_permission ("create")) {
    $return .= l ('Create User', 'admin/people/create');
  }
    
  return $return;
}

if (!function_exists('user_created_by_get_uid')) {
  function user_created_by_get_uid($uid) {
    $query = db_select('user_created_by_data', 'ucbd')->fields('ucbd', array('creator_uid'))->condition('uid', $uid);
    $creator_uid = $query->execute()->fetchField();
    return $creator_uid;
  }
}