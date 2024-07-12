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
			for (j = 0; j < N; j+=20) 
			{
				c[i][j] += a[i][k] * b[k][j];
				c[i][j+1] += a[i][k] * b[k][j+1];
				c[i][j+2] += a[i][k] * b[k][j+2];
				c[i][j+3] += a[i][k] * b[k][j+3];

				c[i][j+4] += a[i][k] * b[k][j+4];
				c[i][j+5] += a[i][k] * b[k][j+5];
				c[i][j+6] += a[i][k] * b[k][j+6];
				c[i][j+7] += a[i][k] * b[k][j+7];

				c[i][j+8] += a[i][k] * b[k][j+8];
				c[i][j+9] += a[i][k] * b[k][j+9];
				c[i][j+10] += a[i][k] * b[k][j+10];
				c[i][j+11] += a[i][k] * b[k][j+11];

				c[i][j+12] += a[i][k] * b[k][j+12];
				c[i][j+13] += a[i][k] * b[k][j+13];
				c[i][j+14] += a[i][k] * b[k][j+14];
				c[i][j+15] += a[i][k] * b[k][j+15];

				c[i][j+16] += a[i][k] * b[k][j+16];
				c[i][j+17] += a[i][k] * b[k][j+17];
				c[i][j+18] += a[i][k] * b[k][j+18];
				c[i][j+19] += a[i][k] * b[k][j+19];
			}
		}
	}
	double end=second();
	printf("%lf",end-start);

	return 0;
}