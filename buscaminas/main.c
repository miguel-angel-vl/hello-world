#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "funciones_buscaminas.h"

int main() {
    time_t t;
    srand((unsigned) time(&t));
    int matriz_valores[90][90];
    int matriz_visual[90][90];
    int col, filas, bombas,i,j;

    printf("******************BUSCAMINAS******************\n\n");

    do{
        printf("Ingrese cantidad de filas: ");
        scanf("%d", &filas);

        if(filas <= 0){
            printf("N%cmero de filas no puede ser menor o igual a cero.\n", 163);
        }
    }while(filas <= 0);

    do{
        printf("Ingrese cantidad de columnas: ");
        scanf("%d", &col);
        if(col <= 0){
            printf("N%cmero de columnas no puede ser menor o igual a cero.\n", 163);
        }
    }while(col <= 0);

    do{
        printf("Ingrese cantidad de bombas: ");
        scanf("%d", &bombas);

        if(bombas > filas*col){
            printf("\nNo pueden haber m%cs de %d bombas en la matriz\n\n", 160, filas*col);
        }
    }while(bombas > filas*col);

    inicializa(matriz_valores, filas, col);
    inicializa(matriz_visual, filas, col);
    generar_bombas(matriz_valores, filas, col, bombas);
    generar_numeros(matriz_valores, filas, col);

    do{
        system("CLS");

        //muestra(matriz_valores, filas, col);
        //printf("-------------------\n");
        muestra(matriz_visual, filas, col);

        printf("\nIngrese coordenadas[x, y]: ");
        scanf("%d, %d", &i, &j);

        click(matriz_visual, matriz_valores, filas, col, i,j);

        if(gano(matriz_visual, filas, col, bombas) == 1){
            system("cls");
            muestra(matriz_valores, filas, col);
            printf("\nGANASTE!!!\n");
            return 0;
        }
    }while (termino(matriz_visual, filas, col, bombas) == 1);

    system("cls");
    muestra(matriz_valores,filas,col);
    printf("\nBOOOOM!!! PERDISTE\n");

    return 0;
}
