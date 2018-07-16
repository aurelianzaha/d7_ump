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
  
  /*$get_roles = user_roles (TRUE);
  $field_info_instances = field_info_instances('user', 'user');
  $user_fields = array ();
  foreach ($field_info_instances as $field_info_instance_key => $field_info_instance_value) {
    $user_fields[$field_info_instance_key] = $field_info_instance_value["label"];
  }  
  
  $guids = variable_get("user_management_pro_rules");
  if (is_array($guids)) {
    foreach ($guids as $guid) {
      $rule = variable_get("user_management_pro_".$guid);
      
      $allow_to_create = "";
      if ($rule["allow_to_create_enable"] == 1) {
          $allow_to_create .= "<b>".$get_roles[$rule["allow_to_create_role"]]."</b> ";
          if ($rule["allow_to_create_overtake"] == 1) {
              $allow_to_create .= "and overtake field <b>".$rule["allow_to_create_overtake_field"]."</b>";
          }
      }
      $allow_to_view = "";
      if ($rule["allow_to_view_enable"] == 1) {
          $allow_to_view .= "<b>".$get_roles[$rule["allow_to_view_role"]]."</b> ";         
          $allow_to_view .= "which <b>".$rule["allow_to_view_which"]."</b>";
      }      
      $allow_to_edit = "";
      if ($rule["allow_to_edit_enable"] == 1) {
          $allow_to_edit .= "<b>".$get_roles[$rule["allow_to_edit_role"]]."</b> ";
          $allow_to_edit .= "which <b>".$rule["allow_to_edit_which"]."</b>";
          if ($rule["allow_to_edit_which"] == "if_share_common_field") {
              $allow_to_edit .= " field <b>".$rule["allow_to_edit_common_field"]."</b>";
          }
      }      
      $allow_to_delete = "";
      if ($rule["allow_to_delete_enable"] == 1) {
          $allow_to_delete .= "<b>".$get_roles[$rule["allow_to_delete_role"]]."</b> ";         
          $allow_to_delete .= "which <b>".$rule["allow_to_delete_which"]."</b>";
      }         
      
      $row = array (
        "<b>".$get_roles[$rule["select_role"]]."</b>",
        $allow_to_create,
        $allow_to_view,
        $allow_to_edit,
        $allow_to_delete,
        l ('Edit', 'admin/config/ump/rule/edit/'.$guid) . " " . l ('Delete', 'admin/config/ump/rule/delete/'.$guid),
      );
      array_push($table["rows"], $row);
    }      
  }*/
  
  $return .= theme_table($table);
  if (ump_check_permission ("create")) {
    $return .= l ('Create User', 'ump/people/create');
  }
    
  return $return;
}