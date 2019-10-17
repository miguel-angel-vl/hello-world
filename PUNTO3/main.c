#include <stdio.h>
#include <stdlib.h>

int main()
{

    int ind, espacio, letras, lineas;
    char caract;

    printf("PIRAMIDE DE LETRAS\n\n");

    do{
        printf("Ingrese cantidad de lineas: ");
        scanf("%d", &lineas);

        if(lineas < 0){
            printf("NO PUEDE SER MENOR QUE 0\n\n");
        }

        if(lineas < 0 || lineas > 'Z'-'A'){
            printf("NO PUEDE SER MAYOR QUE %d\n\n", 'Z'-'A'+1);
        }

    }while(lineas < 0 || lineas > 'Z'-'A'+1);

    for(ind = 0; ind < lineas; ind++){

        for(espacio = 0; espacio < ('Z'-'A')-ind; espacio++){
            printf(" ");
        }

        for(letras = 0; letras <= ind; letras++){
            caract = 'A'+letras;
            printf("%c", caract);
        }

        printf("\n");
    }

    return 0;
}
