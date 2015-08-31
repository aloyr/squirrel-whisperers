<?php
/**
 * @file
 * squirrel_whisperers_songs_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function squirrel_whisperers_songs_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'songs';
  $feeds_importer->config = array(
    'name' => 'Songs',
    'description' => 'Import songs from itunes',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExJsonPath',
      'config' => array(
        'sources' => array(
          'title' => array(
            'name' => 'Track',
            'value' => 'trackCensoredName',
            'debug' => 0,
            'weight' => '1',
          ),
          'tracknumber' => array(
            'name' => 'TrackNumber',
            'value' => 'trackNumber',
            'debug' => 0,
            'weight' => '2',
          ),
          'trackurl' => array(
            'name' => 'TrackURL',
            'value' => 'trackViewUrl',
            'debug' => 0,
            'weight' => '3',
          ),
          'trackpreview' => array(
            'name' => 'TrackPreview',
            'value' => 'previewUrl',
            'debug' => 0,
            'weight' => '4',
          ),
          'artist' => array(
            'name' => 'Artist',
            'value' => 'artistName',
            'debug' => 0,
            'weight' => '5',
          ),
          'album' => array(
            'name' => 'Album',
            'value' => 'collectionName',
            'debug' => 0,
            'weight' => '6',
          ),
          'albumartwork' => array(
            'name' => 'AlbumArtwork',
            'value' => 'artworkUrl100',
            'debug' => 0,
            'weight' => '7',
          ),
        ),
        'context' => array(
          'value' => '$.results.*',
        ),
        'display_errors' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'debug_mode' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'album',
            'target' => 'field_album',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          2 => array(
            'source' => 'tracknumber',
            'target' => 'field_track_number',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'trackurl',
            'target' => 'field_track_buy_it_now',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'trackpreview',
            'target' => 'field_track_preview',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'artist',
            'target' => 'field_artist',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'albumartwork',
            'target' => 'field_album_cover_image',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'song',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['songs'] = $feeds_importer;

  return $export;
}
