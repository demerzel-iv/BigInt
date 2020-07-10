CompOpt = g++ -O2 -std=c++11
objects = bigint.o

main: $(objects) main.cpp 
	$(CompOpt) $(objects) main.cpp -o main

bigint.o: bigint.h 
