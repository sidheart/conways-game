CFLAGS = -Wall -std=c++11
all: main.o cgol.o
	g++ $(CFLAGS) main.o cgol.o -o cgol -lncurses
main.o: main.cpp cgol.h
	g++ $(CFLAGS) -c main.cpp
cgol.o: cgol.cpp cgol.h
	g++ $(CFLAGS) -c cgol.cpp
clean:
	rm -f *~ *.o cgol
