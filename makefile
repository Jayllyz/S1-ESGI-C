all: PROJET EXCUTION
PROJET: ex3.c
	gcc -o EXEC  ex3.c -Wall
	
EXCUTION: EXEC
	./EXEC
