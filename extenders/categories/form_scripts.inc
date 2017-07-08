<?php
/**
 * Categories index extender: category editing controls
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
?>

<!-- Category banners scripts -->

<script type="text/javascript">
    
    category_form_post_show_callbacks[category_form_post_show_callbacks.length] = function()
    {
        $('#category_banners_form').find('textarea.CodeMirror').each(function()
        {
            var editor;
            
            if( $(this).attr('processed') )
            {
                editor = $(this).data('editor');
                editor.refresh();
                
                return;
            }
            
            var element = $(this).get(0);
            
            editor = CodeMirror.fromTextArea(element, {
                // viewPortMargin: Infinity,
                lineNumbers:    true,
                lineWrapping:   true,
                mode:           'htmlmixed'
            });
            
            $(this).attr('processed', 'true');
            $(this).data('editor', editor);
        });
    };

    category_form_reset_callbacks[category_form_reset_callbacks.length] = function($form)
    {
        var $link = $('#category_banners_image_removal_link');
        remove_image($link);
        
        $('#category_banners_form').find('textarea.CodeMirror').each(function()
        {
            var editor = $(this).data('editor');
            if( typeof editor == 'undefined' ) return;
            
            editor.setValue('');
            editor.clearHistory();
        });
    };
    
    category_form_fill_callbacks[category_form_fill_callbacks.length] = function($form, record)
    {
        if( typeof record.category_banners_background  == 'undefined' ) record.category_banners_background  = '';
        if( typeof record.category_banners_title       == 'undefined' ) record.category_banners_title       = '';
        if( typeof record.category_banners_description == 'undefined' ) record.category_banners_description = '';
        
        var actual_background = record.category_banners_background;
        if( record.category_banners_background == '' )
            record.category_banners_background = $_FULL_ROOT_PATH + '/media/missing_image.png';
        
        var selector = '.input[data-field="category_banners_background"] .settings_image_selector';
        $form.find('input[name="category_banners_background"]').val(actual_background);
        $form.find(selector).attr('src', record.category_banners_background);
        $form.find(selector).closest('a').attr('href', record.category_banners_background);
        
        $form.find('input[name="category_banners_title"]').val( record.category_banners_title );
        
        $form.find('textarea.CodeMirror').each(function()
        {
            var editor = $(this).data('editor');
            var name   = $(this).attr('name');
            
            if( typeof editor == 'undefined' )
            {
                $(this).val(record[name]);
                
                return;
            }
            
            editor.setValue(record[name]);
            editor.clearHistory();
        });
    };

    category_form_presubmit_callbacks[category_form_presubmit_callbacks.length] = function($form)
    {
        $form.find('textarea.CodeMirror').each(function()
        {
            var editor = $(this).data('editor');
            editor.save();
        });
    };
</script>
