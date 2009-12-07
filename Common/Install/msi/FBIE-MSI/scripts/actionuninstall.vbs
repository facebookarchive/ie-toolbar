'' unregister the .exe and close all instances
Dim curDir, wshShell
On Error Resume Next
curDir = Session.Property("CustomActionData")

' start FBClientService.exe with register parameter
Set wshShell = CreateObject ("WScript.Shell")
If Not wshShell Is Nothing Then
wshShell.Run("""" + curDir + "FBClientService.exe""" + " -unregister")
End If