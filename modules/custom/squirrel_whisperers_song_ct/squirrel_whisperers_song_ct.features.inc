<?php
/**
 * @file
 * squirrel_whisperers_song_ct.features.inc
 */

/**
 * Implements hook_node_info().
 */
function squirrel_whisperers_song_ct_node_info() {
  $items = array(
    'song' => array(
      'name' => t('Song'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Track (song)'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
