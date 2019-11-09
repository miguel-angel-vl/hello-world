#include <stdio.h>
#include <stdlib.h>

#include "funcionesasig7.h"

int main()
{
    int **mat, orden, ind;

    srand(time(NULL));

    printf("Ingrese orden de la matriz: ");
    scanf("%d", &orden);

    mat = (int *)malloc(orden*sizeof(int));

    for(ind = 0; ind < orden; ind++){
        mat[ind] = (int*)malloc(orden*sizeof(int));
    }

    generarmatriz(mat, orden);

    if(simetrica(mat, orden) == 1){
        printf("\nLa matriz ES sim%ctrica\n", 130);
    }else{
        printf("\nLa matriz NO es sim%ctrica\n", 130);
    }

    return 0;
}
