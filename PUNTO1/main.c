#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *agregapuntoycoma(char *str);

int main()
{
    char *str;

    str = (char *)malloc(100*sizeof(char));

    strcpy(str, "int main(){\n     printf(\"Hello World!\")\n \n }" );

    printf("Cadena modificada: %s", agregapuntoycoma(str));

    return 0;
}


char *agregapuntoycoma(char *str){

    int ind, lstr = strlen(str), ind2;

    for(ind = 0; ind < lstr; ind++){
        if(*(str+ind) == '\n' && *(str+ind-1) != ';' && *(str+ind+1) != '\n'){

            str = (char *)realloc(str, (lstr+1)*sizeof(char));

            for(ind2 = strlen(str)-1; ind2 > ind; ind2--){
                *(str+ind2) = *(str+ind2+1);
            }
            *(str+ind2) = ';';

        }
    }

    return str;
}
