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

	/*
	int d[10]={9,8,7,6,5,4,3,2,1,1};
	__m256i a1 = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);
	__m256i b1 = _mm256_setr_epi32(0, 0, 2, 0, 4, 0, 6, 0);
	__m256i c1 = _mm256_setr_epi32(2, 2, 4, 4, 6, 6, 8, 8);
	__m256i d1 = _mm256_mul_epi32(a1, c1);
	__m256i e1 = _mm256_mul_epi32(b1, c1);
	__m256i f1 =_mm256_loadu_si256((__m256i *)&d[2]);
	printf("a1");
	printf(" %d", _mm256_extract_epi32(e1,0));
	printf(" %d", _mm256_extract_epi32(e1,1));
	printf(" %d", _mm256_extract_epi32(e1,2));
	printf(" %d", _mm256_extract_epi32(e1,3));
	printf(" %d", _mm256_extract_epi32(e1,4));
	printf(" %d", _mm256_extract_epi32(e1,5));
	printf(" %d", _mm256_extract_epi32(e1,6));
	printf(" %d", _mm256_extract_epi32(e1,7));
	printf("\n");
	*/
	


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
	printf("time:%lf\n",end-start);

	return 0;
}