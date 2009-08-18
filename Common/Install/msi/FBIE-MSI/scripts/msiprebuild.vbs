set a = wscript.arguments
if a.count = 0 then wscript.quit 1

' Read Setup project file
Set fileObject = CreateObject("Scripting.FileSystemObject")
Set file = fileObject.OpenTextFile(a(0))
stream = file.ReadAll
'file.Close

set reg = new regexp
reg.global = true

' Increment MSI version number
reg.pattern = "(""ProductVersion"" = ""8:)(\d+(\.\d+)+)"""
set matches = reg.execute(stream)
version = matches(0).submatches(1)
versionBuild = split(version, ".")
versionBuild(ubound(versionBuild)) = versionBuild(ubound(versionBuild)) + 1
versionNew = join(versionBuild, ".")

stream = reg.replace(stream, "$1" & versionNew & """")

' Replace MSI product code
reg.pattern = "(""ProductCode"" = ""8:)(\{.+\})"""
guid = CreateObject("Scriptlet.TypeLib").Guid
guid = left(guid, len(guid) - 2)

stream = reg.replace(stream, "$1" & guid & """")

' Write Setup project file
set file = fileObject.CreateTextfile(a(0), true)
file.Write(stream)
file.close
