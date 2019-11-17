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

int main()
{
    int ind;
    struct losperros perro[CANTPERROS];
    struct losduenos dueno[CANTDUENOS];

    declarardatos(perro, dueno);

    organizaredad(perro);

    for(ind = 0; ind < CANTPERROS; ind++){
        imprimir(perro[ind]);
        printf("\n");
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
    strcpy(perro[3].dad, "");
    strcpy(perro[4].dad, perro[9].name);
    strcpy(perro[5].dad, "");
    strcpy(perro[6].dad, perro[4].name);
    strcpy(perro[7].dad, perro[4].name);
    strcpy(perro[8].dad, perro[0].name);
    strcpy(perro[9].dad, "");

    strcpy(perro[0].mom, perro[2].name);
    strcpy(perro[1].mom, perro[2].name);
    strcpy(perro[2].mom, "");
    strcpy(perro[3].mom, perro[1].name);
    strcpy(perro[4].mom, perro[8].name);
    strcpy(perro[5].mom, perro[8].name);
    strcpy(perro[6].mom, perro[1].name);
    strcpy(perro[7].mom, perro[8].name);
    strcpy(perro[8].mom, perro[2].name);
    strcpy(perro[9].mom, "");

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

void organizaredad(struct losperros *perro){

    int ind, n = CANTPERROS, burb = 1, masv;
    struct losperros temp;

    for(ind = 0; ind < n; ind++){
        burb = 1;
        masv = perro[ind].age;

        while(masv > perro[ind+burb].age && ind+burb < n){

            temp = perro[ind];
            perro[ind] = perro[ind+burb];
            perro[ind+burb] = temp;

            burb++;
        }
    }
    return;

}

void swap(struct losperros perro, struct losperros cambio)
{
   struct losperros temp;

   temp = perro, perro = cambio, cambio = temp;

   return;
}

void imprimir(struct losperros perro){

   printf("ID      : %d\n",perro.dog_id);
   printf("Nombre  : %s\n",perro.name);
   printf("Edad    : %d\n",perro.age);
   printf("Raza    : %s\n",perro.raza);
   printf("Padre   : %s\n",perro.dad);
   printf("Madre   : %s\n",perro.mom);
   printf("Due%co   : %s\n",164, perro.owner);

   return;

}


