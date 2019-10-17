#include <stdio.h>
#include <stdlib.h>

int main()
{

    int ind, espacio, letras;
    char caract;

    printf("PIRAMIDE DE LETRAS\n");

    for(ind = 1; ind <= 'Z'-'A'; ind++){

        for(espacio = 0; espacio < ('Z'-'A')- ind; espacio++){
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
