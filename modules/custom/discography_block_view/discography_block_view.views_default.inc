<?php
/**
 * @file
 * discography_block_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function discography_block_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'discography';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Discography';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Discography';
  $handler->display->display_options['css_class'] = 'section-wrapper';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'discography-songs';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results found.';
  /* Field: Track Name (hidden) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Track Name (hidden)';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Track iTunes Links (hidden) */
  $handler->display->display_options['fields']['field_track_buy_it_now']['id'] = 'field_track_buy_it_now';
  $handler->display->display_options['fields']['field_track_buy_it_now']['table'] = 'field_data_field_track_buy_it_now';
  $handler->display->display_options['fields']['field_track_buy_it_now']['field'] = 'field_track_buy_it_now';
  $handler->display->display_options['fields']['field_track_buy_it_now']['ui_name'] = 'Track iTunes Links (hidden)';
  $handler->display->display_options['fields']['field_track_buy_it_now']['label'] = '';
  $handler->display->display_options['fields']['field_track_buy_it_now']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_track_buy_it_now']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_track_buy_it_now']['type'] = 'text_plain';
  /* Field: Track Number (hidden) */
  $handler->display->display_options['fields']['field_track_number']['id'] = 'field_track_number';
  $handler->display->display_options['fields']['field_track_number']['table'] = 'field_data_field_track_number';
  $handler->display->display_options['fields']['field_track_number']['field'] = 'field_track_number';
  $handler->display->display_options['fields']['field_track_number']['ui_name'] = 'Track Number (hidden)';
  $handler->display->display_options['fields']['field_track_number']['label'] = '';
  $handler->display->display_options['fields']['field_track_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_track_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_track_number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_track_number']['type'] = 'text_plain';
  /* Field: Track Preview (hidden) */
  $handler->display->display_options['fields']['field_track_preview']['id'] = 'field_track_preview';
  $handler->display->display_options['fields']['field_track_preview']['table'] = 'field_data_field_track_preview';
  $handler->display->display_options['fields']['field_track_preview']['field'] = 'field_track_preview';
  $handler->display->display_options['fields']['field_track_preview']['ui_name'] = 'Track Preview (hidden)';
  $handler->display->display_options['fields']['field_track_preview']['label'] = '';
  $handler->display->display_options['fields']['field_track_preview']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_track_preview']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_track_preview']['type'] = 'text_plain';
  /* Field: Album (hidden) */
  $handler->display->display_options['fields']['field_album']['id'] = 'field_album';
  $handler->display->display_options['fields']['field_album']['table'] = 'field_data_field_album';
  $handler->display->display_options['fields']['field_album']['field'] = 'field_album';
  $handler->display->display_options['fields']['field_album']['ui_name'] = 'Album (hidden)';
  $handler->display->display_options['fields']['field_album']['label'] = '';
  $handler->display->display_options['fields']['field_album']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_album']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_album']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Album Cover Image (hidden) */
  $handler->display->display_options['fields']['field_album_cover_image']['id'] = 'field_album_cover_image';
  $handler->display->display_options['fields']['field_album_cover_image']['table'] = 'field_data_field_album_cover_image';
  $handler->display->display_options['fields']['field_album_cover_image']['field'] = 'field_album_cover_image';
  $handler->display->display_options['fields']['field_album_cover_image']['ui_name'] = 'Album Cover Image (hidden)';
  $handler->display->display_options['fields']['field_album_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_album_cover_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_album_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_album_cover_image']['type'] = 'text_plain';
  /* Field: Element (shown) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Element (shown)';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a data-buy-it-now="[field_track_buy_it_now]" data-track="[title]" data-track-number="[field_track_number]" data-track-preview="[field_track_preview]" data-album="[field_album]" data-album-cover="[field_album_cover_image]" data-action="showModal"><figure>					
<img width="100" height="100" src="[field_album_cover_image]" alt="[title]"><figcaption>[title]</figcaption></figure></a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Album (field_album) */
  $handler->display->display_options['sorts']['field_album_tid']['id'] = 'field_album_tid';
  $handler->display->display_options['sorts']['field_album_tid']['table'] = 'field_data_field_album';
  $handler->display->display_options['sorts']['field_album_tid']['field'] = 'field_album_tid';
  /* Sort criterion: Content: Track Number (field_track_number) */
  $handler->display->display_options['sorts']['field_track_number_value']['id'] = 'field_track_number_value';
  $handler->display->display_options['sorts']['field_track_number_value']['table'] = 'field_data_field_track_number';
  $handler->display->display_options['sorts']['field_track_number_value']['field'] = 'field_track_number_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Filter by album';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'albums';

  /* Display: Discography Block */
  $handler = $view->new_display('block', 'Discography Block', 'block');
  $handler->display->display_options['block_description'] = 'Discography Block';
  $export['discography'] = $view;

  return $export;
}
