<?php
/**
 * Categories form extender: category editing controls
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

global $account, $modules;
?>

<fieldset style="margin-bottom: 20px;">
    <legend><?= $this_module->language->form->fieldset_legend ?></legend>
    
    <div id="category_banners_form" class="multicol cols-2">
        
        <div class="col">
            <? $info_handler = "{$this_module->name}_info_background"; ?>
            <div class="field" data-field="background">
                <div class="caption">
                    <?= $this_module->language->form->background->caption ?>
                    <span class="pseudo_link" onclick="toggle_info_section('<?= $info_handler ?>')"><span
                            class="fa fa-info-circle" title="<?= $language->toggle_info ?>"></span></span>
                </div>
                <div class="input info_handler" id="<?= $info_handler ?>"
                     style="<? if($account->engine_prefs[$info_handler] == "hidden") echo "display: none;"; ?>">
                    <span class="fa fa-info-circle"></span>
                    <?= $this_module->language->form->background->info ?>
                </div>
                <div class="input" data-field="category_banners_background"><br>
                    <div class="image_selector_container" align="center">
                        <input type="hidden" class="src_image_value" name="category_banners_background" value="">
                        
                        <a class="image_selector_anchor prettyPhoto" href="<?= $src ?>"><img
                           class="settings_image_selector"
                           src="<?= $config->full_root_path ?>/media/missing_image.png"
                           data-empty-src="<?= $config->full_root_path ?>/media/missing_image.png"
                           style="position: absolute; width: 100%; top: 50%; left: 50%; transform: translate(-50%, -50%);"></a><br>
                        
                        <span class="pseudo_link" onclick="set_image(this, 'full')">
                            <?= $modules["gallery"]->language->settings_image_selector->set ?>
                        </span>
                        &nbsp;
                        <span class="pseudo_link" id="category_banners_image_removal_link" onclick="remove_image(this)">
                            <?= $modules["gallery"]->language->settings_image_selector->remove ?>
                        </span>
                    </div>
                    
                </div>
            </div>
        </div>
        
        <div class="col">
            <? $info_handler = "{$this_module->name}_info_title"; ?>
            <div class="field" data-field="background">
                <div class="caption">
                    <?= $this_module->language->form->title->caption ?>
                    <span class="pseudo_link" onclick="toggle_info_section('<?= $info_handler ?>')"><span
                            class="fa fa-info-circle" title="<?= $language->toggle_info ?>"></span></span>
                </div>
                <div class="input info_handler" id="<?= $info_handler ?>"
                     style="<? if($account->engine_prefs[$info_handler] == "hidden") echo "display: none;"; ?>">
                    <span class="fa fa-info-circle"></span>
                    <?= $this_module->language->form->title->info ?>
                </div>
                <div class="input">
                    <input type="text" name="category_banners_title">
                </div>
            </div>
            
            <? $info_handler = "{$this_module->name}_info_description"; ?>
            <div class="field" data-field="background">
                <div class="caption">
                    <?= $this_module->language->form->description->caption ?>
                    <span class="pseudo_link" onclick="toggle_info_section('<?= $info_handler ?>')"><span
                            class="fa fa-info-circle" title="<?= $language->toggle_info ?>"></span></span>
                </div>
                <div class="input info_handler" id="<?= $info_handler ?>"
                     style="<? if($account->engine_prefs[$info_handler] == "hidden") echo "display: none;"; ?>">
                    <span class="fa fa-info-circle"></span>
                    <?= $this_module->language->form->description->info ?>
                </div>
                <div class="input">
                    <textarea name="category_banners_description" class="CodeMirror"></textarea>
                </div>
            </div>
        </div>
        
    </div>
</fieldset>
