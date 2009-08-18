'' Uninstall old Inno Setup installed instance 
Dim wshShell, regPath, regUninstallPath, regUninstallPathSilent
Set wshShell = CreateObject ("WScript.Shell")

regPath = "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{C0916BB5-0AC5-4BB1-A6EA-CEC8DF595B77}_is1\"

Err.Clear

On Error Resume Next
regUninstallPath = wshShell.RegRead(regPath + "UninstallString")
'Check whether there is such registry path
If Err.Number = 0 Then
	' check whether the uninstall path exists
	If wshShell.FileExists(regUninstallPath) Then
		regUninstallPathSilent = wshShell.RegRead(regPath + "QuietUninstallString")
		' run uninstall
		wshShell.Run regUninstallPathSilent, 0, true
	Else
		' just delete the registry entry
		wshShell.RegDelete regPath
	End If
End If
Set wshShell = Nothing