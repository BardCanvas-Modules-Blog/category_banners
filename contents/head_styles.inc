<?php
/**
 * Styles
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

global $config, $template, $settings;

if($template->get("page_tag") != "post_category_index" ) return;
?>

<!-- Category Banner styles -->

<link rel="stylesheet" href="<?= $this_module->get_url() ?>/media/styles~v1.0.0-5.css">

