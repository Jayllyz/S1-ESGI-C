all: PROJET EXCUTION
PROJET: ex1.c
	gcc -o EXEC  ex1.c -Wall
	
EXCUTION: EXEC
	./EXEC
