#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *frase;

    frase = malloc(100*sizeof(char));

    printf("Ingrese frase: ");
    gets(frase);

    printf("%s", elimoracion(frase));

    return 0;
}
