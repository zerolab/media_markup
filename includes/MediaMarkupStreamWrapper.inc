<?php

/**
 *  @file media_markup/includes/MediaMarkupStreamWrapper.inc
 *
 *  Create an HTML Snippets Stream Wrapper class for the Media/Resource module.
 */

/**
 *  Create an instance like this:
 *  $snippet = new MediaMarkupStreamWrapper('snippet://');
 */
class MediaMarkupStreamWrapper extends MediaReadOnlyStreamWrapper {
  static function getMimeType($uri, $mapping = NULL) {
    return 'snippet/html';
  }

  function getTarget($f) {
    return FALSE;
  }
}
