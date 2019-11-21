#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTPERROS 10
#define CANTDUENOS 7




struct losperros{

    int dog_id;
    char name[55];
    int age;
    char raza[50];
    char dad[50];
    char mom[50];
    char owner[50];
};

struct losduenos{

    char nombre[50];

};

struct arr_perros{
    struct losperros * arreglo;
    int n;
};

struct arr_perros encuentradueno(struct losperros *perro, char dueno[]);
struct losperros *encuentrahermano1(struct losperros *perro, char hermano[]);
int tusperros(struct losperros *perro, char dueno[]);
void declarardatos(struct losperros *perro, struct losduenos *dueno);
void imprimir(struct losperros perro);
int encuentranombre(struct losperros *perro, char nombre[]);

int main()
{
    int k;
    int ind, buscardueno = 1, j;
    char owner[50], hermano[50];
    struct losperros perro[CANTPERROS];
    struct losduenos dueno[CANTDUENOS];
    struct losperros *hermanos;

    declarardatos(perro, dueno);


    for(ind = 0; ind < CANTPERROS; ind++){
        imprimir(perro[ind]);
        printf("\n");
    }

    do{
        do{
            printf("\n%cDesea buscar perro en espec%cfico[POR DUE%cO]? [1]-S%c [0]-No: ", 168, 161, 165, 161);
            scanf("%d", &buscardueno);

            if(buscardueno != 1 && buscardueno != 0){
                printf("OPCION NO VALIDA.\n\n");
            }
        }while(buscardueno != 1 && buscardueno != 0);

        if(buscardueno == 1){
            printf("\nINGRESE DUE%cO DE PERRO A BUSCAR: ", 165);
            fflush(stdin);
            gets(owner);


            struct arr_perros res;

            res =encuentradueno(perro, owner);
            for(k=0; k < res.n; k++){
                imprimir(res.arreglo[k]);

            }

        }
    }while (buscardueno == 1);

    printf("Escriba nombre de perro para encontrar su hermano: ");
    fflush(stdin);
    gets(hermano);

    //printf("%s es hermano de %s", perro[encuentranombre(perro, hermano)].name, perro[encuentrahermano1(perro, hermano)].name);

    hermanos = encuentrahermano1(perro, hermano);

    for(j = 0; j < encuentranombre(perro,hermano); j++){
        imprimir(hermanos[j]);
    }

    return 0;
}


void declarardatos(struct losperros *perro, struct losduenos *dueno)
{
    strcpy(dueno[0].nombre, "Steve");
    strcpy(dueno[1].nombre, "Owen Wilson");
    strcpy(dueno[2].nombre, "Brian");
    strcpy(dueno[3].nombre, "Brendon");
    strcpy(dueno[4].nombre, "Hola");
    strcpy(dueno[5].nombre, "Natalia");
    strcpy(dueno[6].nombre, "Kim");

    perro[0].dog_id = 1;
    perro[1].dog_id = 2;
    perro[2].dog_id = 3;
    perro[3].dog_id = 4;
    perro[4].dog_id = 5;
    perro[5].dog_id = 6;
    perro[6].dog_id = 7;
    perro[7].dog_id = 8;
    perro[8].dog_id = 9;
    perro[9].dog_id = 10;

    strcpy(perro[0].name, "Saludo");
    strcpy(perro[1].name, "Blue");
    strcpy(perro[2].name, "Troublemaker");
    strcpy(perro[3].name, "Myownworstenemy");
    strcpy(perro[4].name, "Coolpatrol");
    strcpy(perro[5].name, "Marley");
    strcpy(perro[6].name, "Amazonprimeflowyouknowialwaysdeliver");
    strcpy(perro[7].name, "Lyingisthemostfunagirlcanhavewithouttakingherclothesoff");
    strcpy(perro[8].name, "Myfavoriteaccident");
    strcpy(perro[9].name, "Famouslastwords");

    perro[0].age = 10;
    perro[1].age = 5;
    perro[2].age = 4;
    perro[3].age = 6;
    perro[4].age = 2;
    perro[5].age = 1;
    perro[6].age = 15;
    perro[7].age = 16;
    perro[8].age = 20;
    perro[9].age = 5;

    strcpy(perro[0].raza, "Mastin napolitano");
    strcpy(perro[1].raza, "Beagle");
    strcpy(perro[2].raza, "Chihuahua");
    strcpy(perro[3].raza, "Yorkie Poo");
    strcpy(perro[4].raza, "Shiba Inu");
    strcpy(perro[5].raza, "Golden Labrador Retriever");
    strcpy(perro[6].raza, "Bulldog");
    strcpy(perro[7].raza, "Doberman");
    strcpy(perro[8].raza, "Pug");
    strcpy(perro[9].raza, "Yorkie Poo");

    strcpy(perro[0].dad, perro[9].name);
    strcpy(perro[1].dad, perro[0].name);
    strcpy(perro[2].dad, perro[9].name);
    strcpy(perro[3].dad, "\0");
    strcpy(perro[4].dad, perro[9].name);
    strcpy(perro[5].dad, "\0");
    strcpy(perro[6].dad, perro[4].name);
    strcpy(perro[7].dad, perro[4].name);
    strcpy(perro[8].dad, perro[0].name);
    strcpy(perro[9].dad, "\0");

    strcpy(perro[0].mom, perro[2].name);
    strcpy(perro[1].mom, perro[2].name);
    strcpy(perro[2].mom, "\0");
    strcpy(perro[3].mom, perro[1].name);
    strcpy(perro[4].mom, perro[8].name);
    strcpy(perro[5].mom, perro[8].name);
    strcpy(perro[6].mom, perro[1].name);
    strcpy(perro[7].mom, perro[8].name);
    strcpy(perro[8].mom, perro[2].name);
    strcpy(perro[9].mom, "\0");

    strcpy(perro[0].owner, dueno[4].nombre);
    strcpy(perro[1].owner, dueno[0].nombre);
    strcpy(perro[2].owner, dueno[3].nombre);
    strcpy(perro[3].owner, dueno[6].nombre);
    strcpy(perro[4].owner, dueno[5].nombre);
    strcpy(perro[5].owner, dueno[1].nombre);
    strcpy(perro[6].owner, dueno[2].nombre);
    strcpy(perro[7].owner, dueno[3].nombre);
    strcpy(perro[8].owner, dueno[6].nombre);
    strcpy(perro[9].owner, dueno[4].nombre);
    return;
}



struct arr_perros encuentradueno(struct losperros *perro, char dueno[]){
    struct arr_perros arr;

    int ind, n = CANTPERROS, i = 0;
    struct losperros *acumd;

    for(ind = 0; ind < n; ind++){
        if(stricmp(perro[ind].owner, dueno) == 0){
            if (i==0){
                acumd = (struct losperros*)malloc(1*sizeof(struct losperros));
            }else{
                acumd = (struct losperros*)realloc(acumd, (i+2)*sizeof(struct losperros));
            }
            *(acumd+i) = perro[ind];
            i++;
        }
    }
    arr.arreglo = acumd;
    arr.n = i;
    return arr;
}

int encuentranombre(struct losperros *perro, char nombre[]){

    int ind, n = CANTPERROS;

    for(ind = 0; ind < n; ind++){
        if (stricmp(perro[ind].name, nombre) == 0){
            return ind;
        }
    }
    return -1;
}

struct losperros *encuentrahermano1(struct losperros *perro, char hermano[]){

    int ind, n = CANTPERROS, j = 0;
    struct losperros *acumh;

    acumh = (struct losperros*)malloc(1*sizeof(struct losperros));

    for(ind = 0; ind < n; ind++){
        if(stricmp(perro[ind].name, hermano) == 0){
            for(j = 0; j < encuentranombre(perro,hermano); j++){
                acumh = (struct losperros*)realloc(acumh, 1*sizeof(struct losperros));
                if((strcmp(perro[ind].dad, perro[j].dad) == 0 || strcmp(perro[ind].mom, perro[j].mom) == 0) && strcmp(perro[ind].name, perro[j].name) != 0){
                    *(acumh+j) = perro[j];
                }
            }
        }
    }

    return acumh;

}

int tusperros(struct losperros *perro, char dueno[]){

    int ind, total = 0, n = CANTPERROS;

    for(ind = 0; ind < n; ind++){
        if(stricmp(perro[ind].owner, dueno) == 0){
            total++;
        }
    }

    return total;
}


void imprimir(struct losperros perro){

   printf("ID      : %d\n", perro.dog_id);
   printf("Nombre  : %s\n", perro.name);
   printf("Edad    : %d\n", perro.age);
   printf("Raza    : %s\n", perro.raza);
   printf("Padre   : %s\n", perro.dad);
   printf("Madre   : %s\n", perro.mom);
   printf("Due%co   : %s\n", 164, perro.owner);

   return;

}

