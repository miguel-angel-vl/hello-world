#include "minunit.h"
#include "../funciones9.h"

#define NOMARCH "estudiante.dat"

#define MINUNIT_EPSILON 1E-5


MU_TEST(test_assert) {

	ESTUDIANTE *estud, *este;

	estud = (EST*)malloc(2*sizeof(EST));
	este = (EST*)malloc(2*sizeof(EST));

	for(int ind = 0; ind < 2; ind++){
        if(ind == 0){
            (estud+ind) = llenar(estud, ind, "Miguel", 20, 20171022, 1, "Algoritmos", 1, 1, "Proyecto", 100, 100);
        }

        if(ind == 1){
            (estud+ind) = llenar(estud, ind, "Angel", 20, 10222017, 1, "Algoritmos", 1, 1, "Proyecto", 100, 0);
        }
	}

	estud = guardarEstudiantes(estud, 2, NOMARCH);
	este = cargarEstudiantes(NOMARCH);

    mu_assert_string_eq(estud[0].nombre,este[0].nombre);
    mu_assert_string_eq(estud[0].matricula,este[0].matricula);
    mu_assert_int_eq(estud[1].edad, este[1].edad);


}


MU_TEST_SUITE(test_suite) {


	MU_RUN_TEST(test_assert);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

