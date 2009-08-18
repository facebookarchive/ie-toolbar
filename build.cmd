rem ---------------------------------------------------------
rem ------------  VS2008  CONFIGURATION  --------------------
rem ---------------------------------------------------------
rem set path to VS2008 directory; example: D:\VS2008

set VS2008="c:\Program Files\Microsoft Visual Studio 9.0"

rem set VS2008 environment variables
call %VS2008%\Common7\Tools\vsvars32.bat

rem ---------------------------------------------------------
rem ------------   ANT CONFIGURATION  -----------------------
rem ---------------------------------------------------------

rem set path to ANT

set ANT_PATH=c:\Programs\apache-ant-1.7.1

call %ANT_PATH%\bin\ant 