<?php

/**
 * @file
 * Definition of MediaMarkupBrowser.
 */

/**
 * Media browser plugin for displaying a specific view and display.
 */
class MediaMarkupBrowser extends MediaBrowserPlugin {
  /**
   * Implements MediaBrowserPluginInterface::access().
   */
  public function access($account = NULL) {
    $access = FALSE;

    if (function_exists('file_entity_access')) {
      $access = file_entity_access('create', NULL, $account);
    }
    elseif (function_exists('media_access')) {
      $access = media_access('create', $account);
    }

    return $access;
  }

  /**
   * Implements MediaBrowserPlugin::view().
   */
  public function view() {
    $build['form'] = drupal_get_form('media_markup_add', $this->params);
    return $build;
  }

}
