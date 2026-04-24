#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct coches
{
    char Marca[15];
    char Modelo[15];
    char Placa[15];
    int Anio;
};

typedef struct coches tipoCoches;