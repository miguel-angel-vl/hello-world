#include <stdio.h>
#include <stdlib.h>
#include <conio.c>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAXCARACT   40
#define MAXPASS   10
#define CANTINI    2
#define MAXFIL     4
#define MAXCOL    50
#define DIMEN    150
#define MAXPREGS  20
#define MAXSCORES 20

#define NOMBREARCH "usuarios.dat"
#define NOMBRESCORES "scores.dat"
#define ARCHAYUDA "Ayuda.txt"
#define ARCHCREDS "CREDITOS.txt"

typedef struct{

    char nombre[MAXCARACT];
    char contra[MAXPASS];

}JUGADOR;

struct resultados{

   char nombre[MAXCARACT];
   int score;

}resul;

int registro(JUGADOR **registrados, int *ind);
int passwordlen(JUGADOR *usuario);
void getpassword(JUGADOR *usuario);
int existusuario(JUGADOR *,int, char *nombre);
int jugar(JUGADOR **usuarios, int *);
long tamarch(FILE *arch);
void guardar_highscore(JUGADOR usuario, int score);
void mostrar_highscores();
void cargar(JUGADOR **registrados, int *ind);
int ayuda();
int creditos();
int randrango(int a,int b);
int existe(int arr[], int n, int val);
int oneplayer(JUGADOR *registrados);
int multiplayer(JUGADOR *registrados, int cant);
int quickgame(JUGADOR *registrados, int cant);
int series(int quick);
int peliculas(int quick);
int historia(int quick);
int geografia(int quick);
int deporte(int quick);
int musica(int quick);
int preguntaseries(int aleat);
int preguntapelicula(int aleat);
int preguntahistoria(int aleat);
int preguntageografia(int aleat);
int preguntadeportes(int aleat);
int preguntamusica(int aleat);

int main()
{
    char opc;
    int ind;
    JUGADOR *usuarios;
    FILE *arch;

    if((arch = fopen(NOMBREARCH,"a+b")) != NULL){
        ind = (int) (tamarch(arch) / sizeof(JUGADOR));
    }else{
        ind = 0;
    }

    fclose(arch);

    cargar(&usuarios, &ind);

    usuarios = NULL;

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

        gotoxy(48,5);
        printf("MENU\n");
        gotoxy(23,7);
        printf("1.JUGAR         2.AYUDA         3.CREDITOS         4.SALIR\n");

        do{
            opc = getch();

        }while(opc != '1' && opc != '2' && opc != '3' && opc != '4');

        switch(opc)
        {
            case '1':
                jugar(&usuarios, &ind);
                break;

            case '2':
                system("cls");
                ayuda();
                break;

            case '3':
                system("cls");
                creditos();
                break;

            case '4':
                break;
        }

    }while(opc != '4');

    return 0;
}

int jugar(JUGADOR **usuarios, int *ind){

    char opc;

    do{
        system("cls");

        printf("MODOS DE JUEGO\n\n");
        printf("1. REGISTRAR USUARIO\n");
        printf("2. UN JUGADOR\n");
        printf("3. MULTIJUGADOR\n");
        printf("4. QUICK GAME\n");
        printf("5. RESULTADOS ANTERIORES\n");
        printf("6. VOLVER\n");

        do{
            opc = getch();

        }while(opc < '1' || opc > '6');

        switch(opc)
        {
            case '1':
                registro(usuarios, ind);
                break;

            case '2':
                oneplayer(*usuarios);
                break;

            case '3':
                multiplayer(*usuarios, ind);
                break;

            case '4':
                quickgame(*usuarios, ind);
                break;

            case '5':
                system("cls");
                mostrar_highscores();
                break;

            case '6':
                return 1;
                break;
        }

    }while(opc != 6);

    return 1;
}

int registro(JUGADOR **registrados, int *ind){

    int total = CANTINI;
    char nomusu[MAXCARACT];
    int existuser;

    FILE *arch;

    if ((arch = fopen(NOMBREARCH, "a+b")) == NULL){
        return -1;
    }

    *ind = (int) (tamarch(arch) / sizeof(JUGADOR));
    total = (*ind) + CANTINI;
    *registrados = (JUGADOR *) malloc(total*sizeof(JUGADOR));
    fread(*registrados, sizeof(JUGADOR), *ind, arch);

    system("cls");

    fclose(arch);

    do{
        printf("Ingrese nombre de usuario: ");
        fflush(stdin);
        gets(nomusu);

        if(strlen(nomusu) > MAXCARACT-1 || nomusu[0] == '\0')
            printf("El nombre de USUARIO no puede pasar de %d digitos ni puede estar vac%co\n\n", MAXCARACT-1, 161);

        else if ( (existuser = existusuario(*registrados,(total-CANTINI),nomusu)) != -1)
            printf("Este nombre ya est%c asignado\n\n",160);

    }while((strlen(nomusu) > MAXCARACT-1 || nomusu[0] == '\0') || existuser != -1);

    strcpy(((*registrados)+(*ind))->nombre, nomusu);
    getpassword((*registrados)+(*ind));
    (*ind)++;

    if((arch = fopen(NOMBREARCH, "wb")) == NULL){
        printf("Archivo no existe\n");
        exit(-1);
    }

    fwrite(*registrados, sizeof(JUGADOR), *ind, arch);
    fclose(arch);

    return 1;
}

void cargar(JUGADOR **registrados, int *ind){

    FILE *arch;
    int total = CANTINI;

    if ((arch = fopen(NOMBREARCH, "a+b")) == NULL){
        exit(-1);
    }

    *ind = (int) (tamarch(arch) / sizeof(JUGADOR));
    total = (*ind) + CANTINI;
    registrados = (JUGADOR *) malloc(total*sizeof(JUGADOR));
    fread(registrados, sizeof(JUGADOR), *ind, arch);

    fclose(arch);

    return;
}

int oneplayer(JUGADOR *registrados){

    int user, score = 0, cant = 0, ind;
    char categoria, nom[MAXCARACT], pass[MAXPASS], chars;
    FILE *arch;

    if ((arch = fopen(NOMBREARCH, "a+b")) == NULL){
        return -1;
    }

    cant = (int) (tamarch(arch) / sizeof(JUGADOR));
    fclose(arch);

    system("cls");

    do
    {
        gotoxy(40,2);
        printf("INICIO DE SESION\n\n");
        ind = 0;

        do{
            printf("Ingrese nombre de USUARIO: ");
            fflush(stdin);
            gets(nom);

            user = existusuario(registrados,cant,nom);

            if(user == -1){
                printf("Usuario no registrado\n\n");
                getch();
                system("cls");
            }
        }while(user == -1);

        printf("Ingrese contrase%ca: ", 164);
        fflush(stdin);

        while( (chars = getch()) )
        {
            if(chars == 13)
            {
                pass[ind] = '\0';
                break;
            }
            else if(chars == 8)
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
                    pass[ind] = chars;
                    ind++;
                }
            }
        }

//        gets(pass);

        if(stricmp(pass, registrados[user].contra) != 0){
            printf("\nCONTRASE%cA INCORRECTA\n\n", 165);
            getch();
            system("cls");
        }

    }while(strcmp(pass, registrados[user].contra) != 0 || user == -1);

    system("cls");

    gotoxy(40,2);
    printf("%cBIENVENIDO \" %s \"!",173,registrados[user].nombre);
    gotoxy(30,3);
    printf("SELECCIONE LA CATEGORIA EN LA QUE DESEA JUGAR:\n\n");
    printf("1. Series de TV\n");
    printf("2. Pel%cculas\n", 161);
    printf("3. Historia\n");
    printf("4. Geograf%ca\n", 161);
    printf("5. Deporte\n");
    printf("6. M%csica\n", 163);
    printf("7. VOLVER\n");

    do{
        categoria = getch();
    }while(categoria < '1' || categoria > '7');

    switch(categoria){

        case '1':
            system("cls");
            printf("**********SERIES de TV**********\n\n");
            getch();

            score = series(0);
            printf("SU SCORE FUE DE %d\n\n", score);
            system("pause");
            guardar_highscore(registrados[user],score);
            break;

        case '2':
            system("cls");
            printf("**********PELICULAS**********\n\n");
            getch();

            peliculas(0);
            printf("SU SCORE FUE DE %d\n\n", score);
            system("pause");
            guardar_highscore(registrados[user],score);
            break;

        case '3':
            system("cls");
            printf("**********HISTORIA**********\n\n");
            getch();

            historia(0);
            printf("SU SCORE FUE DE %d\n\n", score);
            system("pause");
            guardar_highscore(registrados[user],score);
            break;

        case '4':
            system("cls");
            printf("**********GEOGRAFIA**********\n\n");
            getch();

            geografia(0);
            printf("SU SCORE FUE DE %d\n\n", score);
            system("pause");
            guardar_highscore(registrados[user],score);
            break;

        case '5':
            system("cls");
            printf("**********DEPORTES**********\n\n");
            getch();

            deporte(0);
            printf("SU SCORE FUE DE %d\n\n", score);
            system("pause");
            guardar_highscore(registrados[user],score);
            break;

        case '6':
            system("cls");
            printf("**********MUSICA**********\n\n");
            getch();

            musica(0);
            printf("SU SCORE FUE DE %d\n\n", score);
            system("pause");
            guardar_highscore(registrados[user],score);
            break;

        case '7':
            return 1;
            break;

    }

    return 1;
}

int multiplayer(JUGADOR *registrados, int cant)
{
    int user1, user2, cont = 1, score1, score2, ronda = 0, gan1 = 0, gan2 = 0, ind;
    char categoria, nom1[MAXCARACT], nom2[MAXCARACT], pass1[MAXPASS], pass2[MAXPASS], chars;

    system("cls");

    do
    {
        gotoxy(40,2);
        printf("INICIO DE SESION\n\n");
        ind = 0;

        do{
            printf("Ingrese nombre de USUARIO 1: ");
            fflush(stdin);
            gets(nom1);

            user1 = existusuario(registrados,cant,nom1);

            if(user1 == -1){
                printf("Usuario no registrado\n\n");
                getch();
                system("cls");
            }
        }while(user1 == -1);

        printf("Ingrese contrase%ca: ", 164);
        fflush(stdin);

        while( (chars = getch()) )
        {
            if(chars == 13)
            {
                pass1[ind] = '\0';
                break;
            }
            else if(chars == 8)
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
                    pass1[ind] = chars;
                    ind++;
                }
            }
        }
        //gets(pass1);

        if(strcmp(pass1, registrados[user1].contra) != 0){
            printf("\nCONTRASE%cA INCORRECTA\n\n", 165);
            getch();
            system("cls");
        }

    }while(strcmp(pass1, registrados[user1].contra) != 0 || user1 == -1);

    system("cls");

    do
    {
        gotoxy(40,2);
        printf("INICIO DE SESION\n\n");
        ind = 0;

        do{
            printf("Ingrese nombre de USUARIO 2: ");
            fflush(stdin);
            gets(nom2);

            user2 = existusuario(registrados,cant,nom2);

            if(user2 == -1){
                printf("Usuario no registrado\n\n");
            }
        }while(user2 == -1);

        printf("Ingrese contrase%ca: ", 164);
        fflush(stdin);

        while( (chars = getch()) )
        {
            if(chars == 13)
            {
                pass2[ind] = '\0';
                break;
            }
            else if(chars == 8)
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
                    pass2[ind] = chars;
                    ind++;
                }
            }
        }

//        gets(pass2);

        if(strcmp(pass2, registrados[user2].contra) != 0){
            printf("\nCONTRASE%cA INCORRECTA\n\n", 165);
            getch();
            system("cls");
        }


    }while(strcmp(pass2, registrados[user2].contra) != 0 || user2 == -1);

    system("cls");


    gotoxy(40,2);
    printf("%c%s vs. %s!",173,registrados[user1].nombre, registrados[user2].nombre);
    gotoxy(30,3);
    printf("SELECCIONE LA CATEGORIA EN LA QUE DESEA JUGAR:\n\n");
    printf("1. Series de TV\n");
    printf("2. Pel%cculas\n", 161);
    printf("3. Historia\n");
    printf("4. Geograf%ca\n", 161);
    printf("5. Deporte\n");
    printf("6. M%csica\n", 163);
    printf("7. VOLVER\n");

    do{
        categoria = getch();
    }while(categoria < '1' || categoria > '7');

    switch(categoria){

        case '1':
            do{
                do{
                    if(cont == 1){

                        system("cls");
                        printf("**********SERIES de TV**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user1].nombre);
                        system("pause");
                        system("cls");
                        printf("**********SERIES de TV**********\n\n");

                        score1 = series(0);
                        printf("SU SCORE FUE DE %d\n\n", score1);
                        system("pause");

                    }else{

                        system("cls");
                        printf("**********SERIES de TV**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user2].nombre);
                        system("pause");
                        system("cls");
                        printf("**********SERIES de TV**********\n\n");

                        score2 = series(0);
                        printf("SU SCORE FUE DE %d\n\n", score2);
                        system("pause");
                    }
                    cont++;

                }while (cont < 3);

                if(score1 > score2){
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user1].nombre);
                    system("pause");
                    gan1++;
                }else{

                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user2].nombre);
                    system("pause");
                    gan2++;
                }
                cont = 1;
                ronda++;
            }while(ronda < 3);

            if(gan1 >gan2){

                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }else{

                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }

            ronda = 0;
            break;

        case '2':
            do{
                do{
                    if(cont == 1){

                        system("cls");
                        printf("**********PELICULAS**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user1].nombre);
                        system("pause");
                        system("cls");
                        printf("**********PELICULAS**********\n\n");

                        score1 = peliculas(0);
                        printf("SU SCORE FUE DE %d\n\n", score1);
                        system("pause");

                    }else{
                        system("cls");
                        printf("**********PELICULAS**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user2].nombre);
                        system("pause");
                        system("cls");
                        printf("**********PELICULAS**********\n\n");

                        score2 = peliculas(0);
                        printf("SU SCORE FUE DE %d\n\n", score2);
                        system("pause");
                    }
                    cont++;

                }while (cont < 3);

                if(score1 > score2){

                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user1].nombre);
                    system("pause");
                    gan1++;

                }else{

                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user2].nombre);
                    system("pause");
                    gan2++;

                }
                cont = 1;
                ronda++;

            }while(ronda < 3);

            if(gan1 >gan2){

                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");

            }else{

                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");

            }
            ronda = 0;
            break;

        case '3':
            do{
                do{
                    if(cont == 1)
                    {
                        system("cls");
                        printf("**********HISTORIA**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user1].nombre);
                        system("pause");
                        system("cls");
                        printf("**********HISTORIA**********\n\n");

                        score1 = historia(0);
                        printf("SU SCORE FUE DE %d\n\n", score1);
                        system("pause");

                    }else
                    {
                        system("cls");
                        printf("**********HISTORIA**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user2].nombre);
                        system("pause");
                        system("cls");
                        printf("**********HISTORIA**********\n\n");

                        score2 = historia(0);
                        printf("SU SCORE FUE DE %d\n\n", score2);
                        system("pause");
                    }
                    cont++;
                }while (cont < 3);

                if(score1 > score2){
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user1].nombre);
                    gan1++;
                    system("pause");
                }else{
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user2].nombre);
                    gan2++;
                    system("pause");
                }
                cont = 1;
                ronda++;
            }while(ronda < 3);

            if(gan1 > gan2)
            {
                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");

            }else
            {
                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }
            ronda = 0;
            break;

        case '4':
            do{
                do{
                    if(cont == 1){
                        system("cls");
                        printf("**********GEOGRAFIA**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user1].nombre);
                        system("pause");
                        system("cls");
                        printf("**********GEOGRAFIA**********\n\n");

                        score1 = geografia(0);
                        printf("SU SCORE FUE DE %d\n\n", score1);
                        system("pause");

                    }else{
                        system("cls");
                        printf("**********GEOGRAFIA**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user2].nombre);
                        system("pause");
                        system("cls");
                        printf("**********GEOGRAFIA**********\n\n");

                        score2 = geografia(0);
                        printf("SU SCORE FUE DE %d\n\n", score2);
                        system("pause");
                    }
                    cont++;
                }while (cont < 3);

                if(score1 > score2){
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user1].nombre);
                    system("pause");
                }else{
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user2].nombre);
                    system("pause");
                }
                cont = 1;
                ronda++;
            }while(ronda < 3);

            if(gan1 > gan2){
                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }else{
                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }
            ronda = 0;
            break;

        case '5':
            do{
                do{
                    if(cont == 1){

                        system("cls");
                        printf("**********DEPORTES**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user1].nombre);
                        system("pause");
                        system("cls");
                        printf("**********DEPORTES**********\n\n");

                        score1 = deporte(0);
                        printf("SU SCORE FUE DE %d\n\n", score1);
                        system("pause");
                    }else{

                        system("cls");
                        printf("**********DEPORTES**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user2].nombre);
                        system("pause");
                        system("cls");
                        printf("**********DEPORTES**********\n\n");

                        score2 = deporte(0);
                        printf("SU SCORE FUE DE %d\n\n", score2);
                        system("pause");
                    }
                    cont++;
                }while (cont < 3);

                if(score1 > score2){
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user1].nombre);
                    system("pause");
                }else{
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user2].nombre);
                    system("pause");
                }
                cont = 1;
                ronda++;
            }while(ronda < 3);

            if(gan1 > gan2){
                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }else{
                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }
            ronda = 0;
            break;

        case '6':
            do{
                do{
                    if(cont == 1){

                        system("cls");
                        printf("**********MUSICA**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user1].nombre);
                        system("pause");
                        system("cls");
                        printf("**********MUSICA**********\n\n");

                        score1 = musica(0);
                        printf("SU SCORE FUE DE %d\n\n", score1);
                        system("pause");

                    }else{

                        system("cls");
                        printf("**********MUSICA**********\n\n");
                        printf("TURNO DE %s!\n", registrados[user2].nombre);
                        system("pause");
                        system("cls");
                        printf("**********MUSICA**********\n\n");

                        score2 = musica(0);
                        printf("SU SCORE FUE DE %d\n\n", score2);
                        system("pause");
                    }
                    cont++;
                }while (cont < 3);

                if(score1 > score2){
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user1].nombre);
                    system("pause");
                }else{
                    printf("\n%s HA GANADO LA BATALLA!!\n\n", registrados[user2].nombre);
                    system("pause");
                }
                cont = 1;
                ronda++;
            }while(ronda < 3);

            if(gan1 > gan2){
                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }else{
                printf("\n%s HA GANADO LA GUERRA!!\n\n", registrados[user1].nombre);
                system("pause");
            }

            ronda = 0;
            break;

        case '7':
            return 1;
            break;
    }

    return 1;
}

int quickgame(JUGADOR *registrados, int cant){

    int user, result, categoria, ind;
    char nom[MAXCARACT], pass[MAXPASS], chars;

    system("cls");

    do
    {
        gotoxy(40,2);
        printf("INICIO DE SESION\n\n");
        ind = 0;

        do{
            printf("Ingrese nombre de USUARIO: ");
            fflush(stdin);
            gets(nom);

            user = existusuario(registrados,cant,nom);

            if(user == -1){
                printf("Usuario no registrado\n\n");
                getch();
                system("cls");
            }

        }while(user == -1);

        printf("Ingrese contrase%ca: ", 164);
        fflush(stdin);

        while( (chars = getch()) )
        {
            if(chars == 13)
            {
                pass[ind] = '\0';
                break;
            }
            else if(chars == 8)
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
                    pass[ind] = chars;
                    ind++;
                }
            }
        }
//        gets(pass);
        if(strcmp(pass, registrados[user].contra) != 0){
            printf("\nCONTRASE%cA INCORRECTA\n\n", 165);
            getch();
            system("cls");
        }

    }while(strcmp(pass, registrados[user].contra) != 0 || user == -1);

    system("cls");

    gotoxy(40,2);
    printf("%cBIENVENIDO \" %s \"!",173,registrados[user].nombre);

    categoria = randrango(1,6);

    switch(categoria){

        case 1:
            system("cls");
            printf("**********SERIES de TV**********\n\n");
            system("pause");
            system("cls");
            printf("**********SERIES de TV**********\n\n");

            result = series(1);
            printf("SU RESULTADO FUE %d!\n\n", result);
            system("pause");
            break;

        case 2:
            system("cls");
            printf("**********PELICULAS**********\n\n");
            system("pause");
            system("cls");
            printf("**********PELICULAS**********\n\n");

            result = peliculas(1);
            printf("SU RESULTADO FUE %d!\n\n", result);
            system("pause");
            break;

        case 3:
            system("cls");
            printf("**********HISTORIA**********\n\n");
            system("pause");
            system("cls");
            printf("**********HISTORIA**********\n\n");

            result = historia(1);
            printf("SU RESULTADO FUE %d!\n\n", result);
            system("pause");
            break;

        case 4:
            system("cls");
            printf("**********GEOGRAFIA**********\n\n");
            system("pause");
            system("cls");
            printf("**********GEOGRAFIA**********\n\n");

            result = geografia(1);
            printf("SU RESULTADO FUE %d!\n\n", result);
            system("pause");
            break;

        case 5:
            system("cls");
            printf("**********DEPORTES**********\n\n");
            system("pause");
            system("cls");
            printf("**********DEPORTES**********\n\n");

            result = deporte(1);
            printf("SU RESULTADO FUE %d!\n\n", result);
            system("pause");
            break;

        case 6:
            system("cls");
            printf("**********MUSICA**********\n\n");
            system("pause");
            system("cls");
            printf("**********MUSICA**********\n\n");

            result = musica(1);
            printf("SU RESULTADO FUE %d!\n\n", result);
            system("pause");
            break;

        default:
            return -1;

    }

    return 1;
}

void guardar_highscore(JUGADOR usuario, int score)
{
    FILE *arch;

    if( (arch = fopen(NOMBRESCORES, "ab")) == NULL){
        printf("\nARCHIVO NO ENCONTRADO\n");
        exit(-1);
    }

    strcpy(resul.nombre, usuario.nombre);
    resul.score = score;

    fprintf(arch, "%s %d", resul.nombre, resul.score);

    fclose(arch);

    return;
}

void mostrar_highscores()
{
    FILE *arch;
    int ind = 1;

    if( (arch = fopen(NOMBRESCORES, "rb")) == NULL )
    {
        printf("\nNO HAY PARTIDAS GUARDADAS\n");
        system("pause");
        return;
    }

    printf("\n*******************************RESULTADOS ANTERIORES*******************************\n\n");
    while(fscanf(arch,"%s %d",resul.nombre,&resul.score) != EOF)
    {
        printf("No. %d: USUARIO: %s ---- SCORE:  %d\n", ind, resul.nombre,resul.score);
        ind++;
    }

    fclose(arch);
    system("pause");
    return;

}

int existusuario(JUGADOR *usu,int n, char nombre[])
{
    int ind;

    for (ind = 0; ind < n; ind ++){
        if ( stricmp(usu[ind].nombre, nombre) == 0 )
        {
            return ind;
        }
    }

    return -1;
}

long tamarch(FILE *arch)
{
    long posactual, totalbytes;

    // Tomar la posición del puntero
    posactual = ftell(arch);
    // Colocando puntero al final
    fseek(arch,0L,SEEK_END);
    // Tomando la cantidad de bytes del archivo
    totalbytes = ftell(arch);
    // Colocando el puntero en la posición original
    fseek(arch,posactual,SEEK_SET);

    return totalbytes;

}

void getpassword(JUGADOR *usuario)
{
    int ind;
    char chars;

    do
    {
        ind = 0;
        printf("Ingrese su contrase%ca: ",164);

        while( (chars = getch()) )
        {
            if(chars == 13)
            {
                usuario->contra[ind] = '\0';
                break;
            }
            else if(chars == 8)
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

int series(int quick)
{
    int valsinds[MAXPREGS];
    int ind, num, vidas, n, rightans, score = 0;
    char respusu;

    if(quick !=0 ){
        n = 5;
    }else if (quick == 0){
        n = MAXPREGS;
    }

    for ( ind = 0, num = 0; ind < n; ind ++ )
    {
        do
        {
            num = randrango(0,19);
        }while( existe(valsinds,MAXPREGS, num) );

        valsinds[ind] = num;
    }

    if(quick !=0 )
    {
        for (ind = 0; ind < n; ind++)
        {
            rightans = preguntaseries(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                printf("SCORE: %d\n\n", score);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\n\n", score);
            }
        }

    }else{
        for (vidas = 3, ind = 0; vidas >= 1; ind++)
        {
            rightans = preguntaseries(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                vidas--;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);
            }
            if(ind == n-1)
                break;
        }
    }
    return score;
}

int peliculas(int quick)
{
    int valsinds[MAXPREGS];
    int ind, num, vidas, n, rightans, score = 0;
    char respusu;

    if(quick !=0 ){
        n = 5;
    }else if (quick == 0){
        n = MAXPREGS;
    }

    for ( ind = 0, num = 0; ind < n; ind ++ )
    {
        do
        {
            num = randrango(0,19);
        }while( existe(valsinds,MAXPREGS, num) );

        valsinds[ind] = num;
    }

    if(quick !=0 )
    {
        for (ind = 0; ind < n; ind++)
        {
            rightans = preguntapelicula(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");

            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                printf("SCORE: %d\n\n", score);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\n\n", score);
            }
        }

    }else
    {
        for (vidas = 3, ind = 0; vidas >= 1; ind++)
        {
            rightans = preguntapelicula(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                vidas--;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);
            }

            if(ind == n-1)
                break;
        }
    }
    return score;
}

int historia(int quick)
{
    int valsinds[MAXPREGS];
    int ind, num, vidas, n, rightans, score = 0;
    char respusu;

    if(quick !=0 ){
        n = 5;
    }else if (quick == 0){
        n = MAXPREGS;
    }

    for ( ind = 0, num = 0; ind < n; ind ++ )
    {
        do
        {
            num = randrango(0,19);
        }while( existe(valsinds,MAXPREGS, num) );

        valsinds[ind] = num;
    }

    if(quick != 0)
    {
        for (ind = 0; ind < n; ind++)
        {
            rightans = preguntahistoria(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                printf("SCORE: %d\n\n", score);
            }else
            {
                printf("RESPUESTA CORRECTA!\t\n");
                score+=5;
                printf("SCORE: %d\n\n", score);
            }
        }

    }else
    {
        for (vidas = 3, ind = 0; vidas >= 1; ind++)
        {
            rightans = preguntahistoria(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                vidas--;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);

            }else
            {
                printf("RESPUESTA CORRECTA!\t\n");
                score+=5;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);
            }
            if(ind == n-1)
                break;
        }
    }
    return score;
}

int geografia(int quick)
{
    int valsinds[MAXPREGS];
    int ind, num, vidas, n, rightans, score = 0;
    char respusu;

    if(quick !=0 ){
        n = 5;
    }else if (quick == 0){
        n = MAXPREGS;
    }

    for ( ind = 0, num = 0; ind < n; ind ++ )
    {
        do
        {
            num = randrango(0,19);
        }while( existe(valsinds,MAXPREGS, num) );

        valsinds[ind] = num;
    }

    if(quick !=0 )
    {
        for (ind = 0; ind < n; ind++)
        {
            rightans = preguntageografia(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                printf("SCORE: %d\n\n", score);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\n\n", score);
            }
        }

    }else
    {
        for (vidas = 3, ind = 0; vidas >= 1; ind++)
        {
            rightans = preguntageografia(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                vidas--;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);
            }
            if(ind == n-1)
                break;
        }
    }
    return score;
}

int deporte(int quick)
{
    int valsinds[MAXPREGS];
    int ind, num, vidas, n, rightans, score = 0;
    char respusu;

    if(quick !=0 ){
        n = 5;
    }else if (quick == 0){
        n = MAXPREGS;
    }

    for ( ind = 0, num = 0; ind < n; ind ++ )
    {
        do
        {
        num = randrango(0,19);
        }while( existe(valsinds,MAXPREGS, num) );

        valsinds[ind] = num;
    }

    if(quick !=0 )
    {
        for (ind = 0; ind < n; ind++)
        {
            rightans = preguntadeportes(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                printf("SCORE: %d\n\n", score);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\n\n", score);
            }
        }

    }else
    {
        for (vidas = 3, ind = 0; vidas >= 1; ind++)
        {
            rightans = preguntadeportes(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");
            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                vidas--;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);
            }
            if(ind == n-1)
                break;
        }
    }
    return score;
}

int musica(int quick)
{
    int valsinds[MAXPREGS];
    int ind, num, vidas, n, rightans, score = 0;
    char respusu;

    if(quick != 0){
        n = 5;
    }else if (quick == 0){
        n = MAXPREGS;
    }

    for ( ind = 0, num = 0; ind < n; ind ++ )
    {
        do
        {
            num = randrango(0,19);
        }while( existe(valsinds,MAXPREGS, num) );

        valsinds[ind] = num;
    }

    if(quick !=0 )
    {
        for (ind = 0; ind < n; ind++)
        {
            rightans = preguntamusica(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");

            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                printf("SCORE: %d\n\n", score);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\n\n", score);
            }
        }

    }else
    {
        for (vidas = 3, ind = 0; vidas >= 1; ind++)
        {
            rightans = preguntamusica(valsinds[ind]);
            do
            {
                respusu = tolower(getch());
                printf("\nSu respuesta: ");
                putch(respusu);
                printf("\n");

            }while( respusu != 'a' && respusu != 'b' && respusu != 'c' && respusu != 'd');

            if(respusu != rightans)
            {
                printf("RESPUESTA INCORECTA\n");
                printf("LA RESPUESTA CORRECTA ES LA %c\n\n", rightans);
                vidas--;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);

            }else
            {
                printf("RESPUESTA CORRECTA!\n");
                score+=5;
                printf("SCORE: %d\t VIDAS: %d\n\n", score, vidas);
            }
            if(ind == n-1)
                break;
        }
    }
    return score;
}

int existe(int arr[], int n, int val)
{
   int ind;

   for ( ind = 0; ind < n; ind ++ )
      if ( arr[ind] == val )
         return 1;

   return 0;
}

int ayuda()
{
    FILE *arch;

    if ( (arch = fopen(ARCHAYUDA,"rt")) == NULL )
    {
        printf("El archivo %s, no existe.\n",ARCHAYUDA);
        exit(-1);
    }

    char caract;

    while ( (caract = fgetc(arch)) != EOF )
    {
        fputc(caract,stdout);
    }

    fclose(arch);
    printf("\n");
    system("pause");

    return 1;
}

int creditos()
{
    FILE *arch;

    if ( (arch = fopen(ARCHCREDS,"rt")) == NULL )
    {
        printf("El archivo %s, no existe.\n",ARCHAYUDA);
        exit(-1);
    }

    char caract;

    while ( (caract = fgetc(arch)) != EOF )
    {
        fputc(caract,stdout);
    }

    fclose(arch);
    printf("\n");
    system("pause");

    return 1;
}

int randrango(int a,int b)
{
   return rand() % (b-a+1) + a;
}

int preguntaseries(int aleat)
{
    switch (aleat){
        case 0:
            printf("%cQu%c serie cuenta la historia de Ted Mosby?\n",168, 130);
            printf("a) The Big Bang Theory\n");
            printf("b) The Office\n");
            printf("c) Friends\n");
            printf("d) How I Met Your Mother\n");
            return 'd';
            break;

        case 1:
            printf("%cSteve Carell intrepreta a Michael Scott en qu%c serie?\n",168, 130);
            printf("a) The Office\n");
            printf("b) Modern Family\n");
            printf("c) Two and a Half Men\n");
            printf("d) The Big Bang Theory\n");
            return 'a';
            break;

        case 2:
            printf("%cJason Segel intrepreta a Marshall Eriksen en que serie?\n",168);
            printf("a) The Office \n");
            printf("b) How I Met Your Mother\n");
            printf("c) Friends\n");
            printf("d) The Big Bang Theory\n");
            return 'b';
            break;

        case 3:
            printf("%cCu%cl de los siguientes actores no actu%c en Friends\n", 168, 160, 162);
            printf("a) Paul Rudd\n");
            printf("b) Tom Cruise\n");
            printf("c) Robin Williams\n");
            printf("d) Bruce Willis\n");
            return 'b';
            break;

        case 4:
            printf("%cEn qu%c serie Peter Dinklage interpreta a Tyrion?\n", 168, 130);
            printf("a) Game of Thrones\n");
            printf("b) Breaking Bad\n");
            printf("c) Two and a Half Men\n");
            printf("d) Friends\n");
            return 'a';
            break;

        case 5:
            printf("%cI'll be There for You es la canci%cn de intro de que serie?\n", 168,162);
            printf("a) How I Met Your Mother\n");
            printf("b) The Office\n");
            printf("c) Friends\n");
            printf("d) Two and a Half Men\n");
            return 'c';
            break;

        case 6:
            printf("Actriz que protagoniz%c la serie Buffy the Vampire Slayer\n", 162);
            printf("a) Jennifer Aniston\n");
            printf("b) Sarah Michelle Gellar\n");
            printf("c) Anne Hathaway\n");
            printf("d) Cate Blanchett\n");
            return 'b';
            break;

        case 7:
            printf("%cCu%cl de los siguientes actores estuvo en la serie Parks and Recreation?\n",168, 160);
            printf("a) Chris Rock\n");
            printf("b) Chris Evans\n");
            printf("c) Chris Hemsworth\n");
            printf("d) Chris Pratt\n");
            return 'd';
            break;

        case 8:
            printf("%cCu%cl serie es mejor que Friends?\n", 168, 160);
            printf("a) The Office\n");
            printf("b) How I Met Your Mother\n");
            printf("c) Ninguna\n");
            printf("d) Atrevete a decir ninguna\n");
            return 'a';
            break;

        case 9:
            printf("Esta banda proporcion%c la canci%cn de intro de Phineas and Ferb:\n", 162, 162);
            printf("a) Simple Plan\n");
            printf("b) Bowling for Soup\n");
            printf("c) Green Day\n");
            printf("d) Panic! At The Disco\n");
            return 'b';
            break;

        case 10:
            printf("En esta serie animada, el protagonista, al mirar la luna llena, se transforma en un gran mono y asesina a su abuelo:\n");
            printf("a) Dragon Ball\n");
            printf("b) Steven Universe\n");
            printf("c) Naruto\n");
            printf("d) Ben 10\n");
            return 'a';
            break;

        case 11:
            printf("%cQui%cn vive en una piña debajo del mar?\n", 168, 130);
            printf("a) Bob Esponja\n");
            printf("b) Patricio Estrella\n");
            printf("c) Calamardo Tentaculos\n");
            printf("d) Si se me acabaron ideas, dame un break\n");
            return 'a';
            break;

        case 12:
            printf("%cEn qu%c a%co se estren%c la serie Rugrats?\n", 168, 130, 164, 162);
            printf("a) 1991\n");
            printf("b) 1993\n");
            printf("c) 1995\n");
            printf("d) 1989\n");
            return 'a';
            break;

        case 13:
            printf("%cEn esta serie, su protagonista es un gato robot c%csmico del futuro:\n", 168, 162);
            printf("a) Doraemon\n");
            printf("b) Cat-Dog\n");
            printf("c) Don Gato\n");
            printf("d) Garfield\n");
            return 'a';
            break;

        case 14:
            printf("Bill Cypher es el antagonista principal de esta serie:\n");
            printf("a) Rick y Morty\n");
            printf("b) Big Mouth\n");
            printf("c) Gravity Falls\n");
            printf("d) Steven Universe\n");
            return 'c';
            break;

        case 15:
            printf("Inici%c como una parodia de la pelicula de los 80s Volver al Futuro:\n", 162);
            printf("a) Un show m%cs\n", 160);
            printf("b) Samurai Jack\n");
            printf("c) El laboratorio de Dexter\n");
            printf("d) Rick y Morty\n");
            return 'd';
            break;

        case 16:
            printf("%cC%cmo se llaman los protagonistas de Hora de Aventura?\n", 168, 162);
            printf("a) Mordecai y Rigby\n");
            printf("b) Finn y Jake\n");
            printf("c) Gumball y Darwin\n");
            printf("d) Pinky y Cerebro\n");
            return 'b';
            break;

        case 17:
            printf("%cEn qu%c a%co se estren%c la serie animada de Pokem%cn?\n", 168, 130, 164, 162, 162);
            printf("a) 1996\n");
            printf("b) 1994\n");
            printf("c) 2000\n");
            printf("d) 1997\n");
            return 'd';
            break;

        case 18:
            printf("Gan%c Mejor serie animada en los Critics' Choice Television Awards 2018:\n", 162);
            printf("a) Rick y Morty\n");
            printf("b) Hora de Aventura\n");
            printf("c) Carmen Sandiego\n");
            printf("d) Big Mouth\n");
            return 'a';
            break;

        case 19:
            printf("Asta es el protagonista de:\n");
            printf("a) One Piece\n");
            printf("b) Big Mouth\n");
            printf("c) Black Clover\n");
            printf("d) Bleach\n");
            return 'c';
            break;

        case 20:
            printf("JG Quintel es el creador de:\n");
            printf("a) Rick y Morty\n");
            printf("b) Un show m%cs\n", 160);
            printf("c) Hora de Aventura\n");
            printf("d) Ducktales\n");
            return 'b';
            break;

        case 21:
            printf("En un episodio de South Park, Cartman sali%c en b%csqueda de su verdadero padre, %cqui%cn result%c serlo?", 162, 163, 168, 130, 162);
            printf("a) Chef\n");
            printf("b) Sr. Garrison\n");
            printf("c) El equipo de los Denver Broncos\n");
            printf("d) Sra. Cartman\n");
            return 'd';
            break;
    }
    return -1;
}

int preguntapelicula(int aleat){

    switch(aleat){

        case 0:
            printf("%cQui%cn interpreta al Joker en la pel%ccula Batman?\n", 168, 130, 161);
            printf("a) Nicholas Cage\n");
            printf("b) Jack Nicholson\n");
            printf("c) Michael Keaton\n");
            printf("d) Heath Ledger\n");
            return 'b';
            break;

        case 1:
            printf("%cQu%c clase de pie cocina la mama de Jim en American Pie?", 168, 130);
            printf("a) Pie de manzana\n");
            printf("b) Pie de cereza\n");
            printf("c) Pie de calabaza\n");
            printf("d) Pie de fresa\n");
            return 'a';
            break;

        case 2:
            printf("Pel%ccula con mayor recaudaci%cn durante los 2000s\n", 161, 162);
            printf("a) Kill Bill\n");
            printf("b) The Dark Knight\n");
            printf("c) Inglourious Basterds\n");
            printf("d) Avatar\n");
            return 'd';
            break;

        case 3:
            printf("%cQu%c clase de negocio quer%can poner Forrest y Bubba en la pel%ccula Forrest Gump?\n", 168, 130, 161, 161);
            printf("a) Una gasolinera\n");
            printf("b) Una tienda de ropa\n");
            printf("c) Un restaurante\n");
            printf("d) Un bar\n");
            return 'c';
            break;

        case 4:
            printf("%cQu%c descubre Truman Burbank en la pel%ccula The Truman Show?\n", 168, 130, 161);
            printf("a) Toda su vida ha sido una mentira\n");
            printf("b) Toda su familia est%c muerta\n", 160);
            printf("c) Su esposa est%c embarazada\n", 160);
            printf("d) Su hijo ha fallecido\n");
            return 'a';
            break;

        case 5:
            printf("%cEn cu%cles de las siguientes pel%ccula NO aparece Adam Sandler?\n", 168, 160, 161);
            printf("a) The Wedding Singer\n");
            printf("b) Grown-ups\n");
            printf("c) Longest Yard\n");
            printf("d) Meet the Parents\n");
            return 'd';
            break;

        case 6:
            printf("Es la voz de Woody en la pelicula Toy Story\n");
            printf("a) Tim Allen\n");
            printf("b) Tom Hanks\n");
            printf("c) Woody Allen\n");
            printf("d) Matthew Broderick\n");
            return 'b';
            break;

        case 7:
            printf("%cEn qu%c a%co se estren%c la pel%ccula Bambi\n", 168, 130, 164, 162, 161);
            printf("a) 1961\n");
            printf("b) 1941\n");
            printf("c) 1981\n");
            printf("d) 1971\n");
            return 'b';
            break;

        case 8:
            printf("Gan%c el premio de mejor pelicula animada en los Academy Awards (2019)\n",162);
            printf("a) Spider-Man: Into the Spider-Verse\n");
            printf("b) Incredibles 2\n");
            printf("c) Mirai\n");
            printf("d) Ralph Breaks the Internet\n");
            return 'a';
            break;

        case 9:
            printf("Bohemian Rhapsody narra sobre la vida de:\n");
            printf("a) Billie Joe Armstrong\n");
            printf("b) Billy Joel\n");
            printf("c) Freddie Mercury\n");
            printf("d) Elton John\n");
            return 'c';
            break;

        case 10:
            printf("Pel%ccula por la cual Leonardo DiCaprio gan%c su primer Academy Award:\n", 161, 162);
            printf("a) The Wolf of Wall Street\n");
            printf("b) Revenant\n");
            printf("c) Blood Diamond\n");
            printf("d) Shutter Island\n");
            return 'b';
            break;

        case 11:
            printf("%cEn cu%cl pel%ccula Steve Carrell act%ca como un supervisor de mercanc%ca?\n",168,160,161,163,161);
            printf("a) The 40-Year-Old Virgin\n");
            printf("b) Anchorman\n");
            printf("c) Bruce Almighty\n");
            printf("d) Dinner for Schmucks\n");
            return 'a';
            break;

        case 12:
            printf("%cQui%cn hace el papel de Seth en la pelicula Superbad?\n",168,130);
            printf("a) Jonah Hill\n");
            printf("b) Seth Rogen\n");
            printf("c) Michael Cera\n");
            printf("d) Bill Hader\n");
            return 'a';
            break;

        case 13:
            printf("%cPor qu%c Wade Wilson usa una mascara?\n",168,130);
            printf("a) Porque tiene todo su cuerpo quemado\n");
            printf("b) No quiere que su identidad sea revelada\n");
            printf("c) Tiene miedo al p%cblico\n",163);
            printf("d) Porque s%c. Es Deadpool, %cl puede usar lo que quiera\n",161,130);
            return 'a';
            break;

        case 14:
            printf("%cCon cu%cl canci%cn Doug y Steve mueven la cabeza en la pelicula Night at the Roxbury?\n",168,160,162);
            printf("a) Careless Whisper\n");
            printf("b) What is Love\n");
            printf("c) You Spin me Round (Like a Record)\n");
            printf("d) Girls Just Want to Have Fun\n");
            return 'b';
            break;

        case 15:
            printf("%cQu%c responde Harry Potter cuando Hagrid le dice: \"Harry, eres un mago\"?\n",168,130);
            printf("a) Ya lo sab%ca\n",161);
            printf("b) Yo soy un qu%c?!\n",130);
            printf("c) No, no lo soy\n");
            printf("d) Por qu%c me dices esto?\n",130);
            return 'b';
            break;

        case 16:
            printf("Es el tercer humano que logra entrar al mundo de los Looney Tunes en Space Jam:\n");
            printf("a) Bill Murray\n");
            printf("b) Larry Bird\n");
            printf("c) Charles Barkley\n");
            printf("d) Ninguno de los anteriores\n");
            return 'a';
            break;

        case 17:
            printf("%cEn qu%c ciudad est%c basada la pelicula Sex and the City?\n",168,130,160);
            printf("a) New York\n");
            printf("b) Las Vegas\n");
            printf("c) Los Angeles\n");
            printf("d) Chicago\n");
            return 'a';
            break;

        case 18:
            printf("%cCu%cl personaje de marvel fue introducido al MCU en la pelicula Captain America: Civil War?\n",168,160);
            printf("a) Winter Soldier\n");
            printf("b) Falcon\n");
            printf("c) Spider-Man\n");
            printf("d) Ant-Man\n");
            return 'c';
            break;

        case 19:
            printf("%cQui%cn interpreta a Buddy en la pelicula Elf?\n",168,130);
            printf("a) Adam Sandler\n");
            printf("b) Tim Allen\n");
            printf("c) Will Ferrell\n");
            printf("d) Paul Rudd\n");
            return 'c';
            break;
    }
    return -1;
}

int preguntamusica(int aleat){

    switch(aleat){

        case 0:
            printf("Su primer sencillo Ocean Eyes se hizo viral en Soundcloud y Spotify, ganando m%cs de dos millones de reproducciones en su primer a%co:\n", 160, 164);
            printf("a) Finneas O´Connell\n");
            printf("b) Lizzo\n");
            printf("c) Billie Eilish\n");
            printf("d) Frank Ocean\n");
            return 'c';
            break;

        case 1:
            printf("Esta banda proporcion%c la canci%cn de intro para la serie animada %cQu%c hay de nuevo, Scooby-Doo?:\n", 162, 162, 168, 130);
            printf("a) Simple Plan\n");
            printf("b) Bowling for Soup\n");
            printf("c) Green Day\n");
            printf("d) Yellowcard\n");
            return 'b';
            break;

        case 2:
            printf("Esta canci%cn gan%c el premio canci%cn del a%co en los Grammys Music Awards 2019:\n", 162, 162, 162, 164);
            printf("a) This is America\n");
            printf("b) Rockstar\n");
            printf("c) Shallow\n");
            printf("d) I like it\n");
            return 'a';
            break;

        case 3:
            printf("Gan%c un Grammy por su canci%cn Just The Way You Are (Canci%con del a%co):\n", 162, 162, 162, 164);
            printf("a) Bruno Mars\n");
            printf("b) Billy Joel\n");
            printf("c) U2\n");
            printf("d) Coldplay\n");
            return 'b';
            break;

        case 4:
            printf("Gan%c el premio grabaci%cn del a%co en los Grammys Music Awards 2013:\n", 162, 162, 164);
            printf("a) Somebody That I Used to Know\n");
            printf("b) Stronger (What Doesn't Kill You)\n");
            printf("c) We Are Young\n");
            printf("d) We Are Never Ever Getting Back Together\n");
            return 'a';
            break;

        case 5:
            printf("%cCu%cl de las siguientes es una canci%cn de Green Day?\n", 168, 160, 162);
            printf("a) Whatsername\n");
            printf("b) In too Deep\n");
            printf("c) I Write Sins, not Tragedies\n");
            printf("d) Under Cover of Darkeness\n");
            return 'a';
            break;

        case 6:
            printf("%cGan%c alb%cm del a%co en los Grammys Music Awards 2014:\n", 168, 162, 163, 164);
            printf("a) Random Access Memories\n");
            printf("b) Good Kid, M.A.A.D City\n");
            printf("c) The Heist\n");
            printf("d) Red\n");
            return 'a';
            break;

        case 7:
            printf("Se hicieron de mucha popularidad en los 80s por su hit Africa:\n");
            printf("a) Toto\n");
            printf("b) The Police\n");
            printf("c) Duran Duran\n");
            printf("d)Men at Work\n");
            return 'a';
            break;

        case 8:
            printf("%cCu%cl de las siguientes canciones pertenece al d%co musical Daryl Hall & John Oates?\n", 168, 160, 163);
            printf("a) Africa\n");
            printf("b) You Make My Dreams\n");
            printf("c) Down Under\n");
            printf("d) Kiss from a Rose\n");
            return 'b';
            break;

        case 9:
            printf("Banda que se populariz%c en los 2000s con canciones como S.O.S y Hold On:\n", 162);
            printf("a) Coldplay\n");
            printf("b)Jonas Brothers\n");
            printf("c)Panic! At The Disco\n");
            printf("d)Fall Out Boy\n");
            return 'b';
            break;

        case 10:
            printf("Es el video musical con m%cs visitas en YouTube:\n", 160);
            printf("a) Despacito\n");
            printf("b) Gangnam Style\n");
            printf("c) Roar\n");
            printf("d) When I See You Again\n");
            return 'a';
            break;

        case 11:
            printf("%cEn qu%c ciudad surgi%c el Jazz?\n", 168, 130, 162);
            printf("a) Nueva York\n");
            printf("b) Paris\n");
            printf("c) Nueva Orleans\n");
            printf("d) Memphis\n");

            return 'c';
            break;

        case 12:
            printf("%cCu%cl es el nombre art%cstico de Peter Hern%cndez?\n", 168, 160, 161, 160);
            printf("a) Daddy Yankee\n");
            printf("b) Bruno Mars\n");
            printf("c) Eminem\n");
            printf("d) Snoop Dogg\n");
            return 'b';
            break;

        case 13:
            printf("%cQu%c famosa cantante, ya fallecida, se le consideraba la figura principal de la m%csica ranchera?\n", 168, 130, 163);
            printf("a) Jenny Rivera\n");
            printf("b) Selena Quintanilla\n");
            printf("c) Lola Beltr%cn\n", 160);
            printf("d) Chavela Vargas\n");

            return 'd';
            break;

        case 14:
            printf("%cCu%cl es la %cnica banda de rock de la historia en la que cada miembro ha compuesto una canci%cn que ha llegado a ser n%cmero uno como single?\n", 168, 160, 163, 162, 163);
            printf("a) Queen\n");
            printf("b) The beatles\n");
            printf("c) Nirvana\n");
            printf("d) The Rolling Stones\n");

            return 'a';
            break;

        case 15:
            printf("%cQu%c cantante espa%cola tiene en su haber el mayor n%cmero de Grammy latinos por un solo trabajo?\n", 168,130,164,163);
            printf("a) Rosario\n");
            printf("b) Rosal%ca\n", 161);
            printf("c) Natalia Jimenez\n");
            printf("d) Roc%co D%crcal\n", 161, 163);

            return 'b';
            break;

        case 16:
            printf("%cC%cmo se denomina al subg%cnero musical del rap que mezcla rap, hip hop y dubstep?\n", 168, 162, 130);
            printf("a) Trap\n");
            printf("b) Old school\n");
            printf("c) Frat rap\n");
            printf("d) Gangsta rap\n");

            return 'a';
            break;

        case 17:
            printf("%cD%cnde Michael Jackson hizo su primer Moonwalk?\n", 168, 162);
            printf("a) Concierto en Bucharest\n");
            printf("b) Grammys de 1983\n");
            printf("c) Motown 25\n");
            printf("d) En su Bad World Tour\n");

            return 'c';
            break;

        case 18:
            printf("%cCu%cl de estas canciones no es del grupo musical Queen?\n", 168, 160);
            printf("a) Don't Stop Me Now\n");
            printf("b) Where are We Now?\n");
            printf("c) Tie your mother down\n");
            printf("d) These are the days of our lives\n");

            return 'b';
            break;

        case 19:
            printf("%cCu%cl era el nombre original de Maroon 5?\n", 168, 160);
            printf("a) Kara's flowers\n");
            printf("b) The dead flowers\n");
            printf("c) The wild flowers\n");
            printf("d) Kelly's flowers\n");

            return 'a';
            break;
    }
    return -1;
}

int preguntadeportes(int aleat){

    switch(aleat){

        case 0:
            printf("%cEn cu%cntos equipos jug%c Michael Jordan durante su carrera en la NBA?\n", 168, 160, 162);
            printf("a) 1\n");
            printf("b) 2\n");
            printf("c) 4\n");
            printf("d) Ninguna de las anteriores\n");
            return 'b';
            break;

        case 1:
            printf("Gan%c el premio novato del a%co de la liga Americana de MLB en 2018", 162, 164);
            printf("a) Ronald Acuña Jr.\n");
            printf("b) Shohei Ohtani\n");
            printf("c) Gleyber Torres\n");
            printf("d) Juan Soto\n");
            return 'b';
            break;

        case 2:
            printf("Ganador del premio MVP de la liga nacional de MLB en 2014\n");
            printf("a) Clayton Kershaw\n");
            printf("b) Bryce Harper\n");
            printf("c) Andrew McCutchen\n");
            printf("d) Josh Donaldson\n");
            return 'a';
            break;

        case 3:
            printf("Campeones de la serie mundial de la MLB en 2018\n");
            printf("a) Boston Red Sox\n");
            printf("b) LA Dodgers\n");
            printf("c) Houston Astros\n");
            printf("d) Washington Nationals\n");
            return 'a';
            break;

        case 4:
            printf("Equipo con mayor cantidad de campeonatos de las finales de NBA en los 2000s\n");
            printf("a) LA Lakers\n");
            printf("b) Boston Celtics\n");
            printf("c) San Antonio Spurs\n");
            printf("d) Miami Heat\n");
            return 'a';
            break;

        case 5:
            printf("Tiene la mayor cantidad de premios MVP en la historia de la NBA\n");
            printf("a) Bill Russell\n");
            printf("b) Michael Jordan\n");
            printf("c) Kareen Abdul-Jabbar\n");
            printf("d) Wilt Chamberlain\n");
            return 'c';

        case 6:
            printf("%cCu%cntos campeonatos mundiales gan%c Ric Flair durante su carrera?\n", 168, 160, 162);
            printf("a) 16\n");
            printf("b) 20\n");
            printf("c) 21\n");
            printf("d) 18\n");
            return 'b';
            break;

        case 7:
            printf("Tiene el r%ccord de m%cs d%cas seguidos sosteniendo el campeonato de WWE\n", 130, 160, 161);
            printf("a) Steve Austin\n");
            printf("b) CM Punk\n");
            printf("c) John Cena\n");
            printf("d) Brock Lesnar\n");
            return 'd';
            break;

        case 8:
            printf("En nataci%cn, %ccu%cnto mide de largo una piscina de competici%cn para olimpiadas y mundiales?\n",162,168,160,162);
            printf("a) 25 metros\n");
            printf("b) 30 metros\n");
            printf("c) 40 metros\n");
            printf("d) 50 metros\n");

            return 'd';
            break;

        case 9:
            printf("En balonmano, si un equipo no tiene intenci%cn clara de atacar y pretende perder tiempo, el arbitro puede pitar...\n",162);
            printf("a) Reanudar juego\n");
            printf("b) Pasivo\n");
            printf("c) Pasos\n");
            printf("d) Gol\n");

            return 'b';
            break;

        case 10:
            printf("%cA qu%c altura est%c la canasta de baloncesto?\n", 168, 130, 162);
            printf("a) 3 metros\n");
            printf("b) 3,15 metros\n");
            printf("c) 3,09 metros\n");
            printf("d) 3,05 metros\n");

            return 'd';
            break;

        case 11:
            printf("Las tres modalidades de la esgrima son: sable, espada y...\n");
            printf("a) Florete\n");
            printf("b) Estoque\n");
            printf("c) Estilo libre\n");
            printf("d) Toque\n");

            return 'a';
            break;

        case 12:
            printf("%cC%cmo se llama en tenis un punto de saque directo?\n",168,162);
            printf("a) Rev%cs\n",130);
            printf("b) Ace\n");
            printf("c) De frente\n");
            printf("d) Flotante\n");

            return 'b';
            break;

        case 13:
            printf("%cCu%cl es el estilo de nataci%cn m%cs r%cpido?\n",168,160,162,160,160);
            printf("a) Mariposa\n");
            printf("b) Espalda\n");
            printf("c) Crol\n");
            printf("d) Pecho\n");

            return 'c';
            break;

        case 14:
            printf("%cC%cmo se llama la zona de hierba rasa donde est%c ubicado el hoyo en golf?\n",168,162,160);
            printf("a) Esplanada\n");
            printf("b) Green\n");
            printf("c) Campo\n");
            printf("d) Terreno\n");

            return 'b';
            break;

        case 15:
            printf("%cCu%cl es el club de f%ctbol m%cs antiguo de Espa%ca?\n",168,160,163,160,164);
            printf("a) Athletic Club de Bilbao\n");
            printf("b) F.C. Barcelona\n");
            printf("c) Real Madrid\n");
            printf("d) Recreativo de Huelva\n");

            return 'd';
            break;

        case 16:
            printf("%cQui%cn gan%c dos veces tres campeonatos consecutivamente en la NBA?\n",168,130,162);
            printf("a) LeBron James\n");
            printf("b) Michael Jordan\n");
            printf("c) Brian Scalabrine\n");
            printf("d) Bill Russel\n");

            return 'b';
            break;

        case 17:
            printf("%cCon qu%c se premiaba a los campeones ol%cmpicos de la antig%cedad?\n",168,130,161,129);
            printf("a) Corona de Laurel\n");
            printf("b) Medalla de Lat%cn\n",162);
            printf("c) Corona de espinas\n");
            printf("d) Medalla de esta%co",164);

            return 'a';
            break;

        case 18:
            printf("%cCu%cl de estas no es una prueba de decatl%cn?\n", 168, 160, 162);
            printf("a) Carrera de 1500m\n");
            printf("b) Marat%cn\n", 162);
            printf("c) Salto con p%crtiga\n", 130);
            printf("d) Lanzamiento de jabalina\n");

            return 'b';
            break;

        case 19:
            printf("En los Juego Ol%cmpicos de Invierno se compite en luge. %cQu%c es luge?\n",161,168,130);
            printf("a) Una pista de nieve horizontal\n");
            printf("b) Un trineo\n");
            printf("c) Una pista de patinaje\n");
            printf("d) Un tipo de esqu%c especial\n",161);

            return 'b';
            break;
    }

    return -1;

}

int preguntahistoria(int aleat){

    switch (aleat){

        case 0:
            printf("%cEn qu%c a%co el hombre pis%c la Luna por primera vez?\n", 168, 130, 164, 162);
            printf("a) 1967\n");
            printf("b) 1968\n");
            printf("c) 1970\n");
            printf("d) 1969\n");
            return 'd';
            break;

        case 1:
            printf("%cA partir de qu%c suceso se considera que termina la Edad Antigua y empieza la Edad Media?\n", 168, 130);
            printf("a) Con el descubrimiento de Am%crica\n", 130);
            printf("b) Con la ca%cda del Imperio Romano de Occidente\n", 161);
            printf("c) Con la ca%cda del Imperio Romano de Oriente\n", 161);
            printf("d)Con la aparici%cn del Islam\n", 162);
            return 'b';
            break;

        case 2:
            printf("%cCu%cnto dur%c la Guerra de los Cien A%cos?\n", 168, 160, 162, 164);
            printf("a) 116 a%cos\n", 164);
            printf("b) 114 a%cos\n", 164);
            printf("c) 117 a%cos\n", 164);
            printf("d) 115 a%cos\n", 164);
            return 'a';
            break;

        case 3:
            printf("%cEn qu%c a%co se cre%c la Organizaci%cn de las Naciones Unidas?\n", 168, 130, 164, 162, 162);
            printf("a) 1946\n");
            printf("b) 1940\n");
            printf("c) 1945\n");
            printf("d) 1943\n");
            return 'c';
            break;

        case 4:
            printf("%cQu%c isla sirvi%c de prisi%cn para Napole%cn tras su derrota en la batalla de Waterloo?\n", 168, 130, 162, 162, 162);
            printf("a) Madagascar\n");
            printf("b) Santa Elena\n");
            printf("c) Pemba\n");
            printf("d) Santa Mar%ca\n", 161);
            return 'b';
            break;

        case 5:
            printf("%cQui%cnes fueron, seg%cn la leyenda, los dos hermanos fundadores de la ciudad de Roma?\n", 168, 130, 163);
            printf("a) R%cmulo y Remo\n", 162);
            printf("b) Ascanio y Eneas\n");
            printf("c) Ascanio y Rómulo\n");
            printf("d) Numitor y Amulio\n");
            return 'a';
            break;

        case 6:
            printf("%cEn qu%c a%co se descubri%c Am%crica?\n", 168, 130, 164, 162, 130);
            printf("a) 1592\n");
            printf("b) 1492\n");
            printf("c) 1742\n");
            printf("d) 1842\n");
            return 'b';
            break;

        case 7:
            printf("%cEn qu%c a%co empez%c la segunda Guerra Mundial?\n", 168, 130, 164, 162);
            printf("a) 1917\n");
            printf("b) 1945\n");
            printf("c) 1939\n");
            printf("d) 1942\n");
            return 'c';
            break;

        case 8:
            printf("%cEn qu%c a%co el hombre pis%c la Luna por primera vez?\n", 168, 130, 164, 162);
            printf("a) 1969\n");
            printf("b) 1970\n");
            printf("c) 1962\n");
            printf("d) 1964\n");
            return 'a';
            break;

        case 9:
            printf("%cQui%cn fue el primer presidente de Estados Unidos?\n", 168, 130);
            printf("a) George Washington\n");
            printf("b) Benjamin Franklin\n");
            printf("c) John Adams\n");
            printf("d) Thomas Jefferson\n");
            return 'a';
            break;

        case 10:
            printf("%cQui%cn fue el primer presidente de Rep%cblica Dominicana?(Primera Rep%cblica)\n", 168, 130, 163, 163);
            printf("a) Juan Pablo Duarte\n");
            printf("b) Francisco del Rosario S%cnchez\n", 160);
            printf("c) Tom%cs Bobadilla y Briones\n", 160);
            printf("d) Pedro Santana\n");
            return 'd';
            break;

        case 11:
            printf("%cQu%c carabela no volvi%c del viaje en el que Col%cn arrib%c a Am%crica por primera vez?\n", 168, 130, 162, 162, 162, 130);
            printf("a) La ni%ca\n", 164);
            printf("b) La pinta\n");
            printf("c) La Santa Mar%ca\n", 161);
            printf("d) Todas volvieron\n");
            return 'c';
            break;

        case 12:
            printf("%cA qui%cn se le conoci%c como el Rey Tartamudo?\n",168,130,162);
            printf("a) Jorge VI del Reino Unido\n");
            printf("b) Jorge IV del Reino Unido\n");
            printf("c) Guillermo IV del Reino Unido\n");
            printf("d) Juan I de Inglaterra\n");

            return 'a';
            break;

        case 13:
            printf("%cQu%c trajo como consecuencia la Revolucion Francesa?\n", 168, 130);
            printf("a) Fin de la monarqu%ca francesa\n", 161);
            printf("b) Fin de la desigualdad social\n");
            printf("c) Fin de la esclavitud\n");
            printf("d) Creaci%cn de la organizaci%cn para los derechos humanos\n", 162, 162);

            return 'a';
            break;

        case 14:
            printf("%cQu%c motiv%c la rebeli%cn que di%c lugar a la Guerra de la Independencia de EEUU?\n", 168, 130, 162, 162, 162);
            printf("a) Impuesto\n");
            printf("b) Esclavitud\n");
            printf("c) Represi%cn\n", 162);
            printf("d) Todas las anteriores\n");

            return 'a';
            break;

        case 15:
            printf("%cDe qu%c estaba fabricado originalmente el maquillaje blanco de las geishas?", 168, 130);
            printf("a) Harina de arroz\n");
            printf("b) Plomo\n");
            printf("c) Flores\n");
            printf("d) Ninguna de las anteriores\n");

            return 'a';
            break;

        case 16:
            printf("%cQui%cn fue el presidente No. 64 de Rep%cblica Dominicana?\n", 168, 130, 163);
            printf("a) Danilo Medina\n");
            printf("b) Leonel Fern%cndez\n", 160);
            printf("c) Hip%clito Mej%ca\n", 162, 161);
            printf("d) Joaqu%cn Balaguer\n", 161);

            return 'c';
            break;

        case 17:
            printf("%cEn qu%c a%co ocurri%c la ca%cda del Muro de Berl%cn?\n", 168, 130, 164, 162, 161, 161);
            printf("a) 1989\n");
            printf("b) 1988\n");
            printf("c) 1990\n");
            printf("d) 1991\n");

            return 'a';
            break;

        case 18:
            printf("%cEn qu%c pa%cs naci%c Napoleon Bonaparte?\n", 168, 130, 161, 162);
            printf("a) Italia\n");
            printf("b) Inglaterra\n");
            printf("c) Austria\n");
            printf("d) Francia\n");

            return 'd';
            break;

        case 19:
            printf("%cQu%c pa%cses se enfrentaron en la Guerra de los Cien A%cos?\n", 168, 130, 161, 164);
            printf("a) Francia y Espa%ca\n", 164);
            printf("b) Francia e Italia\n");
            printf("c) Francia e Inglaterra\n");
            printf("d) Inglaterra y Espa%ca", 164);

            return 'c';
            break;

    }
    return -1;
}

int preguntageografia(int aleat){

    switch(aleat){

        case 0:
            printf("%cQu%c es Zelandia?\n", 168, 130);
            printf("a) Una ciudad islandesa\n");
            printf("b) Un parque tem%ctico\n", 130);
            printf("c) Un pa%cs del hemisferio norte\n", 161);
            printf("d) Un continente\n");

            return 'd';
            break;

        case 1:
            printf("%cCu%cl es el pa%cs de los 1000 lagos?\n", 168, 160, 161);
            printf("a) Finlandia\n");
            printf("b) Estados Unidos\n");
            printf("c) Canada\n");
            printf("d) Brasil\n");

            return 'a';
            break;

        case 2:
            printf("%cD%cnde est%c la regi%cn m%cs pobre del mundo?\n", 168, 162, 160, 162, 160);
            printf("a) En Zimbabue\n");
            printf("b) En Honduras\n");
            printf("c) En Sahel\n");
            printf("d) En Nepal\n");

        case 3:
            printf("%cCu%cl es la ciudad m%cs antigua del mundo?\n", 168, 162, 162);
            printf("a) Luxor\n");
            printf("b) Ur\n");
            printf("c) Biblos\n");
            printf("d) Jeric%c\n", 162);

            return 'd';
            break;

        case 4:
            printf("%cCu%cl es la capital de Brasil?\n", 168, 160);
            printf("a) Brasilia\n");
            printf("b) Rio de Janeiro\n");
            printf("c) Sao Paulo\n");
            printf("d)Salvador de Bahia\n");

            return 'a';
            break;

        case 5:
            printf("Capital de Corea del Sur:\n");
            printf("a) Seul\n");
            printf("b) Busan\n");
            printf("c) Inchon\n");
            printf("d) Daegu\n");

            return 'a';
            break;

        case 6:
            printf("%cCu%cl de estos pa%cses no limita con Francia?\n", 168, 160, 161);
            printf("a) Espa%ca\n", 164);
            printf("b) Holanda\n");
            printf("c) Italia\n");
            printf("d) Alemania\n");

            return 'b';
            break;

        case 7:
            printf("%cCu%cl es el segundo continente m%cs grande del mundo?\n", 168,160,160);
            printf("a) Europa\n");
            printf("b) Am%crica\n", 130);
            printf("c) Asia\n");
            printf("d) Africa\n");

            return 'b';
            break;

        case 8:
            printf("%cCu%cl es el pa%cs m%cs poblado del mundo?\n", 168, 160, 161, 160);
            printf("a) Estados Unidos\n");
            printf("b) India\n");
            printf("c) Rusia\n");
            printf("d) China\n");

            return 'd';
            break;

        case 9:
            printf("%cCu%cntos pa%cses hay en el mundo?\n", 168, 160, 161);
            printf("a) 214\n");
            printf("b) 196\n");
            printf("c) 194\n");
            printf("d) 189\n");

            return 'c';
            break;

        case 10:
            printf("%cCu%cl es la ciudad m%cs poblada del mundo?\n", 168, 160,160);
            printf("a) Ciudad de M%cxico\n", 130);
            printf("b) Tokio\n");
            printf("c) Nueva Delhi\n");
            printf("d) Shanghai\n");

            return 'b';
            break;

        case 11:
            printf("%cCu%cl es la capital de Canada?\n", 168, 160);
            printf("a) Vancouver\n");
            printf("b) Toronto\n");
            printf("c) Ottawa\n");
            printf("d) Quebec\n");

            return 'c';
            break;

        case 12:
            printf("%cCu%cles pa%cses rodean al Mar Muerto?\n",168,160,161);
            printf("a) Israel, Palestina y Jordania\n");
            printf("b) Israel, Jordania y Egipto\n");
            printf("c) Syria, Jordania y Palestina\n");
            printf("d) Palestina, Egipto y Syria\n");

            return 'a';
            break;

        case 13:
            printf("Rio mas largo del mundo:\n");
            printf("a) Rio Nilo\n");
            printf("b) Rio Amazonas\n");
            printf("c) Rio Yangste/Amarillo\n");
            printf("d) Rio Misisipi\n");

            return 'a';
            break;

        case 14:
            printf("%cEntre cu%cles territorios se encuentra el estrecho de Bering?\n",168,160);
            printf("a) Canada y Estados Unidos\n");
            printf("b) Rusia y Estados Unidos\n");
            printf("c) Rusia y Canada\n");
            printf("d) Japon y Estados Unidos\n");

            return 'b';
            break;

        case 15:
            printf("%cCu%cl es el lago m%cs grande de Am%crica?\n",168,160,160,130);
            printf("a) Lago Superior\n");
            printf("b) Lago Huron\n");
            printf("c) Lago Titikaka\n");
            printf("d) Lago Cocibolca\n");

            return 'a';
            break;

        case 16:
            printf("%cD%cnde est%c ubicado el edificio m%cs alto del mundo?\n",168,162,160,160);
            printf("a) Arabia Saudita\n");
            printf("b) Jap%cn\n",162);
            printf("c) China\n");
            printf("d) Emiratos Arabes Unidos\n");

            return 'd';
            break;

        case 17:
            printf("%cEn qu%c pa%cs est%c ubicada la cascada m%cs alta del mundo llamada Salto Angel?\n",168,130,161,160,160);
            printf("a) Brazil\n");
            printf("b) Argentina\n");
            printf("c) Chile\n");
            printf("d) Venezuela\n");

            return 'd';
            break;

        case 18:
            printf("%cCu%cl de las siguientes ciudades no pertenece a la Uni%cn Europea?\n",168,160,162);
            printf("a) Praga\n");
            printf("b) Estambul\n");
            printf("c) Reykjavik\n");
            printf("d) Barcelona\n");

            return 'b';
            break;

        case 19:
            printf("%cEn qu%c pa%cs de la actualidad se encontraba el Puerto de Alejandr%ca?\n",168,130,161,161);
            printf("a) Roma\n");
            printf("b) Grecia\n");
            printf("c) Egipto\n");
            printf("d) Ir%cn\n",160);

            return 'c';
            break;
    }

    return -1;
}
