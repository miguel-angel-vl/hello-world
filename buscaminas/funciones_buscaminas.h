#ifndef FUNCIONES_BUSCAMINAS_H

int muestra(int matriz[90][90], int n, int m);
int inicializa(int matriz[90][90], int n, int m);
int gano(int matriz[90][90], int n, int m, int bombas);
int termino(int matriz[90][90], int n, int m, int bombas);
void click(int matriz_visual[90][90], int matriz_valores[90][90], int n, int m, int i, int j);
void explosion(int matriz_valores[90][90], int matriz_visual[90][90], int matriz_visitados[90][90], int n, int m, int i, int j);
int generar_bombas(int matriz[90][90], int n, int m, int bomba);
int generar_numeros(int matriz[90][90], int n, int m);
void sumar_uno(int matriz[90][90], int n, int m, int i, int j);

#endif // FUNCIONES_BUSCAMINAS_H
