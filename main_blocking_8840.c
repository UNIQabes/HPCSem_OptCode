#include <stdio.h>
#include "second.c"

#define N 1000
#define BLOCKSIZE_I 8
#define BLOCKSIZE_K 8
#define BLOCKSIZE_J 40

int main(void)
{
	static double a[N][N], b[N][N], c[N][N];
	int ib, jb, kb;
	int i, j, k;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			a[i][j] = rand(); b[i][j] = rand(); c[i][j] = rand();
		}
	}

	double start=second();
	for (ib = 0; ib < N; ib+=BLOCKSIZE_I) 
	{
		//c[i],b[i]のサイズは8K 
		for (kb = 0; kb < N; kb+=BLOCKSIZE_K) 
		{
			for (jb = 0; jb < N; jb+=BLOCKSIZE_J) 
			{
				for (i = ib; i < ib+BLOCKSIZE_I; i++) 
				{
					for (k = kb; k < kb+BLOCKSIZE_K; k++) 
					{
						for (j = jb; j < jb+BLOCKSIZE_J; j++) 
						{
							c[i][j] += a[i][k] * b[k][j];
						}
					}
				}
				
				
			}
		}
	}
	double end=second();
	printf("%lf",end-start);

	return 0;
}