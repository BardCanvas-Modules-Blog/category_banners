<?php
/**
 * Posts extender: banner rendering in the category index.
 *
 * @package    BardCanvas
 * @subpackage category_banners
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 *
 * Imported globals:
 * @var module          $current_module posts
 * @var module          $this_module    category_banners
 * @var category_record $category
 */

use hng2_base\module;
use hng2_modules\categories\category_record;

global $config, $category, $settings;

$collection  = $settings->get("modules:category_banners.data");
if( empty($collection) ) return;

$collection = unserialize(base64_decode($collection));
if( ! isset($collection[$category->id_category]) ) return;

$item = $collection[$category->id_category];
if( empty($item->background) && empty($item->title) && empty($item->description) ) return;

$config->globals["modules:posts.by_category/prevent_showing_heading"] = true;

$posts_data = $config->globals["modules:posts.by_category/posts_data"];

$title = $item->title;
if( empty($title) ) $title = replace_escaped_vars($current_module->language->pages->by_category->title, '{$category}', $category->title);

$styles  = empty($item->background) ? "" : "background-image: url('{$item->background}')";
$classes = empty($item->background) ? "" : "shadowed";

$description = $item->description;
if( empty($description) ) $description = $category->description;
?>

<div class="category_banner clearfix <?= $classes ?>" style="<?= $styles ?>">
    <div class="above">
        <h1 class="title">
            <?= convert_emojis($title) ?>
            <? if($posts_data->pagination["total_pages"] > 1): ?>
                <span class="title_pagination"><?= $posts_data->pagination["this_page_number"]; ?>/<?= $posts_data->pagination["total_pages"]; ?></span>
            <? endif; ?>
        </h1>
    </div>
    <? if( ! empty($description) ): ?>
        <div class="description">
            <?= convert_emojis($description) ?>
        </div>
    <? endif; ?>
</div>
