g++ cbuild.cpp -o cbuild
./cbuild
rm src/*.pro > /dev/null 2>&1
rm src/Makefile > /dev/null 2>&1

windres app_icon.rc -O coff -o app_icon.res
g++ main.cpp app_icon.res -o MyApp.exe