#include <file.au3>
#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include "wampserver-funcs.au3"
#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.5.6 (beta)
 Author:         Herve Leclerc (herve.leclerc@alterway.fr)

#ce ----------------------------------------------------------------------------
Opt("GUIOnEventMode", 1)

$Form = GUICreate("Create an application", 320, 113, 353, 182)
GUISetOnEvent($GUI_EVENT_CLOSE, "FormClose")
$ef_app = GUICtrlCreateInput("", 112, 10, 169, 21)
GUICtrlSetOnEvent(-1, "ef_appChange")
GUICtrlSetTip(-1, "Please provide an application name")
$Label1 = GUICtrlCreateLabel("Nom de l'application", 8, 12, 99, 17)
$btn_ok = GUICtrlCreateButton("OK", 56, 48, 100, 25)
GUICtrlSetOnEvent(-1, "btn_okClick")
$btn_cancel = GUICtrlCreateButton("Cancel", 176, 48, 100, 25)
GUICtrlSetOnEvent(-1, "btn_cancelClick")
GUISetState(@SW_SHOW)


While 1
	Sleep(100)
WEnd

Func btn_cancelClick()
	Exit
EndFunc   ;==>btn_cancelClick
Func btn_okClick()
	$value = GUICtrlRead($ef_app)
	$sc = _PathFull(@ScriptDir & "\..\tpl\MyWebApps")
	$cnf = $sc & "\etc\alias"
	$tpl_app = $cnf & "\mywebapp.conf.tpl"
	$alias=_PathFull(@ScriptDir & "\..\alias")
	$wbapp = _PathFull(@ScriptDir & "\..\MyWebApps\opt")

	If $value = "" Then
		MsgBox(0, "Mandatory Value", "Please provide an application name")
		Return
	EndIf
	If StringIsAlNum($value) = 0 Then
		MsgBox(0, "Bad Value", "Please provide a valid application name" & @CR & "(Only Alphunumeric Characters)")
		Return
	EndIf

	$search = FileFindFirstFile($cnf & "\*.conf")
	If $search <> -1 Then
		While 1
			$file = FileFindNextFile($search)
			If @error Then ExitLoop
			$filename = StringSplit($file, ".")
			If StringLower($filename[1]) = StringLower($value) Then
				MsgBox(16, "Existing Application", "Application " & $filename[1] & " already exists")
				Return
			EndIf
		WEnd
	EndIf

	$search = FileFindFirstFile($alias & "\*.conf")
	If $search <> -1 Then
		While 1
			$file = FileFindNextFile($search)
			If @error Then ExitLoop
			$filename = StringSplit($file, ".")
			If StringLower($filename[1]) = StringLower($value) Then
				MsgBox(16, "Existing Alias", "Alias " & $filename[1] & " already exists")
				Return
			EndIf
		WEnd
	EndIf

	$file_t = $cnf & "\" & $value & ".conf"
	$app_dir = $wbapp & "\" & $value
	ScriptREPLACE($tpl_app, $file_t, "@MYWEBAPP@", $value)
	If DirCreate($app_dir) = 0 Then
		MsgBox(16, "Error", "Cannot create directory " & $app_dir)
		Return
	EndIf

 	$strapp="<H2>Welcome to " & $value & " directory application</H2>"
	$file=FileOpen($wbapp&"\"&$value&"\index.php",2)
	FileWrite ( $file, $strapp )
	FileClose($file)

	MsgBox(64, "Application created", "Application : " & $value & " has been created !" & @CR & "You can customize it here : " & $file_t & @CR & "Application Directory : " & $app_dir & " as been created." & @CR & " You have to put your code here"&@CR&" You must restart Wampserver to use your application")
	Exit
EndFunc   ;==>btn_okClick
Func FormClose()
	Exit
EndFunc   ;==>FormClose
Func FormMaximize()

EndFunc   ;==>FormMaximize

Func ef_appChange()

EndFunc   ;==>ef_appChange
