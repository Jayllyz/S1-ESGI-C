all: PROJET EXCUTION
PROJET: ex4.c
	gcc -o EXEC  ex4.c -Wall
	
EXCUTION: EXEC
	./EXEC
