all: EXO1 EXO2 EXO3 EXO4 EXO5 EXO6

EXO1: Exercice1/exo1.c
	gcc -o EXEC Exercice1/exo1.c -Wall
	./EXEC

EXO2: Exercice2/exo2.c
	gcc -o EXEC Exercice2/exo2.c -Wall
	./EXEC

EXO3: Exercice3/exo3.c
	gcc -o EXEC Exercice3/exo3.c -Wall
	./EXEC

EXO4: Exercice4/exo4.c
	gcc -o EXEC Exercice4/exo4.c -Wall
	./EXEC

EXO5: Exercice5/exo5.c
	gcc -o EXEC Exercice5/exo5.c -Wall
	./EXEC

EXO6: Exercice6/exo6.c Exercice6/ez-draw.c
	gcc -Wall Exercice6/exo6.c Exercice6/ez-draw.c -o EXEC -lX11 -lXext -lm
	./EXEC