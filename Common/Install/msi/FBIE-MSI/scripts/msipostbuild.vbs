' add custom actions to the msi file
Dim wshShell, filename, scriptsPath, installer, database
filename = WScript.Arguments(0)
scriptsPath = WScript.Arguments(1)

Set installer = CreateObject("WindowsInstaller.Installer")
Set database = installer.OpenDatabase(filename, 1) ' 1 == msiOpenDatabaseModeTransact
Dim sql, view, record

'' **********************************************************************************
'' add action to remove old Inno installed instance
'insert binary data

sql = "INSERT INTO `Binary`(`Name`, `Data`) VALUES ('scriptRemoveOld', ?)"
Set view = database.OpenView(sql)
'create binary data
Set record = installer.CreateRecord(1)
record.SetStream 1, scriptsPath & "removeold.vbs"
view.Execute(record)
view.Close
database.Commit

'insert custom action
sql = "INSERT INTO `CustomAction`(`Action`, `Type`, `Source`, `Target`) VALUES ('actionRemoveOld', 6, 'scriptRemoveOld', '')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'insert custom action execution
sql = "INSERT INTO `InstallExecuteSequence`(`Action`, `Condition`, `Sequence`) VALUES ('actionRemoveOld', 'NOT Installed', 1399)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'' **********************************************************************************
'' add action to remove old shortcuts if any
'insert binary data
sql = "INSERT INTO `Binary`(`Name`, `Data`) VALUES ('scriptRemoveShortcut', ?)"
Set view = database.OpenView(sql)
'create binary data
Set record = installer.CreateRecord(1)
record.SetStream 1, scriptsPath & "removeshortcut.vbs"
view.Execute(record)
view.Close
database.Commit

'insert custom action
sql = "INSERT INTO `CustomAction`(`Action`, `Type`, `Source`, `Target`) VALUES ('actionRemoveShortcut', 6, 'scriptRemoveShortcut', '')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'insert custom action execution
sql = "INSERT INTO `InstallExecuteSequence`(`Action`, `Condition`, `Sequence`) VALUES ('actionRemoveShortcut', 'NOT Installed', 1398)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'' **********************************************************************************
' Add checkbox to the finish dialog
' Fill Control table
sql = "INSERT INTO `Control`(`Dialog_`, `Control`, `Type`, `X`, `Y`, `Width`, `Height`, `Attributes`, `Property`, `Text`) VALUES ('FinishedForm', 'Checkbox1', 'CheckBox', 18, 108, 348, 12, 3, 'LAUNCHIE', '{\VSI_MS_Sans_Serif13.0_0_0}Run Internet Explorer')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' Fill CustomAction table
sql = "INSERT INTO `CustomAction`(`Action`, `Type`, `Source`, `Target`) VALUES ('FinishedForm_SetProperty_CHECKBOX1', 307, 'LAUNCHIE', 1)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' Fill InstallExecuteSequence table
sql = "INSERT INTO `InstallExecuteSequence`(`Action`, `Sequence`) VALUES ('FinishedForm_SetProperty_CHECKBOX1', 701)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' Fill InstallUISequence table
sql = "INSERT INTO `InstallUISequence`(`Action`, `Sequence`) VALUES ('FinishedForm_SetProperty_CHECKBOX1', 701)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' Hide on uninstall
sql = "INSERT INTO `ControlCondition`(`Dialog_`, `Control_`, `Action`, `Condition`) VALUES ('FinishedForm', 'Checkbox1', 'Hide', 'Installed')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'' **********************************************************************************
'' add action to run ie after install
'insert binary data
sql = "INSERT INTO `Binary`(`Name`, `Data`) VALUES ('scriptLaunchIE', ?)"
Set view = database.OpenView(sql)
'create binary data
Set record = installer.CreateRecord(1)
record.SetStream 1, scriptsPath & "launchie.vbs"
view.Execute(record)
view.Close
database.Commit

'insert custom action
sql = "INSERT INTO `CustomAction`(`Action`, `Type`, `Source`, `Target`) VALUES ('actionLaunchIE', 6, 'scriptLaunchIE', '')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'insert custom action execution
sql = "INSERT INTO `ControlEvent`(`Dialog_`, `Control_`, `Event`, `Argument`, `Condition`, `Ordering`) VALUES ('FinishedForm', 'CloseButton', 'DoAction', 'actionLaunchIE', 'NOT Installed AND LAUNCHIE', 1)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit


'' **********************************************************************************
'' add action to kill ie before install
'insert binary data
sql = "INSERT INTO `Binary`(`Name`, `Data`) VALUES ('scriptKillIE', ?)"
Set view = database.OpenView(sql)
'create binary data
Set record = installer.CreateRecord(1)
record.SetStream 1, scriptsPath & "terminateie.vbs"
view.Execute(record)
view.Close
database.Commit

'insert custom action
sql = "INSERT INTO `CustomAction`(`Action`, `Type`, `Source`, `Target`) VALUES ('actionKillIE', 6, 'scriptKillIE', '')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'insert custom action execution
sql = "INSERT INTO `ControlEvent`(`Dialog_`, `Control_`, `Event`, `Argument`, `Condition`, `Ordering`) VALUES ('ConfirmInstallForm', 'NextButton', 'DoAction', 'actionKillIE', 'NOT Installed', 2)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit


'' **********************************************************************************
'' adjust commit custom action to execute under current user, rather local machine
sql = "UPDATE `CustomAction` SET `Type`= 1558 WHERE `Type`= 3606"
'3606 means commit with no personate. 1558 its the same but without no personate, see http://msdn.microsoft.com/en-us/library/aa372048(VS.85).aspx
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'' **********************************************************************************
' insert uninstall shortcut
' all the guids are pointing to the components that are already created in the msi.
sql = "INSERT INTO `Shortcut`(`Shortcut`, `Directory_`, `Name`, `Component_`, `Target`, `Arguments`, `Description`, `Icon_`, `IconIndex`, `ShowCmd`, `WkDir`) VALUES ('_51AB71ACD3B646EAA292EB4A37660379', 'PROGRAMMENUGROUP', 'UNINST~1|Uninstall Facebook IE Toolbar', 'C__123D199A3E5A4A4B87F7D04AFDDCFA40', '[SystemFolder]/msiexec.exe', '/i [ProductCode]', 'Uninstall Facebook IE Toolbar', '_6FEFF9B68218417F98F549.exe', 0, 1, 'SystemFolder')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'' **********************************************************************************
' update the product code
' generate guid
guid = CreateObject("Scriptlet.TypeLib").Guid
guid = left(guid, len(guid) - 2)

sql = "UPDATE `Property` SET `Value` = '" & guid & "' WHERE `Property`='ProductCode'"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'' **********************************************************************************
' Remove repair option from the installer
' Set ARPNOREPAIR property
sql = "INSERT INTO `Property`(`Property`, `Value`) VALUES ('ARPNOREPAIR', 1)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' Set maintenance mode to remove
sql = "UPDATE `Property` SET `Value` = 'Remove' WHERE `Property`='AdminMaintenanceForm_Action'"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

sql = "UPDATE `Property` SET `Value` = 'Remove' WHERE `Property`='MaintenanceForm_Action'"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' Hide Radio group
sql = "UPDATE `Control` SET `Attributes` = 2 WHERE `Dialog_`='MaintenanceForm' AND `Control`='RepairRadioGroup'"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

sql = "UPDATE `Control` SET `Attributes` = 2 WHERE `Dialog_`='AdminMaintenanceForm' AND `Control`='RepairRadioGroup'"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' Change dilog main text
sql = "UPDATE `Control` SET `Text` = '{\VSI_MS_Sans_Serif13.0_0_0}Setup will completely remove [ProductName] and all of its components.' WHERE `Dialog_`='MaintenanceForm' AND `Control`='BodyText'"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

sql = "UPDATE `Control` SET `Text` = '{\VSI_MS_Sans_Serif13.0_0_0}Setup will completely remove [ProductName] and all of its components.' WHERE `Dialog_`='AdminMaintenanceForm' AND `Control`='BodyText'"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

'' **********************************************************************************
' insert all users property
sql = "INSERT INTO `Property`(`Property`, `Value`) VALUES ('ALLUSERS', 1)"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' insert property to use "files in use" dialog
sql = "INSERT INTO `Property`(`Property`, `Value`) VALUES ('MSIRESTARTMANAGERCONTROL', 'Disable')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

' insert property to use "files in use" dialog
sql = "INSERT INTO `Property`(`Property`, `Value`) VALUES ('REBOOT', 'ReallySuppress')"
Set view = database.OpenView(sql)
view.Execute
view.Close
database.Commit

Set database = Nothing
Set installer = Nothing
Set wshShell = Nothing