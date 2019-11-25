#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones9.h"

#define NOMARCH "estudiante.dat"

#define ESC 27


int main()
{
    FILE *archestud;
    ESTUDIANTE *estud;
    int ind;

    estud = (ESTUDIANTE *)malloc(2*sizeof(ESTUDIANTE));

    //estud = cargarEstudiantes(NOMARCH);
    //fflush(stdin);
    estud = agregarEstudiante(estud, 2);

    //archestud = fopen("estudiante.dat", "ab");
    estud = guardarEstudiantes(estud, 2, archestud);

    //fclose(archestud);

    free(estud);

    return 0;
}

