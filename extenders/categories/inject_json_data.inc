<?php
/**
 * Categories extender: inject banner details to json record.
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

$data =& $config->globals["modules:categories.json_record"];

$data["category_banners_background"]  = "";
$data["category_banners_title"]       = "";
$data["category_banners_description"] = "";

$id_category = $_GET["id_category"];
$collection  = $settings->get("modules:category_banners.data");
if( ! empty($collection) )
{
    $collection = unserialize(base64_decode($collection));
    if( ! isset($collection[$id_category]) ) return;
    
    $item = $collection[$id_category];
    
    $data["category_banners_background"]  = $item->background;
    $data["category_banners_title"]       = $item->title;
    $data["category_banners_description"] = $item->description;
}
