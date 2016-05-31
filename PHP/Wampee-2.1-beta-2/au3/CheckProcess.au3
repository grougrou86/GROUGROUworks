#NoTrayIcon
#RequireAdmin
#include <file.au3>
#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.5.6 (beta)
 Author:         Herve Leclerc (herve.leclerc@alterway.fr)

 Script Function:
	Wampee Start Stop

#ce ----------------------------------------------------------------------------
Global $apache_proc_name
Global $mysql_proc_name

$apache_proc_name = "wampeehttpd.exe"
$mysql_proc_name  = "wampeemysqld.exe"

$Inifile = @ScriptDir & "\..\resources\wampmanager.ini"

$apache_pid=ProcessExists($apache_proc_name)
$mysql_pid =ProcessExists($mysql_proc_name)

If $apache_pid <> 0 And $mysql_pid <> 0 Then
	$TrayIconNoneRunning=16
ElseIf $apache_pid = 0 And $mysql_pid = 0 Then
	$TrayIconNoneRunning=18
Else
	$TrayIconNoneRunning=17
EndIf

IniWrite($Inifile,"Config","TrayIconNoneRunning",$TrayIconNoneRunning)

Exit