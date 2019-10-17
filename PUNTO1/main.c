#include <stdio.h>
#include <stdlib.h>

int mcd(int, int);

int main()
{
    int num1, num2;

    printf("Ingrese dos n%cmeros: ",163);
    scanf("%d, %d", &num1, &num2);

    printf("El m%cximo com%cn divisor es: %d", 162, 160, mcd(num1, num2));


    return 0;
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










