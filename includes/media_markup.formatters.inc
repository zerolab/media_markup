<?php

/**
 * @file
 * Formatters for Media: HTML Snippets.
 *
 * vim:set sw=2 ts=2 et ft=php:
 */

/**
 * Implements hook_file_formatter_info().
 */
function media_markup_file_formatter_info() {
  $formatters = array();

  $formatters['media_markup'] = array(
    'label' => t('Markup Snippet'),
    'file types' => array('snippet'),
    'default_settings' => array(),
    'view callback' => 'media_markup_file_formatter_markup_view',
    'settings callback' => 'media_markup_file_formatter_markup_settings',
  );

  return $formatters;
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_markup_file_formatter_markup_settings($form, &$form_state, $settings) {
  $element = array();

  $element['thumbnail'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Show placeholder thumbnail'),
    '#default_value' => !empty($settings['thumbnail']) ? $settings['thumbnail'] : 0,
    '#description' => t('Markup Snippets piggyback on fielded file entities to display custom content. Media Browser expects images, so enable this for certain modes to show a generic thumbnail (e.g. Preview)'),
  );

  return $element;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_markup_file_formatter_markup_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);

  if ($scheme == 'snippet' && empty($file->override['wysiwyg'])) {
    $element = array(
      '#theme' => 'media_markup',
      '#file' => $file,
      '#display' => isset($display['settings']['thumbnail']) ? $display['settings']['thumbnail'] : 0,
    );

    $display['settings']['attributes'] = array();

    return $element;
  }
}

/**
 * Implements hook_file_default_displays_alter().
 */
function media_markup_file_default_displays_alter(&$file_displays) {
  $default_styles = array(
    'default' => array(),
    'teaser'  => array(),
    'preview' => array('thumbnail' => 1),
  );

  foreach ($default_styles as $view_mode => $settings) {
    $display_name = "snippet__{$view_mode}__media_markup";
    $file_displays[$display_name] = (object) array(
      'api_version' => 1,
      'name' => $display_name,
      'status' => 1,
      'weight' => 0,
      'settings' => $settings,
    );
  }
}
