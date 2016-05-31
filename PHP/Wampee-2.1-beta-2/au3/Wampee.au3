#NoTrayIcon
#RequireAdmin
#include-once

#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.5.6 (beta)
 Author:         Hervé Leclerc herve.leclerc@alterway.fr

 Script Function:
	Template AutoIt script.

#ce ----------------------------------------------------------------------------

; Script Start
#include <file.au3>
#include <GDIPlus.au3>
#include <WinAPI.au3>
#include <WindowsConstants.au3>
#include <GuiConstantsEx.au3>

Opt("MustDeclareVars", 0)

Global Const $AC_SRC_ALPHA = 1
Global $GUI
Global $hImage
Global $g_IP = "127.0.0.1"

TCPStartup()

$Logfile = @ScriptDir & "\tmp\wampserver.log"
$Inifile = @ScriptDir & "\resources\wampee.ini"

$Papache = IniRead($Inifile,"ports","apache","0")
$apache_port_str="@APACHE_PORT@"
$Pmysql  = IniRead($Inifile,"ports","mysql","0")
$mysql_port_str="@MYSQL_PORT@"


$ScriptPath = _PathFull(@ScriptDir & "\scripts")
FileChangeDir($ScriptPath)

if testPorts($g_IP,$Papache) = True Then
	RunWait("checkports.exe",$ScriptPath)
	Exit
EndIf
if testPorts($g_IP,$Pmysql) = True Then
	RunWait("checkports.exe",$ScriptPath)
	Exit
EndIf

FileChangeDir(_PathFull(@ScriptDir))

; Splash for fun

$tempo=100
$tamanhox=@DesktopWidth*0.46875
$tamanhoy=$tamanhox/2
$posicaox=(@DesktopWidth/2)-(511/2)
$posicaoy=(@DesktopHeight/2)-(124/2);

$Path_Logo = @ScriptDir & "\resources\wampserver.png" ;Chemin vert le fichier .png à afficher
$Time_Splash = 1500 ;Durée d'affichage de l'image .png
MySplash($Path_Logo, $Time_Splash)

; Begin
$root_path_absolute = Root_Path_Absolute()


$sc=@ScriptDir

$tpl_path = $sc & "\tpl"
$bin_path = $sc & "\bin"

; Version des logiciels / Alias
$php_version=IniRead($Inifile,"wampserver","php_version","")
$apache_version=IniRead($Inifile,"wampserver","apache_version","")
$mysql_version=IniRead($Inifile,"wampserver","mysql_version","")
$phpmyadmin_version=IniRead($Inifile,"wampserver","phpmyadmin_version","")
$sqlbuddy_version=IniRead($Inifile,"wampserver","sqlbuddy_version","")
$webgrind_version=IniRead($Inifile,"wampserver","webgrind_version","")

; Alias
$path_to_alias_w=@ScriptDir & "\alias"

; Apps
$path_to_apps_w=@ScriptDir & "\apps"
$path_to_apps_a=StringReplace($path_to_apps_w, "\", "/")

; Path Apps
$phpmyadmin_app_a=$path_to_apps_a & "/phpmyadmin" & $phpmyadmin_version
$sqlbuddy_app_a=$path_to_apps_a & "/sqlbuddy" & $sqlbuddy_version
$webgrind_app_a=$path_to_apps_a & "/webgrind" & $webgrind_version
$phpmyadmin_str="@PATH_PHPMYADMIN@"
$sqlbuddy_str="@PATH_SQLBUDDY@"
$webgrind_str="@PATH_WEBGRIND@"

; phpMyAdmin
$path_to_phpmyadmin_alias_s=$tpl_path & "\alias\phpmyadmin.conf"
$path_to_phpmyadmin_alias_c=@ScriptDir & "\alias\phpmyadmin.conf"
FileDelete($path_to_phpmyadmin_alias_c)
ScriptREPLACE($path_to_phpmyadmin_alias_s,$path_to_phpmyadmin_alias_c,$phpmyadmin_str,$phpmyadmin_app_a,0)

; sqlBuddy
$path_to_sqlbuddy_alias_s=$tpl_path & "\alias\sqlbuddy.conf"
$path_to_sqlbuddy_alias_c=@ScriptDir & "\alias\sqlbuddy.conf"
FileDelete($path_to_sqlbuddy_alias_c)
ScriptREPLACE($path_to_sqlbuddy_alias_s,$path_to_sqlbuddy_alias_c,$sqlbuddy_str,$sqlbuddy_app_a,0)

; webGrind
$path_to_webgrind_alias_s=$tpl_path & "\alias\webgrind.conf"
$path_to_webgrind_alias_c=@ScriptDir & "\alias\webgrind.conf"
FileDelete($path_to_webgrind_alias_c)
ScriptREPLACE($path_to_webgrind_alias_s,$path_to_webgrind_alias_c,$webgrind_str,$webgrind_app_a,0)

; WAMP
$wamp_path_w = @ScriptDir
$wamp_path_a=StringReplace($wamp_path_w, "\", "/")
$wamp_path_e=StringReplace($wamp_path_w, "\", "\\")
$wamp_str="@PATH_WAMP@"

; Scripts
$path_to_scripts_w=@ScriptDir & "\scripts"
$path_to_scripts_a=StringReplace($path_to_scripts_w, "\", "/")
$scripts_str="@PATH_SCRIPTS@"

; PHP
$path_to_php_w=$bin_path & "\php\php" & $php_version
$path_to_php_a=StringReplace($path_to_php_w, "\", "/")
$php_str="@PATH_PHP@"


; Apache
$path_to_apache_w=$bin_path & "\apache\apache" & $apache_version
$path_to_apache_a=StringReplace($path_to_apache_w, "\", "/")
$apache_str="@PATH_APACHE@"

; Mysql
$path_to_mysql_w=$bin_path & "\mysql\mysql" & $mysql_version
$path_to_mysql_a=StringReplace($path_to_mysql_w, "\", "/")
$mysql_str="@PATH_MYSQL@"

; Windows Explorer
$path_to_explorer_w=EnvGet("SystemRoot") & "\explorer.exe"
$path_to_explorer_e=StringReplace($path_to_explorer_w, "\", "\\")
$path_to_explorer_a=EnvGet("SystemRoot") & "/explorer.exe"
$explorer_str="@PATH_EXPLORER@"


$tpl_apache_w=$tpl_path & "\apache\apache" & $apache_version
$bin_apache_w=$bin_path & "\apache" & $apache_version

; wampmanager.ini
$wampmanager_ini_s=$tpl_path &    "\wampmanager.ini"
$wampmanager_ini_c=$wamp_path_w & "\resources\wampmanager.ini"
FileDelete($wampmanager_ini_c)

ScriptREPLACE    ($wampmanager_ini_s, $wampmanager_ini_c, $php_str,         $path_to_php_a,     0)
ScriptREPLACEOnce($wampmanager_ini_c,                     $apache_str,      $path_to_apache_a,  0)
ScriptREPLACEOnce($wampmanager_ini_c,                     $mysql_str,       $path_to_mysql_a,   0)
ScriptREPLACEOnce($wampmanager_ini_c,                     $scripts_str,     $path_to_scripts_a, 0)
ScriptREPLACEOnce($wampmanager_ini_c,                     $mysql_str,       $path_to_mysql_a,   0)
ScriptREPLACEOnce($wampmanager_ini_c,                     $explorer_str,    $path_to_explorer_e,0)
ScriptREPLACEOnce($wampmanager_ini_c,                     $wamp_str,        $wamp_path_a,       0)
ScriptREPLACEOnce($wampmanager_ini_c,                     $apache_port_str, $Papache,           0)

; wampmanager.conf
$wampmanager_conf_s=$tpl_path &    "\wampmanager.conf"
$wampmanager_conf_c=$wamp_path_w & "\resources\wampmanager.conf"
FileDelete($wampmanager_conf_c)

ScriptREPLACE    ($wampmanager_conf_s, $wampmanager_conf_c, $wamp_str,      $wamp_path_a,         0)
ScriptREPLACEOnce($wampmanager_conf_c,                      $explorer_str,  $path_to_explorer_e,  0)

; @PATH_PHP@/bin/php.ini
$php_ini_s=$tpl_path & "\php\php" & $php_version & "\php.ini"
$php_ini_c=$path_to_php_w & "\php.ini"
FileDelete($php_ini_c)

ScriptREPLACE    ($php_ini_s, $php_ini_c,  $php_str,         $path_to_php_a,    0)
ScriptREPLACEOnce($php_ini_c,              $wamp_str,        $wamp_path_a,      0)
ScriptREPLACEOnce($php_ini_c,              $mysql_port_str,  $Pmysql,           0)

; @PATH_APACHE@/bin/php.ini
$php_ini_s=$tpl_path & "\apache\apache" & $apache_version & "\bin\php.ini"
$php_ini_c=$path_to_apache_w & "\bin\php.ini"
FileDelete($php_ini_c)

ScriptREPLACE    ($php_ini_s, $php_ini_c,  $php_str,         $path_to_php_a,    0)
ScriptREPLACEOnce($php_ini_c,              $wamp_str,        $wamp_path_a,      0)
ScriptREPLACEOnce($php_ini_c,              $mysql_port_str,  $Pmysql,      0)

; @PATH_APACHE@/conf/httpd.conf
$httpd_conf_s=$tpl_path & "\apache\apache" & $apache_version & "\conf\httpd.conf"
$httpd_conf_c=$path_to_apache_w & "\conf\httpd.conf"
FileDelete($httpd_conf_c)

ScriptREPLACE    ($httpd_conf_s, $httpd_conf_c,  $apache_str,      $path_to_apache_a,    0)
ScriptREPLACEOnce($httpd_conf_c,                 $php_str,         $path_to_php_a,       0)
ScriptREPLACEOnce($httpd_conf_c,                 $wamp_str,        $wamp_path_a,         0)
ScriptREPLACEOnce($httpd_conf_c,                 $apache_port_str, $Papache,             0)


; @PATH_MYSQL@/my.ini
$my_ini_s=$tpl_path & "\mysql\mysql" & $mysql_version & "\my.ini"
$my_ini_c=$path_to_mysql_w & "\my.ini"
FileDelete($my_ini_c)

ScriptREPLACE    ($my_ini_s, $my_ini_c,      $mysql_str,       $path_to_mysql_a,    0)
ScriptREPLACEOnce($my_ini_c,                 $wamp_str,        $wamp_path_a,        0)
ScriptREPLACEOnce($my_ini_c,                 $mysql_port_str,  $Pmysql,             0)

; MyWebApps
; Lecture des conf applicatives
$MyWebApps_tpl_dir   = $tpl_path & "\MyWebApps"
$MyWebApps_tpl_alias = $MyWebApps_tpl_dir & "\etc\alias"
$MyWebApps_dir_w     = @ScriptDir & "\MyWebApps"
$MyWebApps_dir_alias = $MyWebApps_dir_w & "\etc\alias"

$MyWebApps_dir_opt_w = $MyWebApps_dir_w & "\opt"
$MyWebApps_dir_opt_a = StringReplace($MyWebApps_dir_opt_w, "\", "/")
$MyWebApps_str       = "@PATH_WEBAPP@"
$search = FileFindFirstFile($MyWebApps_tpl_alias & "\*.conf")
If $search <> -1 Then
	While 1
		$file = FileFindNextFile($search)
		If @error Then ExitLoop
		$f_s=$MyWebApps_tpl_alias&"\"&$file
		$f_c=$MyWebApps_dir_alias&"\"&$file
		FileDelete($f_c)
		ScriptREPLACE($f_s, $f_c, $MyWebApps_str, $MyWebApps_dir_opt_a, 0)
	WEnd
EndIf

Run("resources\wampmanager.exe",".",@SW_HIDE)

EndSplash()

Func testPorts($IP,$port)

	$socket = TCPConnect($IP,$port)
	If $socket = -1  or $socket = 0 Then
		Return False
	Else
		Return True
	EndIf
EndFunc

; Commons Functions

Func ScriptCOMMAND($cmd, $info=False)
	RunWait($cmd)
	If $info<>False Then
		InfoShowWindow($cmd & @CRLF & @CRLF & $info)
	EndIf
EndFunc

Func ScriptREPLACE($file, $filet, $search, $replace, $info=False)
			If NOT FileExists($file) Then
				MsgBox(64, "Error", "FileNotFound" & @CRLF & $file)
			EndIf
			$filec=FileOpen($file,0)
			$content=FileRead($filec)
			FileClose($filec)
			$filec=FileOpen($filet,2)
			$content = StringRegExpReplace($content, $search, $replace)
			if (@error=0) Then
				If $info<>False Then
					InfoShowWindow($info)
				EndIf
			Else
				MsgBox(32, "RegExpReplace", "RegExpReplaceFail")
				If $info<>False Then
					InfoShowWindow($info)
				EndIf
			EndIf
			FileWrite($filec, $content)
			FileClose($filec)
		EndFunc
Func ScriptREPLACEOnce($file, $search, $replace, $info=False)
			If NOT FileExists($file) Then
				MsgBox(64, "Error", "FileNotFound" & @CRLF & $file)
			EndIf
			$filec=FileOpen($file,0)
			$content=FileRead($filec)
			FileClose($filec)
			$filec=FileOpen($file,2)
			$content = StringRegExpReplace($content, $search, $replace)
			if (@error=0) Then
				If $info<>False Then
					InfoShowWindow($info)
				EndIf
			Else
				MsgBox(32, "RegExpReplace", "RegExpReplaceFail")
				If $info<>False Then
					InfoShowWindow($info)
				EndIf
			EndIf
			FileWrite($filec, $content)
			FileClose($filec)
EndFunc



Func ScriptEDIT($file,$info=False)
			If NOT FileExists($file) Then
				MsgBox(64, "Error", "FileNotFound" & @CRLF & $file)
			EndIf
			ShellExecute($file)
EndFunc

Func ScriptURL($url)
			ShellExecute($url)
EndFunc

Func Root_Path_Absolute()
	Local $sd, $rpa
	$sd = StringSplit(@ScriptDir, "\")

	For $i = 1 To $sd[0] - 2
		$rpa &= $sd[$i]
		If ($i < $sd[0] - 2) Then $rpa &= "\"
	Next
	Return $rpa

EndFunc   ;==>Root_Path_Absolute


Func InfoShowWindow($msg, $mode = "set")
	Return
EndFunc   ;==>InfoShowWindow


Func MySplash($Path_Logo, $Time_Splash)
    _GDIPlus_Startup()
    $pngSrc = $Path_Logo
    $hImage = _GDIPlus_ImageLoadFromFile($pngSrc)
    $width = _GDIPlus_ImageGetWidth($hImage)
    $height = _GDIPlus_ImageGetHeight($hImage)
    $GUI = GUICreate("logo", $width, $height, -1, -1, $WS_POPUP, $WS_EX_LAYERED)
    SetBitmap($GUI, $hImage, 0)
    GUISetState()
    WinSetOnTop($GUI, "", 1)
    For $i = 0 To 255 Step 10
        SetBitmap($GUI, $hImage, $i)
    Next
    Sleep($Time_Splash)

EndFunc   ;==>MySplash

Func EndSplash()
	For $i = 255 To 0 Step -10
        SetBitmap($GUI, $hImage, $i)
    Next
	_WinAPI_DeleteObject($hImage)
    _GDIPlus_Shutdown()
    GUIDelete($GUI)
EndFunc

Func SetBitmap($hGUI, $hImage, $iOpacity)
    Local $hScrDC, $hMemDC, $hBitmap, $hOld, $pSize, $tSize, $pSource, $tSource, $pBlend, $tBlend

    $hScrDC = _WinAPI_GetDC(0)
    $hMemDC = _WinAPI_CreateCompatibleDC($hScrDC)
    $hBitmap = _GDIPlus_BitmapCreateHBITMAPFromBitmap($hImage)
    $hOld = _WinAPI_SelectObject($hMemDC, $hBitmap)
    $tSize = DllStructCreate($tagSIZE)
    $pSize = DllStructGetPtr($tSize)
    DllStructSetData($tSize, "X", _GDIPlus_ImageGetWidth($hImage))
    DllStructSetData($tSize, "Y", _GDIPlus_ImageGetHeight($hImage))
    $tSource = DllStructCreate($tagPOINT)
    $pSource = DllStructGetPtr($tSource)
    $tBlend = DllStructCreate($tagBLENDFUNCTION)
    $pBlend = DllStructGetPtr($tBlend)
    DllStructSetData($tBlend, "Alpha", $iOpacity)
    DllStructSetData($tBlend, "Format", $AC_SRC_ALPHA)
    _WinAPI_UpdateLayeredWindow($hGUI, $hScrDC, 0, $pSize, $hMemDC, $pSource, 0, $pBlend, $ULW_ALPHA)
    _WinAPI_ReleaseDC(0, $hScrDC)
    _WinAPI_SelectObject($hMemDC, $hOld)
    _WinAPI_DeleteObject($hBitmap)
    _WinAPI_DeleteDC($hMemDC)
EndFunc   ;==>SetBitmap

