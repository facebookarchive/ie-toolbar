'' Uninstall old Inno Setup installed instance 
Dim wshShell, regPath, objShell, objFolder, objFolderItem
Set wshShell = CreateObject("Shell.Application")
Set objFolder = wshShell.Namespace(23) ' 22 - Start Menu Programs for all users
Set objFolderItem = objFolder.Self     


Dim fso
Set fso = CreateObject("Scripting.FileSystemObject")
if fso.FolderExists(objFolderItem.Path + "\Facebook IE Toolbar") Then
	fso.DeleteFolder(objFolderItem.Path + "\Facebook IE Toolbar")
End If
Set fso = Nothing
Set wshShell = Nothing