all: geom tip

clear:
	rm -f geom tip *.o

geom: geom.o get_double.o
	gcc geom.o get_double.o -o geom -l m

geom.o: geom.c get_double.h
	gcc geom.c -c

get_double.o: get_double.c get_double.h
	gcc get_double.c -c

tip: tip.o get_double.o
	gcc tip.o get_double.o -o tip

tip.o: tip.c get_double.h
	gcc tip.c -c
