OPTIONS=  -std=c99 -g -lm -lgmp

OPTIONS+= $(WARNINGS)
OPTIONS+= $(MACROS)
NGenerator : NGenerator.o premier.o
	gcc -o NGenerator NGenerator.o premier.o $(OPTIONS)

premier.o : premier.c premier.h
	gcc -c premier.c $(OPTIONS)

NGenerator.o : premier.o
	gcc -c NGenerator.c $(OPTIONS)

all : NGenerator


clean :
	rm *.o -fv *~

cleanall : clean
	rm NGenerator -f

