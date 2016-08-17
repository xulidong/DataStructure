#include <cstdio>

#define N 10
#define S 4
#define B 30

void printArray(int arr[][10], int l1, int l2)
{
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printSJ()
{
	int array[N][N] = {0};
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (j == 0 || j == i){
				array[i][j] = 1;
			}
		}
	}
	printArray(array, 10, 10);
	
	for (int i = 2; i < N; ++i){
		for (int j = 1; j < i; ++j){
			array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
		}
	}
	printArray(array, 10, 10);
	for (int i = 0; i < N; ++i){
		printf("%*d", B - S/2 * i,array[i][0]);
		for (int j = 1; j <= i; ++j){
			printf("%4d", array[i][j]);
		}
		printf("\n");
	}
}