all: PROJET EXCUTION
PROJET: ex2.c
	gcc -o EXEC  ex2.c -Wall
	
EXCUTION: EXEC
	./EXEC
