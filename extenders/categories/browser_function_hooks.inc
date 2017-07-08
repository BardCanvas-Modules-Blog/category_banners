<?php
/**
 * Categories extender: browser function hooks
 *
 * @package    BardCanvas
 * @subpackage category_banners
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 * 
 * Imported globals:
 * @var array $per_column_function_hooks 2-dimensional: field keys, called function names
 */

use hng2_modules\categories\category_record;

global $per_column_function_hooks;

$per_column_function_hooks["description"][] = "render_category_banner_info_for_category_record";

/**
 * @param category_record $record
 */
function render_category_banner_info_for_category_record($record)
{
    global $modules, $config, $settings;
    
    $collection = $config->globals["modules:category_banners.data_collection"];
    if( empty($collection) )
    {
        $raw_collection = $settings->get("modules:category_banners.data");
        if( empty($raw_collection) ) return;
        
        $collection = unserialize(base64_decode($raw_collection));
        $config->globals["modules:category_banners.data_collection"] = $collection;
    }
    
    /** @var object $item {background:string, title:string, description:string} */
    $item = $collection[$record->id_category];
    if( empty($item) ) return;
    
    $this_module = $modules["category_banners"];
    
    $links = array();
    
    if( ! empty($item->background) )
        $links[] = "
            <span class='framed_content inlined'>
                <a class='prettyPhoto' href='{$config->full_root_path}{$item->background}'
                   ><i class='fa fa-picture-o'></i>
                   {$this_module->language->categories_browser->background}</a>
            </span>
        ";
    
    if( ! empty($item->title) )
        $links[] = "
            <span class='framed_content inlined'>
                <i class='fa fa-plus-circle'></i>
                {$this_module->language->categories_browser->title}
            </span>
        ";
    
    if( ! empty($item->description) )
        $links[] = "
            <span class='framed_content inlined'>
                <i class='fa fa-plus-circle'></i>
                {$this_module->language->categories_browser->description}
            </span>
        ";
    
    if( empty($links) ) return;
    
    echo "<hr>";
    echo "
        <span class='framed_content state_highlight inlined'>
            <i class='fa fa-flag'></i>
            {$this_module->language->categories_browser->has_banner}
        </span>
    ";
    echo implode("\n", $links);
}
