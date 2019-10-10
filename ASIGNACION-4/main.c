#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mayoract(int, int);
int menoract(int, int);
int sumatoria (int, int);
float media (int, int);
float desv ();

int main()
{
    int cant, num, mayor, menor, i, suma = 0, n;
    float mediarit, sumelevado, desviacion;

    n = cant;

    printf("Digite la cantidad de datos a ingresar: ");
    scanf("%d", &cant);

    for ( i = 1; i <= cant; i++){
        printf("Ingrese n%cmero: ", 163);
        scanf("%d", &num);

        if (i == 1){
            mayor = num;
            menor = num;
        }
        else{
            if (mayoract(mayor, num) == 1){
                mayor = num;
            }
            if (menoract(menor, num) == 1){
                menor = num;
            }
        }

        desviacion = desv(num, cant);

        suma = sumatoria(suma, num);

    }

    mediarit = media(suma, cant);

    printf("\nEl mayor es: %d\n", mayor);
    printf("\nEl menor es: %d\n", menor);
    printf("\nLa suma de los datos de entrada es: %d\n", suma);
    printf("\nLa media es: %.3f\n", mediarit);

    return 0;
}

int mayoract(int mayorahora, int n){

    if (n > mayorahora){
        return 1;
    }
}

int menoract(int menorahora, int n){

    if (n < menorahora){
        return 1;
    }
}

int sumatoria (int suma, int n){

    suma += n;
    return suma;
}

float media (int sum, int cant){

    float promedio;

    promedio = (float)sum/(float)cant;
    return promedio;
}

float desv(int num, int cantidad, float promedio){

    float elevado, devest;

    elevado = pow(num-promedio, 2);

    desvest = sqrt((1/cantidad)*())




}

