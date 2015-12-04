<?php

/**
 * @file
 * Extends MediaReadOnlyStreamWrapper.
 *
 * Allows handling HTML Snippets.
 */

/**
 * Media Markup class.
 *
 * @code
 * // New snippet instance.
 * $snippet = new MediaMarkupStreamWrapper('snippet://');.
 * @endcode
 */
class MediaMarkupStreamWrapper extends MediaReadOnlyStreamWrapper {
  public static function getMimeType($uri, $mapping = NULL) {
    return 'snippet/html';
  }

  public function getTarget($f) {
    return FALSE;
  }

}
