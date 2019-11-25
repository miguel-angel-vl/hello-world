#ifndef FUNCIONES9_H

typedef struct evaluacion
{
    char nombre[20];
    int ponderacion;
    int calificacion_obtenida;

} EVALUACION;

typedef struct asignatura
{
    char nombre[20];
    int n_eva;
    EVALUACION eva[10];
    int creditos;

}ASIGNATURA;

typedef struct estudiante
{
    char matricula[9];
    int edad;
    char * nombre;
    ASIGNATURA mat[10];
    int n_mats;

} ESTUDIANTE;

int existeEstudiante(ESTUDIANTE *,int n, char *mat);
ESTUDIANTE * eliminarEstudiante(ESTUDIANTE *, int *n, int ind);
ESTUDIANTE * agregarEstudiante(ESTUDIANTE *, int n);
ESTUDIANTE * guardarEstudiantes(ESTUDIANTE *, int n, FILE * arch);
ESTUDIANTE * cargarEstudiantes(char * narch);
int calcular_indice(ESTUDIANTE est);

#endif // FUNCIONES9_H
