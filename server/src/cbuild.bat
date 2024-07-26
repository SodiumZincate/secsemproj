g++ database.cpp -o database -lsqlite3 -lws2_32
.\database.exe

g++ -o main.o -c main.cpp -lsqlite3 -lws2_32
g++ -o main main.o -lsqlite3 -lws2_32
.\main.exe