#include <stdio.h>
#include <stdlib.h>
#include <conio.c>
#include <ctype.h>

#define MAXCHAR   40
#define MAXPASS   10
#define CANTINI    2
#define MAXFIL     4
#define MAXCOL    50
#define DIMEN    150
#define MAXPREGS  20

#define NOMBREARCH "scores.dat"
#define ARCHAYUDA "Ayuda.txt"


typedef struct{

    char nombre[MAXCHAR];
    int score;
    char contra[MAXPASS];

}JUGADOR;

JUGADOR *registro(JUGADOR *usuarios, int ind, FILE *arch);
JUGADOR *registrados(FILE *arch, int n);

int main()
{
    char opc;
    int ind = 0;
    JUGADOR *usuarios;
    FILE *arch;

    //usuarios =(JUGADOR *)malloc(CANTINI * sizeof(JUGADOR));

    srand(time(NULL));

    system("color F0");
    gotoxy(40,1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    gotoxy(40,2);
    printf("%c %cA QUE NO SABES! %c", 179,173,179);
    gotoxy(40,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);

    gotoxy(32,4);
    printf("Presione cualquier tecla para comenzar\n");
    getch();

    do{
        system("cls");
        gotoxy(40,1);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
        gotoxy(40,2);
        printf("%c %cA QUE NO SABES! %c", 179,173,179);
        gotoxy(40,3);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);

        gotoxy(50,5);
        printf("MENU\n");
        gotoxy(48,7);
        printf("1.REGISTRO\n");
        gotoxy(48,8);
        printf("2.JUGAR\n");
        gotoxy(48,9);
        printf("3.AYUDA\n");
        gotoxy(48,10);
        printf("4.SALIR\n");


        do{
            opc = getch();

        }while(opc != '1' && opc != '2' && opc != '3' && opc != '4');


        switch(opc)
        {
            case '1':
                usuarios = registro(usuarios, ind, arch);
                ind++;
                break;

            case '2':
                //jugar(usuarios, arch);
                break;

            case '3':
                system("cls");
                //ayuda();
                break;

            case '4':
                break;

        }
    }while(opc != '4');

    return 0;
}

int jugar(JUGADOR *usuarios, FILE *arch){

    char opc;

    //usuarios = (JUGADOR *)malloc(CANTINI * sizeof(JUGADOR));

    do{
        system("cls");

        printf("MODOS DE JUEGO\n\n");
        printf("1. UN JUGADOR\n");
        printf("2. MULTIJUGADOR\n");
        printf("3. QUICK GAME\n");
        printf("4. HIGH SCORES\n");
        printf("5. VOLVER\n");

        do{
            opc = getch();

        }while(opc < '1' || opc > '6');

        switch(opc)
        {
            case '1':

                //oneplayer(usuarios, ind, arch);
                break;

            case '2':

                //multiplayer(usuarios, ind, arch);
                break;

            case '3':
                //quickgame(usuarios, ind, arch);
                break;

            case '4':
                //system("cls");
                break;

            case '5':
                return 1;
                break;

        }
    }while(opc != 5);

    return 1;
}

JUGADOR *registro(JUGADOR *usuarios, int ind, FILE *arch){

    int total = CANTINI, cant;
    char nomusu[MAXCHAR];

    system("cls");

    usuarios = registrados(arch, cant);

    do{
        printf("Ingrese nombre de usuario: ");
        fflush(stdin);
        gets(nomusu);

        if(strlen(nomusu) > MAXCHAR-1 || nomusu[0] == '\0')
            printf("El nombre de USUARIO no puede pasar de %d digitos ni puede estar vac%co\n\n", MAXCHAR-1, 161);

        else if ( existusuario(usuarios,ind,nomusu,arch) != -1)
            printf("Este nombre ya est%c asignado\n\n",160);

    }while((strlen(nomusu) > MAXCHAR-1 || nomusu[0] == '\0') || existusuario(usuarios,ind,nomusu, arch) != -1);

    strcpy(*(usuarios+ind)->nombre, nomusu);
    getpassword(usuarios+ind);

    if (guardar_registrados(arch, usuarios, cant) == -1){
        return NULL;
    }else{
        return registrados;
    }
}

JUGADOR *registrados(FILE *arch, int n){

    JUGADOR* jugadores;

    arch = fopen(NOMBREARCH, "rb");

    if (arch == NULL){
        return NULL;
    }

    fread(&n, sizeof(int), 1, arch);

    jugadores = (JUGADOR*)malloc(n * sizeof(JUGADOR));

    fread(jugadores, sizeof(JUGADOR), n, arch);

    fclose(arch);

    return jugadores;
}

int existusuario(JUGADOR *usu, int n, char nombre[], FILE *arch)
{
    int ind;

    arch = fopen(NOMBREARCH, "rb");

    fread(&n, sizeof(int),1, arch);
    fread(usu, sizeof(JUGADOR), n, arch);

    for (ind = 0; ind < n; ind ++){
       if ( strcmp(usu[ind].nombre, nombre) == 0 )
          return ind;
    }

    fclose(arch);

    return -1;
}

void getpassword(JUGADOR *usuario){

   int ind;
   char chars;

   do
   {
       ind = 0;
       printf("Ingrese su contrase%ca: ",164);

       while( chars = getch() )
       {
          if(chars == 13)
          {
             usuario->contra[ind] = '\0';
             break;
          }
          else
          if(chars == 8)
          {
             if(ind > 0)
             {
                ind--;
                printf("\b \b");
             }
          }
          else
          {
             if(ind < MAXPASS)
             {
                printf("*");
                usuario->contra[ind] = chars;
                ind++;
             }
          }
       }

       if (passwordlen(usuario) == 0)
       {
           printf("\nLa contrase%ca debe tener m%cnimo 4 car%ccteres y m%cximo %d.\n",164,161,160,160,MAXPASS-1);
       }

   }while(passwordlen(usuario) == 0);

   return;
}

int passwordlen(JUGADOR *usuario)
{
   int passlen = strlen(usuario->contra);

   if (passlen >= 4 && passlen <= MAXPASS-1)
      return 1;

   return 0;
}


int guardar_registrados(FILE *arch, JUGADOR* usuarios, int cant){

    arch = fopen(NOMBREARCH, "wb");

    if (arch == NULL){
        printf("\nARCHIVO NO EXISTE\n");
        return 0;
    }

    fwrite(&cant, sizeof(int), 1, arch);
    fwrite(usuarios, sizeof(JUGADOR), cant, arch);

    fclose(arch);

    return 1;

}
