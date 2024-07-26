g++ -o database.o -c database.cpp -lsqlite3
g++ -o database.o database.cpp -lsqlite3
./database

g++ -o main.o -c main.cpp -lsqlite3
g++ -o main main.o -lsqlite3
./main