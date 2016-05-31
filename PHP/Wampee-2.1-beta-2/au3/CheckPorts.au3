#RequireAdmin
#NoTrayIcon
#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_Outfile_Type=a3x
#AutoIt3Wrapper_Icon=wampserver.ico
#AutoIt3Wrapper_Outfile=checkports.a3x
#AutoIt3Wrapper_UseX64=n
#AutoIt3Wrapper_Au3Check_Stop_OnWarning=y
#AutoIt3Wrapper_Run_Tidy=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****
#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include <UpdownConstants.au3>
#include <file.au3>
#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.5.6 (beta)
 Author:         Herve Leclerc (herve.leclerc@alterway.fr)

#ce ----------------------------------------------------------------------------

Opt("GUIOnEventMode", 1)
Global $wampserverGUI
Global $ef_apache
Global $ef_mysql
Global $bu_ok
Global $bu_test
Global $g_IP = "127.0.0.1"
Global $Inifile
Global $noGood


TCPStartup()

$Inifile = _PathFull(@ScriptDir & "\..\resources\wampee.ini")
$Papache = IniRead($Inifile, "ports", "apache", "80")
$Pmysql = IniRead($Inifile, "ports", "mysql", "3306")

ShowGUI()

GUICtrlSetData($ef_apache, $Papache)
GUICtrlSetData($ef_mysql, $Pmysql)

testPorts()

GUISetState(@SW_SHOW)

While 1
	Sleep(100)
WEnd

Func bu_cancelClick()
	Exit
EndFunc   ;==>bu_cancelClick
Func bu_okClick()
	IniWrite($Inifile, "ports", "apache", GUICtrlRead($ef_apache))
	IniWrite($Inifile, "ports", "mysql", GUICtrlRead($ef_mysql))
	$pathAbs = _PathFull(@ScriptDir & "\..\")
	FileChangeDir($pathAbs)
	$value = Run($pathAbs & "wampee.exe", $pathAbs)
	Exit
EndFunc   ;==>bu_okClick
Func bu_testClick()
	testPorts()
EndFunc   ;==>bu_testClick
Func ef_apacheChange()
	GUICtrlSetState($bu_ok, $GUI_DISABLE)
EndFunc   ;==>ef_apacheChange
Func ef_mysqlChange()
	GUICtrlSetState($bu_ok, $GUI_DISABLE)
EndFunc   ;==>ef_mysqlChange
Func label_apacheClick()

EndFunc   ;==>label_apacheClick
Func ud_apacheChange()
	GUICtrlSetState($bu_ok, $GUI_DISABLE)
EndFunc   ;==>ud_apacheChange
Func ud_mysqlChange()
	GUICtrlSetState($bu_ok, $GUI_DISABLE)
EndFunc   ;==>ud_mysqlChange
Func wampserverClose()
	Exit
EndFunc   ;==>wampserverClose
Func wampserverMaximize()

EndFunc   ;==>wampserverMaximize
Func wampserverMinimize()

EndFunc   ;==>wampserverMinimize
Func wampserverRestore()

EndFunc   ;==>wampserverRestore

Func testPorts()
	GUICtrlSetState($bu_ok, $GUI_ENABLE)
	$noGood = False
	$socketa = TCPConnect($g_IP, GUICtrlRead($ef_apache))
	If $socketa = -1 Or $socketa = 0 Then
		GUICtrlSetBkColor($ef_apache, 0x00ff00)
	Else
		GUICtrlSetBkColor($ef_apache, 0xff0000)
		GUICtrlSetState($bu_ok, $GUI_DISABLE)
		$noGood = True
	EndIf

	$socketm = TCPConnect($g_IP, GUICtrlRead($ef_mysql))
	If $socketm = -1 Or $socketm = 0 Then
		GUICtrlSetBkColor($ef_mysql, 0x00ff00)
	Else
		GUICtrlSetBkColor($ef_mysql, 0xff0000)
		GUICtrlSetState($bu_ok, $GUI_DISABLE)
		$noGood = True
	EndIf
	Return $noGood
EndFunc   ;==>testPorts

Func ShowGUI()
	$wampserverGUI = GUICreate("Wampserver", 254, 150, 393, 120)
	GUISetOnEvent($GUI_EVENT_CLOSE, "wampserverClose")
	GUISetOnEvent($GUI_EVENT_MINIMIZE, "wampserverMinimize")
	GUISetOnEvent($GUI_EVENT_MAXIMIZE, "wampserverMaximize")
	GUISetOnEvent($GUI_EVENT_RESTORE, "wampserverRestore")
	$label_apache = GUICtrlCreateLabel("Port HTTP Apache", 16, 26, 95, 17)
	GUICtrlSetOnEvent(-1, "label_apacheClick")
	$ef_apache = GUICtrlCreateInput("80", 112, 24, 65, 21, $ES_NUMBER)
	GUICtrlSetOnEvent(-1, "ef_apacheChange")
	$ud_apache = GUICtrlCreateUpdown($ef_apache, $UDS_NOTHOUSANDS)
	GUICtrlSetLimit(-1, 32767, 80)
	GUICtrlSetOnEvent(-1, "ud_apacheChange")
	$Group1 = GUICtrlCreateGroup("Ports WampServer", 1, 0, 241, 97)
	GUICtrlCreateGroup("", -99, -99, 1, 1)
	$Label1 = GUICtrlCreateLabel("Port MySQL", 16, 64, 61, 17)

	$ef_mysql = GUICtrlCreateInput("1024", 112, 62, 65, 21, $ES_NUMBER)
	GUICtrlSetOnEvent(-1, "ef_mysqlChange")
	$ud_mysql = GUICtrlCreateUpdown($ef_mysql, $UDS_NOTHOUSANDS)
	GUICtrlSetLimit(-1, 32767, 1024)
	GUICtrlSetOnEvent(-1, "ud_mysqlChange")
	$bu_ok = GUICtrlCreateButton("OK", 8, 104, 73, 25)
	GUICtrlSetOnEvent(-1, "bu_okClick")
	$bu_cancel = GUICtrlCreateButton("Cancel", 168, 104, 73, 25)
	GUICtrlSetOnEvent(-1, "bu_cancelClick")
	$bu_test = GUICtrlCreateButton("Test", 88, 104, 73, 25)
	GUICtrlSetOnEvent(-1, "bu_testClick")
EndFunc   ;==>ShowGUI