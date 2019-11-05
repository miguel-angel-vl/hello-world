#include "minunit.h"
#include <string.h>

#include "../funciones_buscaminas.h"
//void explosion(int matriz_valores[90][90], int matriz_visual[90][90], int matriz_visitados[90][90], int n, int m, int i, int j);

MU_TEST(test_click1) {
	int m=5, n=4;
	int matvalores[4][5] = {
		{1, 1, 1, 0, 0},
		{1,'b',2 ,1, 1},
		{1, 1, 2,'b',1},
		{0, 0, 1, 1, 1},
	};
	int matvisual[4][5] = {
		{'#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#'},
	};

	click(matvalores, matvisual, n, m, 3, 0);
	int matres[4][5] = {
		{'#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#'},
		{1,   1,    2,  '#', '#'},
		{0  , 0,    1, '#', '#'},
	};
	int i, j;
	for(i=0; i<n;i++)
		for(j=0; j<m;j++)
			printf("%d, %d, %d, %d\n, ", i, j,matvisual[i][j], matres[i][j]);
			mu_assert_int_eq(matvisual[i][j], matres[i][j] );

}

MU_TEST_SUITE(test_suite) {

	MU_RUN_TEST(test_click1);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
