cd  %1%
call ..\..\vendor\bin\bison\bison.exe -o rule.cpp -d -v parser.y -Wno
call ..\..\vendor\bin\bison\flex.exe -o lex.cpp scanner.l
@exit 0