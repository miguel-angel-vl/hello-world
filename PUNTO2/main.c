#include <stdio.h>
#include <stdlib.h>

int sumatoria(int, int, int);
int mcd(int , int);


int main()
{
    int val, min, max;
    printf("Ingrese n%cmero: ", 163);
    scanf("%d", &val);

    do{
        printf("Ingrese m%cnimo del rango: ", 161);
        scanf("%d", &min);

        if(min <1){
            printf("NO PUEDE SER MENOR QUE 1");
        }
    }while(min < 1);

        do{
        printf("Ingrese m%cximo del rango: ", 160);
        scanf("%d", &max);

        if(max<min){
            printf("NO PUEDE SER MENOR QUE MINIMO");
        }
    }while(max<min);

    printf("LA SUMATORIA DE LOS MCD PARES DENTRO DEL RANGO ES: %d", sumatoria(val, min, max));

    return 0;
}

int sumatoria(int num, int liminf, int limsup){

    int suma = 0;


    do{
        if((mcd(num, liminf)) % 2 == 0){
            suma += mcd(num, liminf);
            printf("\n%d\n", suma);
        }
        liminf++;
    }while(liminf<=limsup);

    return suma;

}

int mcd(int x, int y){

    int div, aux;

    if(y > x){
        aux = x;
        y = aux;
        x = y;
    }

    for(div = x; div>=1; div--){
        if(y%div == 0 && x%div == 0){
            return div;
            break;
        }
    }

    return 1;
}




