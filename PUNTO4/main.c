#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int credporcal (int, char);

int main()
{
    int cantmat, indcant, cred, acum = 0, acumcred = 0;
    float indacum;
    char cal;

    printf("Ingrese cantidad de materias: ");
    scanf("%d", &cantmat);

    for(indcant = 1; indcant <= cantmat; indcant++){

        do{
            printf("Ingrese calificacion de materia #%d: ", indcant);
            cal = getche();

            if(cal!='A' && cal!='B' && cal!='C' && cal!= 'D' && cal !='F'){
                printf("\nCALIFICACION NO VALIDA!!\n\n");
            }
        }while (cal!='A' && cal!='B' && cal!='C' && cal!= 'D' && cal !='F');

        do{
            printf("\nIngrese n%cmero de cr%cditos: ", 163, 130);
            scanf("%d", &cred);

            if(cred < 1){
                printf("\nNO PUEDE SER MENOR QUE 1\n\n");
            }
        }while(cred<1);

        acum += credporcal(cred, cal);
        acumcred += cred;
    }

    indacum = (float)acum/acumcred;

    printf("El %cndice acumulado es: %.2f", 161, indacum);

    return 0;
}

int credporcal (int creditos, char letra){

    int mult;

    if(letra == 'A'){
         mult = 4*creditos;
    }
    if(letra == 'B'){
        mult = 3*creditos;
    }
    if(letra == 'C'){
        mult = 2*creditos;
    }
    if(letra == 'D'){
        mult = 1*creditos;
    }
    if(letra == 'F'){
        mult = 0*creditos;
    }
    return mult;
}
