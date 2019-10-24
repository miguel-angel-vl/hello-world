#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 21

int carnum(char []);

int main()
{
    char str[MAXCHAR];

    printf("Digite cadena de numeros: ");
    gets(str);

    if(carnum(str) == 1){
        printf("Felicidades, eres muy inteligente");
    }else{
        printf("NO HA INGRESADO CADENA DE CARACTERES NUMERICOS");
    }

    return 0;
}

int carnum(char string[]){

    int ind;
    int solo_num = 1;
    int can_ptos=0;

    for(ind = 0; ind < strlen(string); ind++){
        if(string[ind] < '0' && string[ind] > '9' && string[ind] != '.'){
            solo_num = 0;
        }
        if(string[ind] == '.'){
            can_ptos++;
        }
    }

    if(solo_num == 0 || can_ptos > 1){
        return 0;
    }else{
        return 1;
    }

}
