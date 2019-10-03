#include <stdio.h>
#include <stdlib.h>

#include "miLibreria.h"

int main()
{
    int min, max, suma = 0, j = 0, n;
    float promedio;

    do{
        printf("Ingrese rango de numeros: ");
        scanf("%d, %d", &min, &max);

        if (min < 0 || max<min){
            printf("Rango no valido");
        }
    }while (min < 0 || max < min);

    for (n = 2; j<=max; n++){
        if (esprimo(n)){
            j++;
            if (j>=min && j<=max){
                suma +=n;
            }
        }
    }

    promedio = (float)suma / (float)(max-min+1);

    printf("El promedio de los numeros primos es: %.3f", promedio);


    return 0;
}


