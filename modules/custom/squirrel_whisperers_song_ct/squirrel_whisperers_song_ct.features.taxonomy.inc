<?php
/**
 * @file
 * squirrel_whisperers_song_ct.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function squirrel_whisperers_song_ct_taxonomy_default_vocabularies() {
  return array(
    'albums' => array(
      'name' => 'Albums',
      'machine_name' => 'albums',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
