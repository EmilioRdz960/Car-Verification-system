#include "tipos.h"

extern void capturarAutos(tipoCoches *arr, int tam);
extern void imprimirAutos(tipoCoches *arr, int tam);
extern void verificarAutos(tipoCoches *arr, int tam);
extern void buscarPlaca(tipoCoches *arr, int tam);

int main(int argc, char *argv[])
{
    int n;
    tipoCoches *apCoches;

    // Validar que se haya ingresado el número de autos como argumento
    sscanf(argv[1], "%d", &n); 

    apCoches = (tipoCoches *)malloc(n*sizeof(tipoCoches));
    if(apCoches == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }

    capturarAutos(apCoches, n);
    imprimirAutos(apCoches, n);
    verificarAutos(apCoches, n);
    buscarPlaca(apCoches, n);

    return 0;
}