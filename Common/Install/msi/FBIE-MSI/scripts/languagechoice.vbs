' Svae language setting to the registry
Dim curLang, wshShell

On Error Resume Next
Set wshShell = CreateObject ("WScript.Shell")
curLang = Session.Property("CustomActionData")

wshShell.RegWrite "HKEY_CURRENT_USER\Software\AppDataLow\Software\Facebook\IEToolbar\currentCultureId", curLang, "REG_SZ"

Set wshShell = Nothing