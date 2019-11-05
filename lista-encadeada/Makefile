main: main.o linked-list.o
	gcc main.o linked-list.o -o main -Wall

main.o: main.c linked-list.h
	gcc main.c -c

linked-list.o: linked-list.c linked-list.h
	gcc linked-list.c -c
