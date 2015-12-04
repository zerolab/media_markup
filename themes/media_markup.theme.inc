<?php

/**
 * @file
 * Theme functions.
 *
 * vim:set sw=2 ts=2 et ft=php:
 */

/**
 * Template preprocessor for theme_media_markup().
 */
function template_preprocess_media_markup(&$variables) {
  $element = array(
    '#theme' => 'image',
    '#path' => drupal_get_path('module', 'media_markup') . '/thumbnail.png',
  );
  $variables['content'] = ($variables['display'] ? drupal_render($element) : '');
}
