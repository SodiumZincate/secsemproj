exec > app.log
set -e

make
./app/loginpage
rm *.o