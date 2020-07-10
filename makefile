CompOpt = g++ -O2 -std=c++11 
ObjCompOpt = g++ -O2 -std=c++11 -c
LibOpt = -L. -lpoly -static

objects = bigint.o 

main: libpoly.a $(objects) main.cpp 
	$(CompOpt) $(objects) main.cpp -o main $(LibOpt)

bigint.o: bigint.cpp bigint.h 
	$(CompOpt) $< -o $@ -c $(LibOpt)

clean:
	rm *.o