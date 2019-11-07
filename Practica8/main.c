#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ind;
    struct perro misperros[10];

    misperros[0].dog_id = 1;
    misperros[1].dog_id = 2;
    misperros[2].dog_id = 3;
    misperros[3].dog_id = 4;
    misperros[4].dog_id = 5;
    misperros[5].dog_id = 6;
    misperros[6].dog_id = 7;
    misperros[7].dog_id = 8;
    misperros[8].dog_id = 9;
    misperros[9].dog_id = 10;

    misperros[0].dog_id = 1;
    misperros[1].dog_id = 2;
    misperros[2].dog_id = 3;
    misperros[3].dog_id = 4;
    misperros[4].dog_id = 5;
    misperros[5].dog_id = 6;
    misperros[6].dog_id = 7;
    misperros[7].dog_id = 8;
    misperros[8].dog_id = 9;
    misperros[9].dog_id = 10;


    return 0;
}

struct perro{

    int dog_id;
    char name[50];
    int age;
    char raza[50];
    char dad[50];
    char mom[50];

};

struct dueno{

    char nombre[50];

};
