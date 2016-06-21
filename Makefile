CC = g++
CFLAGS = -Wall -g -std=c++11

all: map

map.o: defs.h includes.h map_exer.cc 
	${CC} ${CFLAGS} -c map_exer.cc

map: map.o
	${CC} ${CFLAGS} map_exer.o -o map_exercise

run:
	make all && echo && ./map_exercise < input

clean:
	rm -rf *.o
	rm -rf map_exercise
