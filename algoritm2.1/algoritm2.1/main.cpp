#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10000

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int i, j, k, elem_c;
	int **A = (int**)malloc(N * sizeof(int*));
	int **B = (int**)malloc(N * sizeof(int*));
	int **C = (int**)malloc(N * sizeof(int*));
	for (i = 0; i < N; i++){
		A[i] = (int*)malloc(N * sizeof(int));
		B[i] = (int*)malloc(N * sizeof(int));
		C[i] = (int*)malloc(N * sizeof(int));
	}
	
	srand(time(NULL));
	for (i = 0; i < N; i++)
    for (j = 0; j < N; j++){
        A[i][j] = rand() % 100;
        B[i][j] = rand() % 100;
    }

	double time_spent = 0.0; // для хранения времени выполнения кода
    clock_t begin = clock();
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for(k = 0; k < N; k++)
			C[i][j] += A[i][k] * B[k][j];
		}
	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;// рассчитать прошедшее время, найдя разницу (end - begin) и деление разницы на CLOCKS_PER_SEC для перевода в секунды
    printf("Затраченно время в секундах %f ", time_spent);

	for (i = 0; i < N; i++){
		free(A[i]);
		free(B[i]); 
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);
	
}

