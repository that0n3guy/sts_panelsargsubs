<?php
// $Id: panelsargsubs_capital.inc,v 1.1.2.1 2010/01/29 19:54:02 that0n3guy Exp $


/**
 * @file
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Panels arg Subs Capitalize"),
  'description' => t('A single way to put url arguments into panels content.'),
  'context' => 'sts_panelsargsubs_context_create_panelsargsubs_capital',  // func to create context
  'context name' => 'panelsargsubs_capital',
  'keyword' => 'panelsargsubs_capital',

  // Provides a list of items which are exposed as keywords.
  'convert list' => 'panelsargsubs_capital_convert_list',
  // Convert keywords into data.
  'convert' => 'panelsargsubs_capital_convert',
);

/**
 * Create a context, either from manual configuration or from an argument on the URL.
 *
 * @param $empty
 *   If true, just return an empty context.
 * @param $data
 *   If from settings form, an array as from a form. If from argument, a string.
 * @param $conf
 *   TRUE if the $data is coming from admin configuration, FALSE if it's from a URL arg.
 *
 * @return
 *   a Context object/
 */
function sts_panelsargsubs_context_create_panelsargsubs_capital($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('panelsargsubs_capital');
  $context->plugin = 'panelsargsubs_capital';

  if ($empty) {
    return $context;
  }
  $context->data = new stdClass();
  // For this simple item we'll just create our data by stripping non-alpha and
  // adding '_from_configuration_item_1' to it.
  return $context;
}


/**
 * Provide a list of sub-keywords.
 *
 * This is used to provide keywords from the context for use in a content type,
 * pane, etc.
 */
function panelsargsubs_capital_convert_list() {
  return array(
    'getargs' => t('Instead of getargs, put the name of the GET value'),
  );
}

/**
 * Convert a context into a string to be used as a keyword by content types, etc.
 */
function panelsargsubs_capital_convert($context, $type) {
  foreach($_GET as $key => $value) {
    if ($type == $key) {
      return filter_xss(ucwords($value));
    }
  }
}


