<?php

/**
 * Form constructor for the 'UMP config' form of a bundle.
 *
 * @see ump_overview_form_validate()
 * @see ump_overview_form_submit()
 * @ingroup forms
 */
function ump_overview_form($form, &$form_state) {
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
  );
  
  $form['allow_to_create'] = array(
    '#type' => 'fieldset',
    '#title' => t('Allow to create'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,  
  );

  $form['allow_to_create']['allow_to_create_role'] = array(
    '#type' => 'select',
    '#title' => t('Select role'),
    '#options' => $get_roles,
  );

  $form['allow_to_create']['allow_to_create_overtake'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Overtake commond field'),
  );  
  
  $form['allow_to_create']['allow_to_create_overtake_field'] = array(
    '#type' => 'select',
    '#title' => t('Select field'),
    '#options' => $user_fields,
    '#states' => array(
      'visible' => array(
        ':input[name="allow_to_create_overtake"]' => array('checked' => true),
      ),
    ),
  );  
  
  $form['allow_to_view'] = array(
    '#type' => 'fieldset',
    '#title' => t('Allow to view'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,  
  );

  $form['allow_to_view']['allow_to_view_role'] = array(
    '#type' => 'select',
    '#title' => t('Select role'),
    '#options' => $get_roles,
  );
  
  $form['allow_to_view']['allow_to_view_which'] = array(
    '#type' => 'select',
    '#title' => t('Select field'),
    '#options' => array (
      'all' => 'All of them',
      'created_by_user' => 'Created by the user',
    ),
  );    
  
  
  return $form;
}

/**
 * Form validation handler for ump_overview_form().
 *
 * @see ump_overview_form_submit()
 */
function ump_overview_form_validate($form, &$form_state) {

}

/**
 * Form submission handler for ump_overview_form().
 *
 * @see ump_overview_form_validate()
 */
function ump_overview_form_submit($form, &$form_state) {

}