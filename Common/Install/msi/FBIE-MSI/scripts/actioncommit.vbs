Dim curDir, wshShell, regPath, regUninstallPath, regUninstallPathSilent
On Error Resume Next
Set wshShell = CreateObject ("WScript.Shell")
curDir = Session.Property("CustomActionData")

Sub RegDeleteEntry(regPath)
	Err.Clear
	regUninstallPath = wshShell.RegRead(regPath)
	'Check whether there is such registry path
	If Err.Number = 0 Then
			wshShell.RegDelete regPath
	End If
End Sub

'force IE to reload sidebars and toolbars
RegDeleteEntry "HKCR\Component Categories\{00021493-0000-0000-C000-000000000046}\Enum\"
RegDeleteEntry "HKCR\Component Categories\{00021494-0000-0000-C000-000000000046}\Enum\"'

RegDeleteEntry "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Discardable\PostSetup\Component Categories\{00021493-0000-0000-C000-000000000046}\Enum\"
RegDeleteEntry "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Discardable\PostSetup\Component Categories\{00021494-0000-0000-C000-000000000046}\Enum\"

'' if there was previous version - unregister it and close all instances
Dim fso
Set fso = CreateObject("Scripting.FileSystemObject")
If fso.FileExists("""" + curDir + "FBClientService.exe""") Then
  If Not wshShell Is Nothing Then
  	wshShell.Run """" & curDir & "FBClientService.exe""" & " -closeall", 0, True	
    wshShell.Run """" & curDir & "FBClientService.exe""" & " -unregister", 0, True
  End If
End If

Set fso = Nothing

'' Display toolbar with IE
' Get the WebBrowser object
Dim webBrowser, vDump
Set webBrowser = CreateObject("InternetExplorer.Application")
If Not webBrowser Is Nothing Then
  ' open the web browser with our toolbar
  webBrowser.ShowBrowserBar "{A823A630-78C6-4637-AF80-AEDCA5BB74C1}", True, vDump
  ' Free object again
  webBrowser.Quit()
  Set webBrowser = Nothing
End If

' start FBClientService.exe with register parameter
If Not wshShell Is Nothing Then
  wshShell.Run """" & curDir & "FBClientService.exe""" & " -register", 0, True
End If

Set wshShell = Nothing