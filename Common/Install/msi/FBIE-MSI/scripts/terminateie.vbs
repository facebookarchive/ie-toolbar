'' force all IE to quit at finish
On Error Resume Next
strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")
Set colProcessList = objWMIService.ExecQuery _
    ("SELECT * FROM Win32_Process WHERE Name = 'iexplore.exe'")
For Each objProcess in colProcessList
    objProcess.Terminate()
Next