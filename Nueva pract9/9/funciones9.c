#include "funciones9.h"

ESTUDIANTE *agregarEstudiante(ESTUDIANTE *estud, int n){

    int indasig, indeval, ind;

    for(ind = 0; ind < n; ind++){

        printf("Digite matr%ccula: ", 161);
        fflush(stdin);
        gets(estud[ind].matricula);

        printf("Ingrese nombre: ");
        estud[ind].nombre = (char *)malloc(75*sizeof(char));
        fflush(stdin);
        gets(estud[ind].nombre);

        printf("Digite n%cmero de materias que toma el estudiante: ", 163);
        scanf("%d", &estud[ind].n_mats);

        for(indasig = 0; indasig < estud[ind].n_mats; indasig++){

            printf("Digite nombre de la asignatura: ");
            fflush(stdin);
            gets(estud[ind].mat[indasig].nombre);

            printf("Ingrese cantidad de cr%cditos de asignatura: ", 130);
            fflush(stdin);
            scanf("%d", &estud[ind].mat[indasig].creditos);

            printf("Digite n%cmero de evaluaciones de la asignatura: ", 163);
            scanf("%d", &estud[ind].mat[indasig].n_eva);

            for(indeval = 0; indeval < estud[ind].mat[indasig].n_eva; indeval++){

                printf("Ingrese nombre de evaluaci%cn: ", 162);
                fflush(stdin);
                gets(estud[ind].mat[indasig].eva[indeval].nombre);

                printf("Ingrese ponderaci%cn: ", 162);
                scanf("%d", &estud[ind].mat[indasig].eva[indeval].ponderacion);

                printf("Ingrese calificaci%cn obtenida: ", 161);
                scanf("%d", &estud[ind].mat[indasig].eva[indeval].calificacion_obtenida);
            }
        }
    }
    return estud;
}

ESTUDIANTE * guardarEstudiantes(ESTUDIANTE *estud, int n, FILE * arch){

    //FILE *arch;
    int ind;
    char buff[100];

    arch = fopen(NOMARCH, "ab");

    fwrite(&n, sizeof(int), 1, arch);
    fwrite(&estud, sizeof(ESTUDIANTE), n, arch);

    for(ind = 0; ind < n; ind++){
        strcpy(buff, estud[ind].nombre);
        fwrite(buff, sizeof(char), 100, arch);
    }
    fflush(arch);
    fclose(arch);

    return estud;
}


ESTUDIANTE * cargarEstudiantes(char * narch){

    int n_est, ind;
    char buff[100];
    //printf("Algo");

    ESTUDIANTE* estud;

    FILE *arch = fopen(narch, "rb");
    //printf("Algo");

    if(arch == NULL){
        return NULL;
    }
    //printf("Algo");

    fread(&n_est, sizeof(int), 1, arch);
    estud = (ESTUDIANTE *)malloc(n_est * sizeof(ESTUDIANTE));
    fread(estud, sizeof(ESTUDIANTE), n_est, arch);

    for (ind = 0; ind < n_est; ind++) {
        //printf("Algo");
        estud[ind].nombre = calloc(100, sizeof(char));
        printf("Algo");

        fread(buff, sizeof(char), 100, arch);
        strcpy(estud[ind].nombre, buff);
        imprimir(estud[ind]);
    }
    fclose(arch);
    return estud;
}

void imprimir(ESTUDIANTE estud){

    int indasig, indeval;

    printf("\nNombre de estudiante: %s\n", estud.nombre);
    printf("Edad de estudiante: %d\n", estud.edad);
    printf("Matr%ccula de estudiante: %s\n", 161, estud.matricula);

    printf("Cantidad de asignaturas que toma el estudiante: %d\n\n", estud.n_mats);

    for(indasig = 0; indasig < estud.n_mats; indasig++){
        printf("Asignatura #%d: %s\n", indasig+1, estud.mat[indasig].nombre);
        printf("Cr%cditos: %d\n", 130, estud.mat[indasig].creditos);
        printf("N%cmero de evaluaciones: %d\n", 163, estud.mat[indasig].n_eva);

        for(indeval = 0; indeval < estud.mat[indasig].n_eva; indeval++){
            printf("Nombre de evaluaci%cn: %s\n", 162, estud.mat[indasig].eva[indeval].nombre);
            printf("Ponderaci%cn: %d%\n", 162, estud.mat[indasig].eva[indeval].ponderacion);
            printf("Calificaci%cn obtenida: %d\n", 162, estud.mat[indasig].eva[indeval].calificacion_obtenida);
        }
    }
    return;
}

ESTUDIANTE llenar(ESTUDIANTE *est, int ind, char *nombre, int edad, char matricula[], int num_mats, char nomasig[], int creds, int numeroevals, char nombeval[], int pond, int cal_obt){

    strcpy(est[ind].nombre, nombre);
    est[ind].edad = edad;
    strcpy(est[ind].matricula, matricula);
    est[ind].n_mats = num_mats;
    strcpy(est[ind].mat.nombre, nomasig);

    est[ind].mat.creditos = creds;
    est[ind].mat.n_eva = numeroevals;

    strcpy(est[ind].mat.eva.nombre, nombeval)
    est[ind].mat.eva.ponderacion = pond;
    est[ind].mat.eva.calificacion_obtenida = cal_obt;


    return;

}
