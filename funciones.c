#include "tipos.h"


/**
 *  @brief Función para buscar un auto por su placa
 *  @param arr Arreglo de tipoCoches que contiene los datos de los autos
 * @param tam Tamaño del arreglo de autos
 * @return void
 *  @details Esta función solicita al usuario ingresar una placa y busca en el arreglo de autos para encontrar un auto que coincida con esa placa. Si encuentra una coincidencia, muestra los datos del auto. Si no encuentra ninguna coincidencia, muestra un mensaje indicando que el vehículo no está catalogado.
 */
extern void buscarPlaca(tipoCoches *arr, int tam)
{
    int i;
    char busquedaPlaca[15];
    int validacionPlaca = 0;

    printf("\nIngrese la placa para buscar datos del auto: ");
    scanf("%s", busquedaPlaca);
    
    for(i = 0; i < tam; i++)
    {
        if(strcmp(busquedaPlaca, arr[i].Placa) == 0)
        {
            printf("\nDatos del vehiculo: \n");
            printf("%s\t%s\t%s\t%d\n ", arr[i].Marca, arr[i].Modelo, arr[i].Placa, arr[i].Anio);
        }
        else
            validacionPlaca++;
    }

    if(validacionPlaca == tam)
        printf("\nEl vehiculo no está catalogado.\n");

    return;
}


/**
 *  @brief Función para verificar los autos
 *  @param arr Arreglo de tipoCoches que contiene los datos de los autos
 *  @param tam Tamaño del arreglo de autos
 *  @return void
 *  @details Esta función verifica los autos en función del último dígito de su placa y muestra la temporada de verificación correspondiente.
 */
extern void verificarAutos(tipoCoches *arr, int tam)
{   
    int i;
    char digito;
    int numDigito;

        printf("\n[Verificación]\n");

        for(i = 0; i < tam; i++)
        {
            digito = arr[i].Placa[5]; // 5 es el último digito de la cadena
            numDigito = digito - '0';

            if(numDigito == 5 || numDigito == 6)
            {
                printf("\nEl %s %s con placa: %s se debe verificar entre Julio y Agosto\n", arr[i].Marca, arr[i].Modelo, arr[i].Placa);
            }
            else if(numDigito == 7 || numDigito == 8)
            {
                printf("\nEl %s %s con placa: %s se debe verificar entre Agosto y Septiembre\n", arr[i].Marca, arr[i].Modelo, arr[i].Placa);
            }
            else if(numDigito == 3 || numDigito == 4)
            {
                printf("\nEl %s %s con placa: %s se debe verificar entre Septiembre y Octubre\n", arr[i].Marca, arr[i].Modelo, arr[i].Placa);
            }
            else if(numDigito == 1 || numDigito == 2)
            {
                printf("\nEl %s %s con placa: %s se debe verificar entre Octubre y Noviembre\n", arr[i].Marca, arr[i].Modelo, arr[i].Placa);
            }
            else if(numDigito == 9 || numDigito == 0)
            {
                printf("\nEl %s %s con placa: %s se debe verificar entre Noviembre y Diciembre\n", arr[i].Marca, arr[i].Modelo, arr[i].Placa);
            }

        }

    return;
}

/**
 *  @brief Función para imprimir los autos
 *  @param arr Arreglo de tipoCoches que contiene los datos de los autos
 *  @param tam Tamaño del arreglo de autos
 *  @return void
 *  @details Esta función lee los datos de los autos desde el archivo "autos.txt" y los imprime en la consola.
 */
extern void imprimirAutos(tipoCoches *arr, int tam)
{
    int i;
    FILE *fp;
    char MarcaArr[15];
    char ModeloArr[15];
    char PlacasArr[15];
    int AnioArr;

    fp = fopen("autos.txt", "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    while(fscanf(fp,"%s\t%s\t%s\t%d\n", MarcaArr, ModeloArr, PlacasArr, &AnioArr) == 4 )
    {
        printf("\n%s\t%s\t%s\t%d\n ", MarcaArr, ModeloArr, PlacasArr, AnioArr);
    }


    return;
}

/**
 *  @brief Función para capturar los datos de los autos
 *  @param arr Arreglo de tipoCoches que contiene los datos de los autos
 *  @param tam Tamaño del arreglo de autos
 *  @return void
 *  @details Esta función solicita al usuario ingresar los datos de los autos y los almacena en el arreglo.
 */
extern void capturarAutos(tipoCoches *arr, int tam)
{
    int i;
    FILE *fp;

    fp = fopen("autos.txt", "w"); //Abre el archivo en modo escritura
    if(fp == NULL) //Verifica la disponibilidad del archivo
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }

    for(i = 0; i < tam; i++)
    {  
        printf("\nRegistro[%d]\n", i+1);
        printf("\nIngrese la marca de su vehiculo: ");
        scanf("%s", arr[i].Marca);
        printf("\nIngrese el modelo de su vehiculo: ");
        scanf("%s", arr[i].Modelo);
        printf("\nIngrese las placas de su vehiculo: ");
        scanf("%s", arr[i].Placa);
        printf("\nIngrese el anio de su vehiculo: ");
        scanf("%d", &arr[i].Anio);

        fprintf(fp,"%s\t%s\t%s\t%d\n", arr[i].Marca, arr[i].Modelo, arr[i].Placa, arr[i].Anio);
    }
 
    fclose(fp);

    return;
}