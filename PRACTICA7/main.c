#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *frase;

    frase = malloc(100*sizeof(char));

    printf("Ingrese frase: ");
    gets(frase);

    elimoracion(frase);

    printf("%s", frase);

    return 0;
}
