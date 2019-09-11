<?php

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_scholar_profile_admin(array $form, array &$form_state) {

  // Get vocabularies
  $vocabulary = taxonomy_get_vocabularies();
  $checklist_vocab_array = array();
  $checklist_vocab_array['--none--'] = t('--None--');
  foreach ($vocabulary as $item) {
    $checklist_vocab_array[$item->machine_name] = $item->name;
  }

  // Get solr views to use
  $views = views_get_all_views();
  $view_array = array();
  $view_array['--none--'] = t('--None--');
  foreach ($views as $view => $value) {
    // Only Add Solr Views
    if ($value->base_table == 'islandora_solr') {
      $view_array[$view] = $value->human_name;
    }
  }

  $form['islandora_scholar_profile_activity_taxonomy'] = array(
    '#type' => 'select',
    '#title' => t('Select the vocabulary that will load actives to enable autocomplete on profiles'),
    '#description' => t('Selecting --none-- will disable autocomplete on the activities field'),
    '#options' => $checklist_vocab_array ,
    '#default_value' => variable_get('islandora_scholar_profile_activity_taxonomy', 'islandora_sp_activities_vocabulary'),
  );

  $form['islandora_scholar_profile_activity_taxonomy_ref_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Reference field, to the vocabulary that will be used for auto complete activities'),
    '#description' => t('Can\'t be left empty or the field won\'t have term lookup'),
    '#default_value' => variable_get('islandora_scholar_profile_activity_taxonomy_ref_field', 'field_islandora_spa_reference'),
  );

  $form['islandora_scholar_profile_entities_linking_content_solr_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Reference field, to the the scholar profile that owns the publications that will be shown in the profile'),
    '#description' => t('has to be the unique u1 identifier that is defined in the profile and also in each object.'),
    '#default_value' => variable_get('islandora_scholar_profile_entities_linking_content_solr_field', 'mods_identifier_u1_ms'),
  );

  $form['islandora_scholar_profile_entities_scholar_title_solr_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr field: used to autocomplete u1 fields in objects, this is a field in the user profile.'),
    '#default_value' => variable_get('islandora_scholar_profile_entities_scholar_title_solr_field', 'MADS_u1_ms'),
  );

  $form['islandora_scholar_profile_entities_department_solr_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr field: used to autocomplete u2 fields in objects, this is a field in the user profile.'),
    '#default_value' => variable_get('islandora_scholar_profile_entities_department_solr_field', 'MADS_u2_ms'),
  );

  return system_settings_form($form);
}
