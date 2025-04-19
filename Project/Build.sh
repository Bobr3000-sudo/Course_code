g++ main.cpp character.cpp map.cpp end.cpp start.cpp clear.cpp -o main -lncurses -pg
./main
gprof test gmon.out > analysis.txt
clear
