<?php
/**
 * @file
 * squirrel_whisperers_songs_feed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function squirrel_whisperers_songs_feed_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
