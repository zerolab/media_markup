<?php

/**
 * @file media_markup/themes/media_markup.theme.inc
 */

/**
 * Template preprocessor for theme_media_markup()
 */
function template_preprocess_media_markup(&$variables) {
  $element = array(
    '#theme' => 'image',
    '#path' => drupal_get_path('module', 'media_markup') . '/thumbnail.png'
  );
  $variables['content'] = ($variables['display'] ? drupal_render($element) : '');
}
