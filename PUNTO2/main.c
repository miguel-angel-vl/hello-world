#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct entero_largisimo{
    char * digitos;
} ENTERO_LARG;

ENTERO_LARG multiplica(ENTERO_LARG a, ENTERO_LARG b);
ENTERO_LARG suma(ENTERO_LARG a, ENTERO_LARG b);

int main()
{
    printf("Hello world!\n");
    return 0;
}

ENTERO_LARG multiplica(ENTERO_LARG a, ENTERO_LARG b){

    ENTERO_LARG *resultado;
    int canta = strlen(a.digitos), cantb = strlen(b.digitos), i, j, max;

    if(canta > cantb){
        resultado.digitos = (char*)malloc((canta+1) * sizeof(char));
        max = cantb;
        menor = canta;
    }else if(cantb > canta){
        resultado.digitos = (char*)malloc((cantb+1) * sizeof(char));
        max = canta;
        menor = cantb;
    }

    for(i = max; i > 0; i--){

    }

}





