OPTIONS= -O3 -std=c99 -g -lm -lgmp
WARNINGS= -Wall -pedantic -Wextra
OPTIONS+= $(WARNINGS)
OPTIONS+= $(MACROS)
NGenerator : NGenerator.o fonctions.o
	gcc -o NGenerator NGenerator.o fonctions.o $(OPTIONS)

fonctions.o : fonctions.c fonctions.h
	gcc -c fonctions.c $(OPTIONS)

NGenerator.o : fonctions.o
	gcc -c NGenerator.c $(OPTIONS)

all : NGenerator


clean :
	rm *.o -fv *~

cleanall : clean
	rm NGenerator -f

