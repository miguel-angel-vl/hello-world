#include "minunit.h"
#include "../funcionesasig7.h"

#define MINUNIT_EPSILON 1E-5

MU_TEST(test_simetrica1) {

	int ** matriz = (int **) malloc(3 * sizeof(int*));
	for(int i=0; i<3; i++){
		matriz[i] = (int *) malloc(3*sizeof(int));
	}
	matriz[0][0] = 1; matriz[0][1] = 5; matriz[0][2] = 0;
	matriz[1][0] = 5; matriz[1][1] = 3; matriz[1][2] = 9;
	matriz[2][0] = 0; matriz[2][1] = 9; matriz[2][2] = 2;

	mu_assert_int_eq(1, simetrica(matriz, 3));

	for(int i=0; i<3; i++){
		free(matriz[i]);
	}
	free(matriz);
}

MU_TEST(test_simetrica2) {

	int ** matriz = (int **) malloc(5 * sizeof(int*));
	for(int i=0; i<5; i++){
		matriz[i] = (int *) malloc(5*sizeof(int));
	}
	matriz[0][0] = 1; matriz[0][1] = 2; matriz[0][2] = 3, matriz[0][3] = 4, matriz[0][4] = 5;
	matriz[1][0] = 2; matriz[1][1] = 8; matriz[1][2] = 7, matriz[1][3] = 7, matriz[1][4] = 7;
	matriz[2][0] = 3; matriz[2][1] = 7; matriz[2][2] = 4, matriz[2][3] = 2, matriz[2][4] = 1;
	matriz[3][0] = 4; matriz[3][1] = 7; matriz[3][2] = 2, matriz[3][3] = 0, matriz[3][4] = 4;
	matriz[4][0] = 5; matriz[4][1] = 7; matriz[4][2] = 1, matriz[4][3] = 4, matriz[4][4] = 5;

	mu_assert_int_eq(1, simetrica(matriz, 3));

	for(int i=0; i<3; i++){
		free(matriz[i]);
	}
	free(matriz);
}


MU_TEST(test_simetrica3) {

	int ** matriz = (int **) malloc(3 * sizeof(int*));
	for(int i=0; i<3; i++){
		matriz[i] = (int *) malloc(3*sizeof(int));
	}
	matriz[0][0] = 8; matriz[0][1] = 2; matriz[0][2] = 3;
	matriz[1][0] = 5; matriz[1][1] = 28; matriz[1][2] = 1;
	matriz[2][0] = 0; matriz[2][1] = 9; matriz[2][2] = 2;

	mu_assert_int_eq(0, simetrica(matriz, 3));

	for(int i=0; i<3; i++){
		free(matriz[i]);
	}
	free(matriz);
}

MU_TEST(test_simetricaError) {

	int ** matriz = (int **) malloc(3 * sizeof(int*));
	for(int i=0; i<3; i++){
		matriz[i] = (int *) malloc(3*sizeof(int));
	}
	matriz[0][0] = -8; matriz[0][1] = -1; matriz[0][2] = 3;
	matriz[1][0] = -1; matriz[1][1] = 7; matriz[1][2] = 4;
	matriz[2][0] = 3; matriz[2][1] = 4; matriz[2][2] = 9;

	mu_assert_int_eq(0, simetrica(matriz, 3));

	for(int i=0; i<3; i++){
		free(matriz[i]);
	}
	free(matriz);
}


MU_TEST_SUITE(test_suite) {

	MU_RUN_TEST(test_simetrica1);
	MU_RUN_TEST(test_simetrica2);
	MU_RUN_TEST(test_simetrica3);
	MU_RUN_TEST(test_simetricaError);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

