/**
 *  iotinator XIOT module settings page 
 *  Xavier Grosjean 2022
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 #pragma once

 #include "Messages.h"

 char settingsBeginingPage[] = "\
<html title='" MSG_SETINGS_WELCOME "'>\
<head>\
<meta charset='UTF-8'>\
<meta name='viewport' content='width=device-width, initial-scale=1'>\
<style>\
body{line-height:1.5em}\
input{left:100px;position:absolute}\
a{right:40px;position:absolute;text-decoration:none}\
</style>\
</head>\
<body>\
<h1>" MSG_SETINGS_WELCOME "<a href='/config'>⚙</a></h1>\
<form action='/feederApi/saveSettings' method='post'>\
";

char formTemplate[] = "\
" MSG_INIT_HOUR " <input name='" HOUR_PARAM_NAME "' value='%d' type='number' min=0 max=23 size=4/></br>\
" MSG_INIT_QUANTITY " <input name='" QUANTITY_PARAM_NAME "' value='%d' type='number' min=0 max=5000 size=4/></br>\
" MSG_INIT_ACTIVE " <input name='" ACTIVE_PARAM_NAME "' type='checkbox' %s/></br><hr>\
";

char settingsEndingPage[]="\
  <input type='submit'/>\
</form>\
</body>\
</html>\
";