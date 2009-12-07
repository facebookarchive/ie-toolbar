Dim curDir, wshShell
On Error Resume Next
'The path ("[TARGETDIR]") is being passed by the installer 
'in the one available parameter: CustomActionData

curDir = Session.Property("CustomActionData")
Set wshShell = CreateObject ("WScript.Shell")

If Not wshShell Is Nothing Then
  wshShell.Run """" & curDir & "FBClientService.exe""" & " -register", 0, True
End If

Set wshShell = Nothing




