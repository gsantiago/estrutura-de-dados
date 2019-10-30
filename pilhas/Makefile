all: main.program ex1.program ex2.program ex3.program ex4.program ex5.program ex6.program ex7.program ex8.program ex9.program

# includes
stack.o: stack.c stack.h
	gcc stack.c -c

stack_chars.o: stack_chars.c stack_chars.h
	gcc stack_chars.c -c

# main
main: main.program
	./main.program

main.program: main.o stack.o
	gcc main.o stack.o -o main.program

main.o: main.c stack.h
	gcc main.c -c

# exercícios
ex1: ex1.program
	./ex1.program

ex1.program: ex1.o stack.o
	gcc ex1.o stack.o -o ex1.program

ex1.o: ex1.c stack.h
	gcc ex1.c -c

ex2: ex2.program
	./ex2.program

ex2.program: ex2.o stack.o
	gcc ex2.o stack.o -o ex2.program

ex2.o: ex2.c stack.h
	gcc ex2.c -c

ex3: ex3.program
	./ex3.program

ex3.program: ex3.o stack.o
	gcc ex3.o stack.o -o ex3.program

ex3.o: ex3.c stack.h
	gcc ex3.c -c

ex4: ex4.program
	./ex4.program

ex4.program: ex4.o stack_chars.o
	gcc ex4.o stack_chars.o -o ex4.program

ex4.o: ex4.c stack_chars.h
	gcc ex4.c -c

ex5: ex5.program
	./ex5.program

ex5.program: ex5.o stack_chars.o
	gcc ex5.o stack_chars.o -o ex5.program

ex5.o: ex5.c stack_chars.h
	gcc ex5.c -c

ex6: ex6.program
	./ex6.program

ex6.program: ex6.o stack.o
	gcc ex6.o stack.o -o ex6.program

ex6.o: ex6.c stack.h
	gcc ex6.c -c

ex7: ex7.program
	./ex7.program

ex7.program: ex7.o stack_chars.o
	gcc ex7.o stack_chars.o -o ex7.program

ex7.o: ex7.c stack_chars.h
	gcc ex7.c -c

ex8: ex8.program
	./ex8.program

ex8.program: ex8.o stack_chars.o
	gcc ex8.o stack_chars.o -o ex8.program

ex8.o: ex8.c stack_chars.h
	gcc ex8.c -c

ex9: ex9.program
	./ex9.program

ex9.program: ex9.o stack_chars.o
	gcc ex9.o stack_chars.o -o ex9.program

ex9.o: ex9.c stack_chars.h
	gcc ex9.c -c

# clean
clean:
	rm *.o *.program
