#include "minunit.h"
#include "../funciones-pract7.h"

#define MINUNIT_EPSILON 1E-5

MU_TEST(test_elimoracion1){

    char str[] = "Hola, como estas? Espero que bien";

    elimoracion(str);

	mu_assert_string_eq("Espero que bien", str);
}

MU_TEST(test_elimoracion2){

    char str[] = "Hola como estas? Bien. Hoy comí mucho. Nos veremos en un rato";

    elimoracion(str);

	mu_assert_string_eq("Bien. Hoy comí mucho. Nos veremos en un rato", str);
}

MU_TEST(test_elimoracion3){

    char str[] = "Saludos";

    elimoracion(str);

	mu_assert_string_eq("", str);
}

MU_TEST(test_elimoracionError){

    char str[] = "Hola como estas? Bien. Hoy comí mucho. Nos veremos en un rato";

    elimoracion(str);

	mu_assert_string_eq("Hola como estas? Bien. Hoy comí mucho. Nos veremos en un rato", str);
}

MU_TEST_SUITE(test_suite) {

	MU_RUN_TEST(test_elimoracion1);
	MU_RUN_TEST(test_elimoracion2);
	MU_RUN_TEST(test_elimoracion3);
	MU_RUN_TEST(test_elimoracionError);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

