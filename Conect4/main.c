#include <stdio.h>
#include <stdlib.h>
#include <conio.c>

#define MAXFIL 6
#define MAXCOL 7
#define ESP    3

#define ESC   27
#define ENTER 13

#define DERECHA   77
#define IZQUIERDA 75

#define CT     BLUE
#define CF     LIGHTGRAY

#define CTS    LIGHTGRAY
#define CFS    BLUE

#define CTM    RED
#define CFM    YELLOW

void genmat(int [][MAXCOL],int,int);
void putmatxy(int [][MAXCOL],int,int,int,int,int,int,int);
void movimiento(int [][MAXCOL],int,int,int,int);
int turnojugador(int[][MAXCOL], int[], int, int, int);

void setcolor(int,int);
void colordefault();
int randrango(int,int);

int main()
{
   int mat[MAXFIL][MAXCOL];
   int veces;
   srand(time(NULL));

   genmat(mat,MAXFIL,MAXCOL);
   movimiento(mat,MAXFIL,MAXCOL,10,5);

   return 0;
}

void genmat(int mat[][MAXCOL],int fila,int column)
{
   int indfil, indcol;

   for ( indfil = 0; indfil < fila; indfil ++ )
      for ( indcol = 0; indcol < column; indcol ++ )
         mat[indfil][indcol] = 0;

}

void putmatxy(int mat[][MAXCOL],int fila,int column,int px, int py,int fs, int cs, int cont)
{
   int indfil, indcol;

   clrscr();

   printf("\n\t ************************CONECTA 4************************\n\n");

   if(cont % 2 == 0){
      printf("\t\t\t     TURNO DEL USUARIO\n");
   }else{
      if(cont % 2 == 1)
         printf("\t\t\t      TURNO DEL CPU\n\t\t\t[PRESIONE CUALQUIER TECLA]\n");
   }


   for ( indfil = 0; indfil < fila; indfil ++ )
   {
      for ( indcol = 0; indcol < column; indcol ++ )
      {
         setcolor(CT,CF);
         if ( indfil == fs && indcol == cs )
               setcolor(CTS,CFS);
         gotoxy(px+indcol*ESP,py+indfil);
         printf(" %c ",mat[indfil][indcol]);
      }
   }
   colordefault();
}

void movimiento(int mat[][MAXCOL],int fila,int column,int px, int py)
{
   int filasel = 0, columnasel = 0, ind = 1, arr[7] = {0}, cont = 0, n;
   int temp, indfil, indcol;
   char tecla;
   _setcursortype(0);
   do{
      putmatxy(mat,MAXFIL,MAXCOL,28,6,filasel,columnasel,cont);
      tecla = getch();

      if ( tecla == DERECHA )
      {
         columnasel ++;
         if ( columnasel > MAXFIL )
            columnasel = 0;
      }

      if ( tecla == IZQUIERDA )
      {
         columnasel --;
         if ( columnasel < 0 )
            columnasel = MAXFIL;
      }

      if(cont%2 == 0){
      if(tecla == ENTER){


            arr[columnasel]++;

            mat[MAXFIL - arr[columnasel]][columnasel] = 'O';

            if(gano(mat, indfil, indcol, 'O') == 1){
               putmatxy(mat,MAXFIL,MAXCOL,28, 6,filasel,columnasel,cont);
               break;
            }
            cont++;
         }else{
         if(cont % 2 == 1){

            n = randrango(0, 6);
            arr[n]++;

            if (casigana(mat, '0') == 1){
               for(indfil = 0; indfil < MAXFIL; indfil++){
                  for(indcol = 0; indcol < MAXCOL; indcol++){
                     if(gano(mat, indfil, indcol, 'O') == 1){
                        mat[indfil][indcol] = 'X';
                     }
                  }
               }
            }else{
               if(casigana(mat, 'O') == 0)
                  mat[MAXFIL - arr[n]][n] = 'X';
            }

            if(gano(mat, MAXFIL - arr[n], n, 'X') == 1){
               putmatxy(mat,MAXFIL,MAXCOL,28, 6,filasel,columnasel,cont);
               break;
            }
            cont++;
         }
      }
      }


   }while ( tecla != ESC );
}

int turnojugador(int mat[][MAXCOL], int arr[], int filasel, int columnasel, int cont){

   int tecla;

   mat[MAXFIL - arr[columnasel]][columnasel] = 'O';
   if(gano(mat, MAXFIL - arr[columnasel], columnasel, 'O') == 1)
   {
      return 1;
   }
   return 0;
}

int randrango(int a,int b)
{
   return rand() % (b-a+1) + a;
}

int gano(int mat[][MAXCOL], int filaact, int columnact, int c){

   if(columnact < 0 || columnact > MAXCOL || filaact < 0 || filaact > MAXCOL){
      return 0;
   }
   if((mat[filaact][columnact-1] == c) && (mat[filaact][columnact-2] == c) && (mat[filaact][columnact-3] == c)){
      return 1;
   }

   if((mat[filaact][columnact+1] == c) && (mat[filaact][columnact+2] == c) && (mat[filaact][columnact+3] == c)){
      return 1;
   }

   if((mat[filaact][columnact-1] == c) && (mat[filaact][columnact+1] == c) && (mat[filaact][columnact+2] == c)){
      return 1;
   }

   if((mat[filaact][columnact-1] == c) && (mat[filaact][columnact+1] == c) && (mat[filaact][columnact-2] == c)){
      return 1;
   }

   if((mat[filaact+1][columnact] == c) && (mat[filaact+2][columnact] == c) && (mat[filaact+3][columnact] == c)){
      return 1;
   }

   if((mat[filaact+1][columnact+1] == c) && (mat[filaact+2][columnact+2] == c) && (mat[filaact+3][columnact+3] == c)){
      return 1;
   }

   if((mat[filaact-1][columnact-1] == c) && (mat[filaact+1][columnact+1] == c) && (mat[filaact+2][columnact+2] == c)){
      return 1;
   }

   if((mat[filaact-1][columnact-1] == c) && (mat[filaact-2][columnact-2] == c) && (mat[filaact+1][columnact+1] == c)){
      return 1;
   }

   if((mat[filaact-1][columnact-1] == c) && (mat[filaact-2][columnact-2] == c) && (mat[filaact-3][columnact-3] == c)){
      return 1;
   }

   if((mat[filaact+1][columnact-1] == c) && (mat[filaact+2][columnact-2] == c) && (mat[filaact+3][columnact-3] == c)){
      return 1;
   }

   if((mat[filaact-1][columnact+1] == c) && (mat[filaact+1][columnact-1] == c) && (mat[filaact+2][columnact-2] == c)){
      return 1;
   }

   if((mat[filaact-1][columnact+1] == c) && (mat[filaact-2][columnact+2] == c) && (mat[filaact+1][columnact-1] == c)){
      return 1;
   }

   if((mat[filaact-1][columnact+1] == c) && (mat[filaact-2][columnact+2] == c) && (mat[filaact-3][columnact+3] == c)){
      return 1;
   }

   return 0;
}

int casigana(int mat[][MAXCOL], int c){

   int indfil, indcol;

   for(indfil = 0; indfil < MAXFIL; indfil++){
      for(indcol = 0; indcol < MAXCOL; indcol++){
         if(gano(mat, indfil, indcol, c) == 1){
            return 1;
         }
      }
   }
   return 0;
}

void setcolor(int ct, int cf)
{
   textcolor(ct);
   textbackground(cf);
}

void colordefault()
{
   setcolor(LIGHTGRAY,BLACK);
}
