CompOpt = g++ -O2 -std=c++11 
ObjCompOpt = g++ -O2 -std=c++11 -c
#LibOpt = -L. -lpoly 

objects = bigint.o 



main: $(objects) main.cpp  
#ifeq ($(shell uname), Linux)
#	$(CompOpt) $(objects) main.cpp -o main $(LibOpt) -static
#else
#ifeq ($(shell uname), Darwin)
#	$(CompOpt) $(objects) main.cpp -o main $(LibOpt) 
#endif
#endif
	$(CompOpt) $(objects) main.cpp -o main

staticlib: $(objects)
	ar -crv libBigInt.a $(objects)

#libpoly.a:
#	make -C ./poly staticlib
#	mv ./poly/libpoly.a ./

bigint.o: bigint.cpp bigint.h 
	$(CompOpt) $< -o $@ -c

clean:
	rm *.o