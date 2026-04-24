autos.exe: autos.o funciones.o
	gcc autos.o funciones.o -o autos.exe

autos.o: autos.c tipos.h
	gcc -c autos.c

funciones.o: funciones.c tipos.h
	gcc -c funciones.c