<?php

/**
 * @file
 * Extends MediaReadOnlyStreamWrapper.
 *
 * Allows handling HTML Snippets.
 *
 * vim:set sw=2 ts=2 et ft=php:
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
