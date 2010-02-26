<?php

/**
 * Settings form callback
 */
function jira_api_settings_form(){
  $form = array();

  $jira = new Jira();
  $projects = $jira->getProjectsNoSchemes();

  $rows[0] = t('Select JIRA project');

  if(count($projects)){
    foreach($projects as $project){
      $rows[$project->key] = $project->name;
    }
  }

  $form['jira-settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Jira settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['jira-settings']['jira_wsdl'] = array(
    '#type' => 'textfield',
    '#title' => t('WSDL url'),
    '#default_value' => variable_get('jira_wsdl',''),
    '#description' => t('The url to the JIRA soap service'),
    '#size' => 30,
    '#required' => TRUE,
  );

  $form['jira-project-settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Jira project settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['jira-project-settings']['jira_active_project'] = array(
    '#type' => 'select',
    '#title' => t('Select active project'),
    '#default_value' => variable_get('jira_active_project',0),
    '#options' => $rows,
    '#description' => t('Select the Jira project you would like to connect to this project.'),
  );

  $form['jira-user-settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Jira user data'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['jira-user-settings']['jira_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('jira_username',''),
    '#description' => t('JIRA username'),
    '#size' => 25,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['jira-user-settings']['jira_password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#description' => t('JIRA user password'),
    '#size' => 25,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  return system_settings_form($form);
}