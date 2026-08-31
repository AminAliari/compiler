@echo off
setlocal
cd /d %1%

set BISON_CMD=bison
set FLEX_CMD=flex

if exist ..\..\vendor\bin\bison\bison.exe set BISON_CMD=..\..\vendor\bin\bison\bison.exe
if exist ..\..\vendor\bin\bison\flex.exe set FLEX_CMD=..\..\vendor\bin\bison\flex.exe

call %BISON_CMD% -o rule.cpp -d -v parser.y -Wno
if errorlevel 1 exit /b 1
call %FLEX_CMD% -o lex.cpp scanner.l
if errorlevel 1 exit /b 1
@exit 0