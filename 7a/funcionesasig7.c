#include "funcionesasig7.h"

int simetrica(int **mat, int n){

    int indfil, indcol;

    for(indfil = 0; indfil < n; indfil++){
        for(indcol = 0; indcol < n; indcol++){
            if(*(*(mat+indfil)+indcol) != *(*(mat+indcol)+indfil))
                return 0;
        }
    }
    return 1;
}

void generarmatriz(int **mat, int n){

    int indfil, indcol;

    for(indfil = 0; indfil < n; indfil++){
        for(indcol = 0; indcol < n; indcol++){
            mat[indfil][indcol] = randrango(1, 19);
        }
    }

    for(indfil = 0; indfil < n; indfil++){
        for(indcol = 0; indcol < n; indcol++){
            printf(" %d\t", mat[indfil][indcol]);
        }
        printf("\n");
    }

    return;
}

int randrango(int a,int b)
{
   return rand() % (b-a+1) + a;
}


