#include <string.h>
#include "funciones-pract7.h"

char* elimoracion(char *oracion){

    do{
        if(*oracion == '.' || *oracion == '?' || *oracion == '!'){
            if(*oracion == ' ')
                return oracion+2;
            else
                return oracion+1;
        }
        oracion++;
    }while(*oracion);
    
    return oracion;
}

