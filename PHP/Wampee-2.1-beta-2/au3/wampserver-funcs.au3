#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.5.6 (beta)
 Author:         Herve Leclerc

 Script Function:
	Template AutoIt script.

#ce ----------------------------------------------------------------------------

; Script Start
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
