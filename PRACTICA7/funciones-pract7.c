#include <string.h>
#include "funciones-pract7.h"

char* elimoracion(char *oracion){

    do{
        if(*oracion == '.' || *oracion == '?' || *oracion == '!'){
            if(*oracion == ' '){
                return oracion+1;
            }
            else{
                return oracion+2;
            }
        }
        oracion++;
    }while(*oracion);

    return oracion;
}

