<?php

function _istat_block_population() {
  $code = variable_get('istat_municipality_code', '');
  $width = variable_get('istat_municipality_width', '200');
  $height = variable_get('istat_municipality_height', '300');
  $url = variable_get('istat_municipality_url', DEFAULT_PROXY);
  
  $default_subject = t('Municipality Population');
  
  if (!$code) {
    $content = t('Please check configuration by clicking <a href="@url"> here </a>.', 
                  array('@url' => url('admin/build/block/configure/istat/population', array('absolute' => TRUE))));
  }
  else {
   $content = theme('istat_block_population', check_plain($code), $width, $height, $url);
  }
  return array('subject' => $default_subject, 'content' => $content);
}

