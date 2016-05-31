<?php
$tpl = <<< EOTPL
[Config]
;WAMPCONFIGSTART
ImageList=images_off.bmp
ServiceCheckInterval=1
ServiceGlyphRunning=13
ServiceGlyphPaused=10
ServiceGlyphStopped=11
;TrayIcon=wampserver.ico
TrayIconAllRunning=16
TrayIconSomeRunning=17
TrayIconNoneRunning=18
ID={wampee}
AboutHeader=WAMPEE (Wampserver Portable)
AboutVersion=Version ${c_wampVersion}
;WAMPCONFIGEND

[AboutText]
Wampee Version ${c_wampVersion}

Created by Herve Leclerc (herve.leclerc@alterway.fr)

Sources are available at SourceForge

http://www.wampserver.com

[Messages]
AllRunningHint=WAMPEE - ${w_serverOffline}
SomeRunningHint=WAMPEE - ${w_serverOffline}
NoneRunningHint=WAMPEE - ${w_serverOffline}

[StartupAction]
;WAMPSTARTUPACTIONSTART
Action: run; FileName: "${c_phpCli}";Parameters: "refresh.php";WorkingDir: "${c_installDir}/scripts"; Flags: waituntilterminated
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop all";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "start all"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; Parameters: "start all"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig;
;WAMPSTARTUPACTIONEND

[Menu.Right.Settings]
;WAMPMENURIGHTSETTINGSSTART
BarVisible=no
SeparatorsAlignment=center
SeparatorsFade=yes
SeparatorsFadeColor=clBtnShadow
SeparatorsFlatLines=yes
SeparatorsGradientEnd=clSilver
SeparatorsGradientStart=clGray
SeparatorsGradientStyle=horizontal
SeparatorsSeparatorStyle=shortline
;WAMPMENURIGHTSETTINGSEND

[Menu.Left.Settings]
;WAMPMENULEFTSETTINGSSTART
AutoLineReduction=no
BarVisible=yes
BarCaptionAlignment=bottom
BarCaptionCaption=Wampee ${c_wampVersion}
BarCaptionDepth=1
BarCaptionDirection=downtoup
BarCaptionFont=Tahoma,16,clWhite,bold italic
BarCaptionHighlightColor=clNone
BarCaptionOffsetY=0
BarCaptionShadowColor=clNone
BarPictureHorzAlignment=center
BarPictureOffsetX=0
BarPictureOffsetY=0
BarPicturePicture=barimage.bmp
BarPictureTransparent=yes
BarPictureVertAlignment=bottom
BarBorder=clNone
BarGradientEnd=$00550000
BarGradientStart=clBlue
BarGradientStyle=horizontal
BarSide=left
BarSpace=0
BarWidth=32
SeparatorsAlignment=center
SeparatorsFade=yes
SeparatorsFadeColor=clBtnShadow
SeparatorsFlatLines=yes
SeparatorsFont=Arial,8,clWhite,bold 
SeparatorsGradientEnd=$00FFAA55
SeparatorsGradientStart=$00550000
SeparatorsGradientStyle=horizontal
SeparatorsSeparatorStyle=caption
;WAMPMENULEFTSETTINGSSTART

[Menu.Right]
;WAMPMENURIGHTSTART
Type: item; Caption: "${w_about}"; Action: about
Type: item; Caption: "Refresh"; Action: multi; Actions: wampreload
Type: item; Caption: "${w_help}"; Action: run; FileName: "${c_navigator}"; Parameters: "http://www.Wampserver.com/presentation.php"; Glyph: 5
Type: submenu; Caption: "${w_language}"; SubMenu: language; Glyph: 3
Type: item; Caption: "${w_exit}"; Action: multi; Actions: myexit;
;WAMPMENURIGHTEND

[wampreload]
;WAMPRELOADSTART
Action: run; FileName: "${c_phpCli}";Parameters: "refresh.php";WorkingDir: "${c_installDir}/scripts"; Flags: waituntilterminated
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig;
;WAMPRELOADEND

[language]
;WAMPLANGUAGESTART
;WAMPLANGUAGEEND


[Menu.Left]
;WAMPMENULEFTSTART
Type: separator; Caption: "Powered by Alter Way"
Type: item; Caption: "${w_localhost}"; Action: run; FileName: "${c_navigator}"; Parameters: "http://localhost:@APACHE_PORT@/"; Glyph: 5
Type: item; Caption: "${w_phpmyadmin}"; Action: run; FileName: "${c_navigator}"; Parameters: "http://localhost:@APACHE_PORT@/phpmyadmin/"; Glyph: 5
Type: item; Caption: "${w_wwwDirectory}"; Action: shellexecute; FileName: "${wwwDir}"; Glyph: 2
Type: submenu; Caption: "Apache"; SubMenu: apacheMenu; Glyph: 19
Type: submenu; Caption: "PHP"; SubMenu: phpMenu; Glyph: 4
Type: submenu; Caption: "MySQL"; SubMenu: mysqlMenu; Glyph: 15
Type: separator; Caption: "Debug"
Type: item; Caption: "Client XDebug"; Glyph: 14; Action: run; FileName: "${c_installDir}/tools/xdc/xdc.exe"
Type: item; Caption: "${c_webgrind}"; Action: run; FileName: "${c_navigator}"; Parameters: "http://localhost:@APACHE_PORT@/webgrind/"; Glyph: 5
Type: separator; Caption: "Quick Admin"
Type: item; Caption: "${w_startServices}"; Action: multi; Actions: StartAll; Glyph: 9
Type: item; Caption: "${w_stopServices}"; Action: multi; Actions: StopAll; Glyph: 11
Type: item; Caption: "${w_restartServices}"; Action: multi; Actions: RestartAll; Glyph: 12
Type: separator;
Type: item; Caption: "Eject Key"; Action: multi; Actions: WampEject; Glyph: 10
Type: separator;
Type: item; Caption: "${w_putOnline}"; Action: multi; Actions: onlineoffline
;WAMPMENULEFTEND

[apacheMenu]
;WAMPAPACHEMENUSTART
Type: submenu; Caption: "Version"; SubMenu: apacheVersion; Glyph: 3
Type: submenu; Caption: "Service"; SubMenu: apacheService; Glyph: 3
Type: submenu; Caption: "${w_apacheModules}"; SubMenu: apache_mod; Glyph: 3
Type: submenu; Caption: "${w_aliasDirectories}"; SubMenu: alias_dir; Glyph: 3
Type: item; Caption: "httpd.conf"; Glyph: 6; Action: run; FileName: "notepad.exe"; parameters:"${c_apacheConfFile}"
Type: item; Caption: "${w_apacheErrorLog}"; Glyph: 6; Action: run; FileName: "notepad.exe"; parameters:"${c_installDir}/${logDir}apache_error.log"
Type: item; Caption: "${w_apacheAccessLog}"; Glyph: 6; Action: run; FileName: "notepad.exe"; parameters:"${c_installDir}/${logDir}access.log"
;WAMPAPACHEMENUEND

[apacheVersion]
;WAMPAPACHEVERSIONSTART
;WAMPAPACHEVERSIONEND

[phpMenu]
;WAMPPHPMENUSTART
Type: submenu; Caption: "Version"; SubMenu: phpVersion; Glyph: 3
Type: submenu; Caption: "${w_phpSettings}"; SubMenu: php_params;  Glyph: 3
Type: submenu; Caption: "${w_phpExtensions}"; SubMenu: php_ext;  Glyph: 3
Type: item; Caption: "php.ini"; Glyph: 6; Action: run; FileName: "notepad.exe"; parameters: "${c_phpConfFile}"
Type: item; Caption: "${w_phpLog}"; Glyph: 6; Action: run; FileName: "notepad.exe"; parameters: "${c_installDir}/${logDir}php_error.log"
;WAMPPHPMENUEND

[phpVersion]
;WAMPPHPVERSIONSTART
;WAMPPHPVERSIONEND

[mysqlMenu]
;WAMPMYSQLMENUSTART
Type: submenu; Caption: "Version"; SubMenu: mysqlVersion; Glyph: 3
Type: submenu; Caption: "Service"; SubMenu: mysqlService; Glyph: 3
Type: item; Caption: "${w_mysqlConsole}"; Action: run; FileName: "${c_mysqlConsole}";Parameters: "-u root -p"; Glyph: 0
Type: item; Caption: "my.ini"; Glyph: 6; Action: run; FileName: "notepad.exe"; parameters: "${c_mysqlConfFile}"
Type: item; Caption: "${w_mysqlLog}"; Glyph: 6; Action: run; FileName: "notepad.exe"; parameters: "${c_installDir}/${logDir}mysql.log"
;WAMPMYSQLMENUEND

[mysqlVersion]
;WAMPMYSQLVERSIONSTART
;WAMPMYSQLVERSIONEND

[alias_dir]
;WAMPALIAS_DIRSTART
Type: separator; Caption: "${w_aliasDirectories}"
Type: item; Caption: "${w_adddAlias}"; Action: multi; Actions: add_alias;Glyph : 1
Type: separator
;WAMPADDALIAS
;WAMPALIAS_DIREND


[php_params]
Type: separator; Caption: "${w_phpSettings}"
;WAMPPHP_PARAMSSTART
;WAMPPHP_PARAMSEND


[php_ext]
Type: separator; Caption: "${w_phpExtensions}"
;WAMPPHP_EXTSTART
;WAMPPHP_EXTEND



[add_alias]
;WAMPADD_ALIASSTART
Action: run; FileName: "${c_phpExe}";Parameters: "-c . addAlias.php";WorkingDir: "${c_installDir}/scripts"; Flags: waituntilterminated
Action: run; FileName: "${c_phpCli}";Parameters: "refresh.php";WorkingDir: "${c_installDir}/scripts"; Flags: waituntilterminated
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop apache";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "start apache";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig;
;WAMPADD_ALIASEND


[DoubleClickAction]
Action: about;

[apacheService]
;WAMPAPACHESERVICESTART
Type: separator; Caption: "${w_apache}"
Type: item; Caption: "${w_startResume}"; Action: multi; Actions: start_apache_p; Glyph: 9
Type: item; Caption: "${w_stopService}"; Action: multi; Actions: stop_apache_p ; Glyph: 11
Type: item; Caption: "${w_restartService}"; Action: multi; Actions: restart_apache_p; Glyph: 12
Type: separator
Type: item; Caption: "${w_testPort80}"; Action: run; FileName: "${c_phpExe}";Parameters: "-c . testPort.php";WorkingDir: "$c_installDir/scripts"; Flags: waituntilterminated; Glyph: 9
;WAMPAPACHESERVICEEND

[start_apache_p]
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "start apache";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig

[stop_apache_p]
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop apache";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig

[restart_apache_p]
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop apache";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "start apache";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig


[MySqlService]
;WAMPMYSQLSERVICESTART
Type: separator; Caption: "${w_mysql}"
Type: item; Caption: "${w_startResume}"; Action: multi; Actions: start_mysql_p; Glyph: 9
Type: item; Caption: "${w_stopService}"; Action: multi; Actions: stop_mysql_p; Glyph: 11
Type: item; Caption: "${w_restartService}"; Action: multi; Actions: restart_mysql_p; Glyph: 12
;WAMPMYSQLSERVICEEND

[start_mysql_p]
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "start mysql";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig

[stop_mysql_p]
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop mysql";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig

[restart_mysql_p]
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop mysql";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "start mysql";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig


[StartAll]
;WAMPSTARTALLSTART
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "start all";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ;
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig
;WAMPSTARTALLEND

[StopAll]
;WAMPSTOPALLSTART
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop all";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ; 
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig
;WAMPSTOPALLEND

[WampEject]
;WAMPEJECT
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop all";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated ; 
;Action: run; FileName: "${c_apacheExe}"; Parameters: "${c_apacheServiceRemoveParams}"; ShowCmd: hidden; Flags: waituntilterminated
;Action: run; FileName: "${c_mysqlExe}"; Parameters: "${c_mysqlServiceRemoveParams}"; ShowCmd: hidden; Flags: waituntilterminated
Action:  exit
;WAMPEJECTEND

[RestartAll]
;WAMPRESTARTALLSTART
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "restart all";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig
;WAMPRESTARTALLEND

[myexit]
;WAMPMYEXITSTART
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "stop all";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig
Action:  exit
;WAMPMYEXITEND

[apache_mod]
Type: separator; Caption: "${w_apacheModules}"
;WAMPAPACHE_MODSTART
;WAMPAPACHE_MODEND

[onlineoffline]
;WAMPONLINEOFFLINESTART
Action: run; FileName: "${c_phpCli}";Parameters: "onlineOffline.php on";WorkingDir: "${c_installDir}/scripts"; Flags: waituntilterminated
Action: run; FileName: "${c_phpCli}";Parameters: "refresh.php";WorkingDir: "${c_installDir}/scripts"; Flags: waituntilterminated
Action: run; FileName: "${c_installDir}/scripts/WampeeSrv.exe"; Parameters: "restart all";  WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated
Action: run; FileName: "${c_installDir}/scripts/CheckProcess.exe"; WorkingDir: "${c_installDir}/scripts"; ShowCmd: hidden; Flags: waituntilterminated 
Action: readconfig;
;WAMPONLINEOFFLINEEND
EOTPL;

?>