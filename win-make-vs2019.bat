@echo off
if exist vendor\bin\premake\windows\premake5.exe (
	call vendor\bin\premake\windows\premake5.exe vs2019
) else if exist vendor\bin\premake\mac\premake5 (
	call vendor\bin\premake\mac\premake5 vs2019
) else (
	echo premake5 was not found in vendor/bin/premake.
	exit /b 1
)
PAUSE