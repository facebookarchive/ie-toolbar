'' force all IE to quit at finish
'' moved to the installation start
'strComputer = "."
'Set objWMIService = GetObject("winmgmts:" _
'   & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")
'Set colProcessList = objWMIService.ExecQuery _
'    ("SELECT * FROM Win32_Process WHERE Name = 'iexplore.exe'")
'For Each objProcess in colProcessList
'    objProcess.Terminate()
'Next

Dim webBrowser
' Run Browser
Set webBrowser = CreateObject("InternetExplorer.Application")
If Not webBrowser Is Nothing Then
  ' open web browser
  webBrowser.navigate "http://www.facebook.com/"
  webBrowser.visible = true
  ' Free object
  'Set webBrowser = Nothing
End If