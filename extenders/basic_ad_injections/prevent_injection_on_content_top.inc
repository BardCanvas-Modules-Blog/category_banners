<?php
/**
 * Basic ad injections extender: prevent content injection at the content_top point
 *
 * @package    BardCanvas
 * @subpackage category_banners
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 */

global $config, $template;

if( $template->get("page_tag") != "post_category_index" ) return;

$config->globals["modules:basic_ad_injections.content_top/prevent_rendering"] = true;
return;
