#include <stdio.h>
#include <stdlib.h>

int mcd(int, int);

int main()
{
    int num1, num2;

    printf("Ingrese primer n%cmero: ",163);
    scanf("%d", &num1);

    printf("Ingrese segundo n%cmero: ",163);
    scanf("%d", &num2);

    printf("\nEl m%cximo com%cn divisor es: %d\n", 160, 163, mcd(num1, num2));

    return 0;
}

int mcd(int x, int y){

    int div, aux;

    if(y > x){
        aux = x;
        x = y;
        y = aux;
    }

    for(div = x; div>=1; div--){
        if(y%div == 0 && x%div == 0){
            return div;
            break;
        }
    }

    return 1;
}










