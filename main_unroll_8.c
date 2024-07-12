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
			for (j = 0; j < N; j+=8) 
			{
				c[i][j] += a[i][k] * b[k][j];
				c[i][j+1] += a[i][k] * b[k][j+1];
				c[i][j+2] += a[i][k] * b[k][j+2];
				c[i][j+3] += a[i][k] * b[k][j+3];

				c[i][j+4] += a[i][k] * b[k][j+4];
				c[i][j+5] += a[i][k] * b[k][j+5];
				c[i][j+6] += a[i][k] * b[k][j+6];
				c[i][j+7] += a[i][k] * b[k][j+7];
			}
		}
	}
	double end=second();
	printf("%lf",end-start);

	return 0;
}