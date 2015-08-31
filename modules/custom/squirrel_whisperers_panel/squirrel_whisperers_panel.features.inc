<?php
/**
 * @file
 * squirrel_whisperers_panel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function squirrel_whisperers_panel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
