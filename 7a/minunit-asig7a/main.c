#include "minunit.h"
#include "../funcionesasig7.h"

#define MINUNIT_EPSILON 1E-5

MU_TEST(test_simetrica1) {
     int matval[3][3] = {
		{1, 2, 3},
		{2, 8, 7},
		{3, 7, 2},
     };

	mu_assert_int_eq(1, simetrica(matval, 3));
}

MU_TEST(test_simetrica2) {
     int matval[5][5] = {
		{1, 2, 3, 4, 5},
		{2, 8, 7, 7, 7},
		{3, 7, 4, 2, 1},
		{4, 7, 2, 0, 4},
		{5, 7, 1, 4, 5}
     };
	
	mu_assert_int_eq(1, simetrica(matval, 5));
}

MU_TEST(test_simetrica3) {
     int matval[3][3] = {
		{8, 2, 3},
		{5, 8, 1},
		{0, 9, 2},
     };
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
     int matval[3][3] = {
		{-8, -1, 3},
		{-1, 7, 4},
		{3, 4, 9},
     };

	mu_assert_int_eq(0, simetrica(matval, 3));
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

