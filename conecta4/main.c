#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXFIL 6
#define MAXCOL 7

#define ESC 27
#define ENTER 13

int main()
{
    char mat[MAXFIL][MAXCOL] = {0};
    int filasel, columsel, tecla;

    do{

    muestra(mat, MAXFIL, MAXCOL);
    printf("Ingrese coodenadas: ");
    scanf("%d, %d", &filasel, &columsel);

    tecla = getch();

    if(tecla == ENTER){
        if(mat[filasel][columsel] != 'O'){
            mat[filasel][columsel] = 'O';
        }

        if((mat[filasel][columsel+1] == '0' && mat[filasel][columsel+2] == '0' && mat[filasel][columsel+3] == '0' )
           || (mat[filasel+1][columsel+1] == '0' && mat[filasel+2][columsel+2] == '0' && mat[filasel+3][columsel+3] == '0')
           || (mat[filasel][columsel-1] == '0' && mat[filasel][columsel-2] == '0' && mat[filasel][columsel-3] == '0' )
           || (mat[filasel-1][columsel-1] == '0' && mat[filasel-2][columsel-2] == '0' && mat[filasel-3][columsel-3] == '0' )
           || (mat[filasel+1][columsel] == '0' && mat[filasel+2][columsel] == '0' && mat[filasel+3][columsel] == '0' )
           || (mat[filasel-1][columsel] == '0' && mat[filasel-2][columsel] == '0' && mat[filasel-3][columsel] == '0' )){

            printf("\nGano");
            break;

        }

    }
    system("cls");

    }while(tecla!= ESC);

    //printf("\nGano");
    return 0;
}

void muestra(char matriz[][MAXCOL], int n, int m){

    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if(matriz[i][j] == 0){
                printf(" x ",matriz[i][j]);
            }else{
                printf(" %c ",matriz[i][j]);
            }
        }
        printf("\n");
    }
}
