#include <stdio.h>
#include "second.c"

#define N 1000
#define BLOCKSIZE 8
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
	for (ib = 0; ib < N; ib+=BLOCKSIZE) 
	{
		for (kb = 0; kb < N; kb+=BLOCKSIZE) 
		{
			for (jb = 0; jb < N; jb+=BLOCKSIZE) 
			{
				for (i = ib; i < ib+BLOCKSIZE; i++) 
				{
					for (k = kb; k < kb+BLOCKSIZE; k++) 
					{
						for (j = jb; j < jb+BLOCKSIZE; j++) 
						{
							c[i][j] += a[i][k] * b[k][j];
						}
					}
				}
				
				
			}
		}
	}
	double end=second();
	printf("time:%lf\n",end-start);

	return 0;
}