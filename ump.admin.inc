<?php

/**
 * Form constructor for the 'UMP create / edit rule' form of a bundle.
 *
 * @see ump_overview_form_validate()
 * @see ump_overview_form_submit()
 * @ingroup forms
 */
function ump_rule_form ($form, &$form_state, $guid = null) {
  if ($guid != null) {
    $rule = variable_get("user_management_pro_".$guid);
    $select_role = $rule["select_role"];
    $allow_to_create_enable = $rule["allow_to_create_enable"];
    $allow_to_create_role = $rule["allow_to_create_role"];
    $allow_to_create_overtake = $rule["allow_to_create_overtake"];
    $allow_to_create_overtake_field = $rule["allow_to_create_overtake_field"];
    $allow_to_view_enable = $rule["allow_to_view_enable"];
    $allow_to_view_role = $rule["allow_to_view_role"];
    $allow_to_view_which = $rule["allow_to_view_which"];
    $allow_to_edit_enable = $rule["allow_to_edit_enable"];
    $allow_to_edit_role = $rule["allow_to_edit_role"];
    $allow_to_edit_which = $rule["allow_to_edit_which"];
    $allow_to_edit_common_field = $rule["allow_to_edit_common_field"];
    $allow_to_delete_enable = $rule["allow_to_delete_enable"];
    $allow_to_delete_role = $rule["allow_to_delete_role"];
    $allow_to_delete_which = $rule["allow_to_delete_which"]; 
  }
  else {
    $select_role = null;
    $allow_to_create_enable = null;
    $allow_to_create_role = null;
    $allow_to_create_overtake = null;
    $allow_to_create_overtake_field = null;
    $allow_to_view_enable = null;
    $allow_to_view_role = null;
    $allow_to_view_which = null;
    $allow_to_edit_enable = null;
    $allow_to_edit_role = null;
    $allow_to_edit_which = null;
    $allow_to_edit_common_field = null;
    $allow_to_delete_enable = null;
    $allow_to_delete_role = null;
    $allow_to_delete_which = null;
  }
  
  
  $field_info_instances = field_info_instances('user', 'user');
  $user_fields = array ();
  foreach ($field_info_instances as $field_info_instance_key => $field_info_instance_value) {
    $user_fields[$field_info_instance_key] = $field_info_instance_value["label"];
  }
  
  $get_roles = user_roles (TRUE);
  
  $form['select_role'] = array(
    '#type' => 'select',
    '#title' => t('Select role'),
    '#options' => $get_roles,
    '#default_value' => $select_role,
  );
  
  $form['allow_to_create'] = array(
    '#type' => 'fieldset',
    '#title' => t('Allow to create'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,  
  );

  $form['allow_to_create']['allow_to_create_enable'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Enable'),
    '#default_value' => $allow_to_create_enable,
  );  
  
  $form['allow_to_create']['allow_to_create_role'] = array(
    '#type' => 'select',
    '#title' => t('Select role'),
    '#options' => $get_roles,
    '#default_value' => $allow_to_create_role,
    '#states' => array(
      'disabled' => array(
        ':input[name="allow_to_create_enable"]' => array('checked' => FALSE),
      ),
    ), 
  );

  $form['allow_to_create']['allow_to_create_overtake'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Overtake commond field'),
    '#default_value' => $allow_to_create_overtake,
    '#states' => array(
      'disabled' => array(
        ':input[name="allow_to_create_enable"]' => array('checked' => FALSE),
      ),
    ),     
  );  
  
  $form['allow_to_create']['allow_to_create_overtake_field'] = array(
    '#type' => 'select',
    '#title' => t('Select field'),
    '#options' => $user_fields,
    '#default_value' => $allow_to_create_overtake_field,
    '#states' => array(
      'visible' => array(
        ':input[name="allow_to_create_overtake"]' => array('checked' => true),
      ),
      'disabled' => array(
        ':input[name="allow_to_create_enable"]' => array('checked' => FALSE),
      ),      
    ),
  );  
  
  $form['allow_to_view'] = array(
    '#type' => 'fieldset',
    '#title' => t('Allow to view'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,  
  );

  $form['allow_to_view']['allow_to_view_enable'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Enable'),
    '#default_value' => $allow_to_view_enable,
  );  
  
  $form['allow_to_view']['allow_to_view_role'] = array(
    '#type' => 'select',
    '#title' => t('Select role'),
    '#options' => $get_roles,
    '#default_value' => $allow_to_view_role,
    '#states' => array(
      'disabled' => array(
        ':input[name="allow_to_view_enable"]' => array('checked' => FALSE),
      ),
    ),         
  );
  
  $form['allow_to_view']['allow_to_view_which'] = array(
    '#type' => 'select',
    '#title' => t('Select field'),
    '#options' => array (
      'all' => 'All of them',
      'created_by_user' => 'Created by the user',
    ),
    '#default_value' => $allow_to_view_which,
    '#states' => array(
      'disabled' => array(
        ':input[name="allow_to_view_enable"]' => array('checked' => FALSE),
      ),
    ),       
  );    
  
  $form['allow_to_edit'] = array(
    '#type' => 'fieldset',
    '#title' => t('Allow to edit'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,  
  );

  $form['allow_to_edit']['allow_to_edit_enable'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Enable'),
    '#default_value' => $allow_to_edit_enable,
  );  
  
  $form['allow_to_edit']['allow_to_edit_role'] = array(
    '#type' => 'select',
    '#title' => t('Select role'),
    '#options' => $get_roles,
    '#default_value' => $allow_to_edit_role,
    '#states' => array(
      'disabled' => array(
        ':input[name="allow_to_edit_enable"]' => array('checked' => FALSE),
      ),
    ), 
  );

  $form['allow_to_edit']['allow_to_edit_which'] = array(
    '#type' => 'select',
    '#title' => t('Select field'),
    '#options' => array (
      'all' => 'All of them',
      'if_share_common_field' => 'If share common field',
    ),
    '#default_value' => $allow_to_edit_which,
    '#states' => array(
      'disabled' => array(
        ':input[name="allow_to_edit_enable"]' => array('checked' => FALSE),
      ),
    ),       
  );      
  
  $form['allow_to_edit']['allow_to_edit_common_field'] = array(
    '#type' => 'select',
    '#title' => t('Select field'),
    '#options' => $user_fields,
    '#default_value' => $allow_to_edit_common_field,
    '#states' => array(
      'visible' => array(
        ':input[name="allow_to_edit_which"]' => array('value' => 'if_share_common_field'),
      ),
      'disabled' => array(
        ':input[name="allow_to_edit_enable"]' => array('checked' => FALSE),
      ),      
    ),
  );    
  
  $form['allow_to_delete'] = array(
    '#type' => 'fieldset',
    '#title' => t('Allow to delete'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,  
  );

  $form['allow_to_delete']['allow_to_delete_enable'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Enable'),
    '#default_value' => $allow_to_delete_enable,
  );  
  
  $form['allow_to_delete']['allow_to_delete_role'] = array(
    '#type' => 'select',
    '#title' => t('Select role'),
    '#options' => $get_roles,
    '#default_value' => $allow_to_delete_role,
    '#states' => array(
      'disabled' => array(
        ':input[name="allow_to_delete_enable"]' => array('checked' => FALSE),
      ),
    ),         
  );
  
  $form['allow_to_delete']['allow_to_delete_which'] = array(
    '#type' => 'select',
    '#title' => t('Select field'),
    '#options' => array (
      'all' => 'All of them',
      'created_by_user' => 'Created by the user',
    ),
    '#default_value' => $allow_to_delete_which,
    '#states' => array(
      'disabled' => array(
        ':input[name="allow_to_delete_enable"]' => array('checked' => FALSE),
      ),
    ),       
  );      
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );  
  
  return $form;
}

/**
 * Form validation handler for ump_overview_form().
 *
 * @see ump_overview_form_submit()
 */
function ump_rule_form_validate($form, &$form_state) {

}

/**
 * Form submission handler for ump_overview_form().
 *
 * @see ump_overview_form_validate()
 */
function ump_rule_form_submit($form, &$form_state) {
  $rule = array (
    "select_role" => $form_state["values"]["select_role"],
    "allow_to_create_enable" => $form_state["values"]["allow_to_create_enable"],
    "allow_to_create_role" => $form_state["values"]["allow_to_create_role"],
    "allow_to_create_overtake" => $form_state["values"]["allow_to_create_overtake"],
    "allow_to_create_overtake_field" => $form_state["values"]["allow_to_create_overtake_field"],
    "allow_to_view_enable" => $form_state["values"]["allow_to_view_enable"],
    "allow_to_view_role" => $form_state["values"]["allow_to_view_role"],
    "allow_to_view_which" => $form_state["values"]["allow_to_view_which"],
    "allow_to_edit_enable" => $form_state["values"]["allow_to_edit_enable"],
    "allow_to_edit_role" => $form_state["values"]["allow_to_edit_role"],
    "allow_to_edit_which" => $form_state["values"]["allow_to_edit_which"],
    "allow_to_edit_common_field" => $form_state["values"]["allow_to_edit_common_field"],
    "allow_to_delete_enable" => $form_state["values"]["allow_to_delete_enable"],
    "allow_to_delete_role" => $form_state["values"]["allow_to_delete_role"],
    "allow_to_delete_which" => $form_state["values"]["allow_to_delete_which"],
  );
  
  $guid = uniqid ();
  variable_set("user_management_pro_".$guid, $rule);
  $rules = variable_get("user_management_pro_rules", array());
  array_push($rules, $guid);
  variable_set("user_management_pro_rules", $rules);
  $form_state['redirect'] = "admin/config/ump/overview";
  
}

/**
 * Form constructor for the 'UMP delete rule' form of a bundle.
 *
 * @see ump_rule_delete_form_validate()
 * @see ump_rule_delete_form_submit()
 * @ingroup forms
 */
function ump_rule_delete_form ($form, &$form_state, $guid = null) {
  if ($guid != null) {
    $form_state['storage']['guid'] = $guid;
  }
  else {
    return;
  }
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#storage' => 'delete',
    '#value' => t('Delete'),
  );  
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#storage' => 'cancel',
    '#value' => t('Cancel'),
  );

  return $form;
}

/**
 * Form validation handler for ump_rule_delete_form().
 *
 * @see ump_rule_delete_form_submit()
 */
function ump_rule_delete_form_validate($form, &$form_state) {

}

/**
 * Form submission handler for ump_rule_delete_form().
 *
 * @see ump_rule_delete_form_validate()
 */
function ump_rule_delete_form_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#storage'] == "delete") {
    $guid = $form_state['storage']['guid'];
    variable_del("user_management_pro_".$guid);
    $rules = variable_get("user_management_pro_rules", array());
    if (($key = array_search($guid, $rules)) !== false) {
      unset($rules[$key]);
    }
    variable_set("user_management_pro_rules", $rules);    
  }
  $form_state['redirect'] = "admin/config/ump/overview";
}


function ump_rules_overview () {
  $return = "";
  
  $table["header"] = array (
    "Role",
    "Allow to create",
    "Allow to view",
    "Allow to edit",
    "Allow to delete",
    "Operations",
  );
  $table["rows"] = array ();
  $table["attributes"] = array ();
  $table["caption"] = "";
  $table["colgroups"] = array ();
  $table["sticky"] = true;
  $table["empty"] = "No rules created yet.";
  
  $guids = variable_get("user_management_pro_rules");
  foreach ($guids as $guid) {
    $rule = variable_get("user_management_pro_".$guid);
    $row = array (
      $rule["select_role"],
      $rule["allow_to_create_enable"],
      $rule["allow_to_view_enable"],
      $rule["allow_to_edit_enable"],
      $rule["allow_to_delete_enable"],
      l ('Edit', 'admin/config/ump/rule/edit/'.$guid) . " " . l ('Delete', 'admin/config/ump/rule/delete/'.$guid),
    );
    array_push($table["rows"], $row);
  }
  
  $return .= theme_table($table);
  $return .= l ('Create Rule', 'admin/config/ump/rule/create');
    
  return $return;
}