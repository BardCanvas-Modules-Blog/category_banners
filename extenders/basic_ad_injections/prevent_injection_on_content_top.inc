<?php
/**
 * Basic ad injections extender: prevent content injection at the content_top point
 *
 * @package    BardCanvas
 * @subpackage category_banners
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 */

global $config;

$config->globals["modules:basic_ad_injections.content_top/prevent_rendering"] = true;
return;
