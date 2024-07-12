#include <stdio.h>
#include <immintrin.h>
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
			for (j = 0; j < N; j+=4) 
			{
				
				//c[i][j] += a[i][k] * b[k][j];
				__m256d aik=_mm256_set1_pd (a[i][k]);
				__m256d bkj_0_3=_mm256_loadu_pd ( &(b[k][j]) );
				__m256d cij_0_3=_mm256_loadu_pd ( &(c[i][j]) );

				__m256d ab=_mm256_mul_pd(aik,bkj_0_3);
				cij_0_3= _mm256_add_pd(cij_0_3,ab);

				_mm256_store_pd ( (&(c[i][j])) , cij_0_3);
			}
		}
	}
	double end=second();
	printf("%lf",end-start);


	return 0;
}