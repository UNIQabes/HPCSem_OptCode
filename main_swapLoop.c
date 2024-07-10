#include <stdio.h>
#include "second.c"

#define N 1000
int main(void)
{
	static double a[N][N], b[N][N], c[N][N];
	int i, j, k;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			a[i][j] = rand(); b[i][j] = rand(); c[i][j] = rand();
		}
	}

	double start=second();
	for (i = 0; i < N; i++) 
	{
		for (k = 0; k < N; k++) 
		{
			for (j = 0; j < N; j++) 
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	double end=second();
	printf("time:%lf\n",end-start);

	return 0;
}