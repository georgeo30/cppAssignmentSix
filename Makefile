CC=g++
LIB=-std=c++11
create: State.h State.cpp driver.cpp
	$(CC) $(LIB) State.h State.cpp driver.cpp -c
	$(CC) $(LIB) driver.o State.o -o rl

 

clean:
	rm State.o
	rm driver.o
	rm State.h.gch
	rm rl
