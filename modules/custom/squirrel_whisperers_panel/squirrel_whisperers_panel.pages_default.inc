<?php
/**
 * @file
 * squirrel_whisperers_panel.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function squirrel_whisperers_panel_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'squirrel_whisperers_home';
  $page->task = 'page';
  $page->admin_title = 'Squirrel Whisperers Home';
  $page->admin_description = 'Home page panel layout for the Squirrel Whisperers website.';
  $page->path = 'front';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_squirrel_whisperers_home__panel';
  $handler->task = 'page';
  $handler->subtask = 'squirrel_whisperers_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Zen No Wrapper One Column',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'zen_no_wrapper';
  $display->layout_settings = array(
    'main_classes' => '',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => array(
        'list_type' => 'ul',
      ),
      'main' => NULL,
    ),
    'middle' => array(
      'style' => 'list',
    ),
    'main' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e8772d78-ed67-4f00-aa7d-b336d78e5310';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5b53e2d8-7003-41ce-9dfe-e27cd9c1bc1e';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'views-discography-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Discography',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'discography',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5b53e2d8-7003-41ce-9dfe-e27cd9c1bc1e';
    $display->content['new-5b53e2d8-7003-41ce-9dfe-e27cd9c1bc1e'] = $pane;
    $display->panels['main'][0] = 'new-5b53e2d8-7003-41ce-9dfe-e27cd9c1bc1e';
    $pane = new stdClass();
    $pane->pid = 'new-c2a5881f-ffc3-4d28-baf7-102aa3456635';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'twitter_block-twitter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Twitter',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'twitter',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c2a5881f-ffc3-4d28-baf7-102aa3456635';
    $display->content['new-c2a5881f-ffc3-4d28-baf7-102aa3456635'] = $pane;
    $display->panels['main'][1] = 'new-c2a5881f-ffc3-4d28-baf7-102aa3456635';
    $pane = new stdClass();
    $pane->pid = 'new-a218d169-0a12-4b6a-af0e-84c674f0c28c';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'youtube_block-youtube';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Music Videos',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'music-videos',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a218d169-0a12-4b6a-af0e-84c674f0c28c';
    $display->content['new-a218d169-0a12-4b6a-af0e-84c674f0c28c'] = $pane;
    $display->panels['main'][2] = 'new-a218d169-0a12-4b6a-af0e-84c674f0c28c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-5b53e2d8-7003-41ce-9dfe-e27cd9c1bc1e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['squirrel_whisperers_home'] = $page;

  return $pages;

}
