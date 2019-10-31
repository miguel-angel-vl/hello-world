#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int muestra(int matriz[90][90], int n, int m);
int inicializa(int matriz[90][90], int n, int m);
int gano(int matriz[90][90], int n, int m, int bombas);
int termino(int matriz[90][90], int n, int m, int bombas);
int click(int matriz_visual[90][90], int matriz_valores[90][90], int n, int m, int i, int j);
void explosion(int matriz_valores[90][90], int matriz_visual[90][90], int matriz_visitados[90][90], int n, int m, int i, int j);
int generar_bombas(int matriz[90][90], int n, int m, int bomba);
int generar_numeros(int matriz[90][90], int n, int m);
void sumar_uno(int matriz[90][90], int n, int m, int i, int j);

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

        if(click(matriz_visual, matriz_valores, col,filas, i,j)){
            printf("\n\nSe acabo\n");
            break;
        }


    }while (termino(matriz_visual, col, filas, bombas) || click(matriz_visual, matriz_valores, col,filas, i,j) != 0);
    return 0;
}

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
            printf("%c",matriz[i][j]);
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
int click(int matriz_visual[90][90], int matriz_valores[90][90], int n, int m, int i, int j){

    int temp;

    if(matriz_valores[i][j] == 'b'){
        return 0;
    }else{
        matriz_visual[i][j] = matriz_valores[i][j];

        if(matriz_valores[i+1][j]){
            return click(matriz_visual, matriz_valores, n, m, i+1, j);
        }
        if(matriz_valores[i+1][j+1]){
            return click(matriz_visual, matriz_valores, n, m, i+1, j+1);
        }
        if(matriz_valores[i+1][j-1]){
            return click(matriz_visual, matriz_valores, n, m, i+1, j-1);
        }
        if(matriz_valores[i-1][j]){
            return click(matriz_visual, matriz_valores, n, m, i-1, j);
        }
        if(matriz_valores[i-1][j+1]){
            return click(matriz_visual, matriz_valores, n, m, i-1, j+1);
        }
        if(matriz_valores[i-1][j-1]){
            return click(matriz_visual, matriz_valores, n, m, i-1, j-1);
        }
        if(matriz_valores[i][j+1]){
            return click(matriz_visual, matriz_valores, n, m, i, j+1);
        }
        if(matriz_valores[i][j-1]){
            return click(matriz_visual, matriz_valores, n, m, i, j-1);
        }
    }
}
