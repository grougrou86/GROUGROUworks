#RequireAdmin
#NoTrayIcon
#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_icon=wampserver.ico
#AutoIt3Wrapper_outfile=WampeeSrv.exe
#AutoIt3Wrapper_UseX64=n
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****
#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.5.6 (beta)
 Author:         Herve Leclerc (herve.leclerc@alterway.fr)

 Script Function:
	Wampee Start Stop

#ce ----------------------------------------------------------------------------
#include <file.au3>
#include <Constants.au3>

Global $DriveLetter = StringLeft(@ScriptDir, 2)
$Root  = _PathFull(@ScriptDir & "\..")
$RootA =StringReplace($Root, "\", "/")
$Inifile = _PathFull($Root&"\resources\wampee.ini")

Global $Apache_version = IniRead($Inifile, "wampserver", "apache_version", "")
Global $Mysql_version  = IniRead($Inifile, "wampserver", "mysql_version", "")

If $CmdLine[0] <> 2 Then
	ConsoleWrite("Usage : WampeeSrv [start|stop|restart] [all|apache|mysql]")
	Exit
EndIf
If $CmdLine[2] <> "apache" And $CmdLine[2] <> "mysql" And $CmdLine[2] <> "all" Then
	ConsoleWrite("Usage : WampeeSrv [start|stop|restart] [all|apache|mysql]")
	Exit
EndIf
Select
    Case $CmdLine[1] = "start"
        Wampee_start_servers($CmdLine[2])
	Case $CmdLine[1] = "stop"
        Wampee_stop_servers($CmdLine[2])
	Case $CmdLine[1] = "restart"
		Wampee_stop_servers($CmdLine[2])
		Wampee_start_servers($CmdLine[2])
    Case Else
        ConsoleWrite("Usage : WampeeSrv [start|stop|restart] [all|apache|mysql]")
		Exit
EndSelect

Func Wampee_start_servers($param)
	If $param = "apache" Or $param = "all" Then
		Local $apachepath = $Root  & "\bin\apache\Apache" & $Apache_version & "\bin\wampeehttpd.exe"               ;Apache executable
		Local $apacheconf = $RootA & "/bin/apache/Apache" & $Apache_version & "/conf/httpd.conf"          ;Apache configuration file
		Local $apacheroot = $RootA & "/bin/apache/Apache" & $Apache_version                               ;Apache root folder
		Local $apache      = $apachepath & " -f " & $apacheconf & " -d " & $apacheroot ;Apache start string

		; run Apache server. select w:, change directory to php required to pick-up libmysql.dll
		Run(@ComSpec & " /c " & $DriveLetter & " & " & $apache,"", @SW_HIDE )

		; wait for Apache to run
		While Not ProcessExists("wampeehttpd.exe");wait for process to run
			Sleep(100)                       ;periodically check
		WEnd
		ConsoleWrite("Wampee_start_servers: Apache Started"&@LF);
    EndIf

	If $param = "mysql" Or $param = "all" Then
		Local $mysql_path = $Root  & "\bin\mysql\mysql"& $Mysql_version &"\bin\wampeemysqld.exe"              ; path to executable
		Local $mysql_conf =" --defaults-file=" & $RootA & "/bin/mysql/mysql"& $Mysql_version & "/my.ini" ; Mysql config file
		Run(@ComSpec & " /c " & $DriveLetter & " & " & $mysql_path & $mysql_conf ,"", @SW_HIDE )
		ConsoleWrite("Wampee_start_servers: Mysql Started");
	EndIf
EndFunc

Func Wampee_stop_servers($param)

	If $param = "apache" Or $param="all" Then
		While ProcessExists("wampeehttpd.exe") ; wait for all Apache processs to close
			ProcessClose  ("wampeehttpd.exe")  ; kill named process
			Sleep(100)                   ; give process chance to close
		WEnd
		ConsoleWrite("Wampee_stop_servers: Apache Stopped"&@LF);
	EndIf

    If $param = "mysql" Or $param = "all" Then
		ProcessClose ("wampeemysqld.exe")
		ConsoleWrite("Wampee_stop_servers: MySQL Stopped")
	EndIf
EndFunc ;