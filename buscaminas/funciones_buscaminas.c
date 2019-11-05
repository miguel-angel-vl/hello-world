#include "funciones_buscaminas.h"

int generar_bombas(int matriz[90][90], int n, int m, int bomba){
    int aleatorio_i, aleatorio_j;
    while (bomba>0){
        aleatorio_i = rand() % n;
        aleatorio_j = rand() % m;
        if (matriz[aleatorio_i][aleatorio_j]!='b'){
            matriz[aleatorio_i][aleatorio_j]='b';
            bomba--;
        }
    }
}

int generar_numeros(int matriz[90][90], int n, int m){
    int i, j;
    for ( i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (matriz[i][j] == '#'){
                matriz[i][j]=0;
            }
            if (matriz[i][j] == 'b'){
                // Tengo que sumarle uno a todos los valores alrededor que no sean 'b'
                sumar_uno(matriz, n, m, i+1, j);
                sumar_uno(matriz, n, m, i+1, j+1);
                sumar_uno(matriz, n, m, i+1, j-1);
                sumar_uno(matriz, n, m, i-1, j);
                sumar_uno(matriz, n, m, i-1, j+1);
                sumar_uno(matriz, n, m, i-1, j-1);
                sumar_uno(matriz, n, m, i, j+1);
                sumar_uno(matriz, n, m, i, j-1);
            }
        }
    }
}

void sumar_uno(int matriz[90][90], int n, int m, int i, int j){
    if (i<0||j<0||i>=n||j>=m||matriz[i][j]=='b') return;
    if (matriz[i][j] == '#'){
        matriz[i][j]=0;
    }
    matriz[i][j]++;
}

int muestra(int matriz[90][90], int n, int m){

    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if(matriz[i][j] == 'b' || matriz[i][j] == '#' || matriz[i][j] == 0){
                printf("%c",matriz[i][j]);
            }else{
                printf("%d",matriz[i][j]);
            }
        }
        printf("\n");
    }
}


int inicializa(int matriz[90][90], int n, int m){
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            matriz[i][j]='#';
        }
    }
}

int termino(int matriz[90][90], int n, int m, int bombas){

    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j< m; j++){
            if (matriz[i][j] == 'b'){
                return 0;
            }
        }
    }
    return 1;
}

int gano(int matriz[90][90], int n, int m, int bombas){

    int i, j, cont = 0;

    for(i = 0; i < n; i++){
        for(j = 0; j< m; j++){
            if (matriz[i][j] == '#'){
                cont++;
            }
        }
    }
    if(cont == bombas){
        return 1;
    }else{
        return 0;
    }
}

void click(int matriz_visual[90][90], int matriz_valores[90][90], int n, int m, int i, int j){

    if(i >= n || j >= m || i < 0 || j < 0 ){
        return;
    }

    if (matriz_visual[i][j] != '#') {
        return;
    }

    matriz_visual[i][j] = matriz_valores[i][j];

    if(matriz_visual[i][j] != '#' || matriz_valores[i][j] == 'b' ){
        if(matriz_valores[i][j] == 'b' ){
            return;
        }else{
            if(matriz_valores[i][j] >= 0 && matriz_valores[i][j] <=9){

                matriz_visual[i][j] = matriz_valores[i][j];

                if(matriz_valores[i][j] != 0){
                    return;
                }

                click(matriz_visual, matriz_valores, n, m, i+1, j);
                click(matriz_visual, matriz_valores, n, m, i+1, j+1);
                click(matriz_visual, matriz_valores, n, m, i+1, j-1);
                click(matriz_visual, matriz_valores, n, m, i-1, j);
                click(matriz_visual, matriz_valores, n, m, i-1, j+1);
                click(matriz_visual, matriz_valores, n, m, i-1, j-1);
                click(matriz_visual, matriz_valores, n, m, i, j+1);
                click(matriz_visual, matriz_valores, n, m, i, j-1);

                return;
            }
        }
    }
}

