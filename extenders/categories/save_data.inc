<?php
/**
 * Categories extender: save incoming category banner data
 *
 * @package    BardCanvas
 * @subpackage category_banners
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 *
 * Imported globals:
 * @var module $current_module categories
 * @var module $this_module    category_banners
 */

use hng2_base\module;

global $config, $settings;

$collection = $settings->get("modules:category_banners.data");
if( empty($collection) ) $collection = array();
else                     $collection = unserialize(base64_decode($collection));

$id_category = $_POST["id_category"];
$collection[$id_category] = (object) array(
    "background"  => trim(stripslashes($_POST["category_banners_background"])),
    "title"       => trim(stripslashes($_POST["category_banners_title"])),
    "description" => trim(stripslashes($_POST["category_banners_description"])),
);

$settings->set("modules:category_banners.data", base64_encode(serialize($collection)));
