#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_ARG 3

int main(int v, char *arg[])
{
	if(v != MAX_ARG)
	{
		printf("\nerror : invalid arguments\n");
		return -1;
	}

	int r = atoi(arg[1]);
	int c = atoi(arg[2]);

	int i;
	int j;

	int m[MAX][MAX];
	int d1[MAX];
	int d2[MAX];

	int k = 0;
	int l = 0;

	if(r != c)
	{
		printf("\nerror : only square matrix allowed\n");
		return -1;
	}

	printf("\nEnter the elements : \n");
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			scanf("%d", &m[i][j]);
			if(i == j)
			{
				d1[k++] = m[i][j];
			}
			else if((i + j) == (r - 1))
			{
				d2[l++] = m[i][j];
			}
		}
	}

	k = 0;
	l = 0;
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			if(i == j)
			{
				m[i][j] = d2[k++];
			}
			else if((i + j) == (r - 1))
			{
				m[i][j] = d1[l++];
			}
		}
	}

	printf("\nThe transformed matrix is : \n");

	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}