#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "funciones_buscaminas.h"

int main() {
    time_t t;
    srand((unsigned) time(&t));
    int matriz_valores[90][90];
    int matriz_visual[90][90];
    int col, filas, bombas,i,j, clickeado;
//    scanf("%d %d %d", &col, &filas, &bombas);
col=6;
filas=6;
bombas=2;
    inicializa(matriz_valores, col, filas);
    inicializa(matriz_visual, col, filas);
    generar_bombas(matriz_valores,col,filas,bombas);
    generar_numeros(matriz_valores, col, filas);
    do{
        system("CLS");

        muestra(matriz_valores,col,filas);
        muestra(matriz_visual,col,filas);

        printf("\nIngrese coordenadas:");
        scanf("%d %d", &i, &j);

        click(matriz_visual, matriz_valores, col,filas, i,j);


    }while (termino(matriz_visual, col, filas, bombas));
    return 0;
}

