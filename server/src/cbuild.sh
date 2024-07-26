./database

g++ -o main.o -c main.cpp -lsqlite3
g++ -o main main.o -lsqlite3
./main