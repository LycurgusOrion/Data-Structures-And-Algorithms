/******************************************

	Program to implement sparse matrix
	using structures

	usage: FileName NumberOfStructureElements
					NumberRowOfSparseMatrix
					NumberOfColumnSparseMatrix

******************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_ARG 4

struct Sparse
{
	int row;
	int col;
	int elm;
};

int main(int v, char *arg[])
{
	if(v != MAX_ARG)
	{
		printf("error : invalid arguments");
		return -1;
	}

	struct Sparse sp[MAX];

	int a[MAX][MAX];
	int n, i, j, r, c, k;

	n = atoi(arg[1]);
	r = atoi(arg[2]);
	c = atoi(arg[3]);

	for(i = 0 ; i < n ; i++)
	{
		printf("\n\nEnter row for %d : ", i + 1);
		scanf("%d", &sp[i].row);
		printf("Enter col for %d : ", i + 1);
		scanf("%d", &sp[i].col);
		printf("Enter val for %d : ", i + 1);
		scanf("%d", &sp[i].elm);
	}

	printf("\nRow\tColumn\tValue\n");
	for(i = 0 ; i < n ; i++)
		printf("%d\t%d\t%d\n", sp[i].row, sp[i].col, sp[i].elm);

	k = 0;
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			if(sp[k].row == i && sp[k].col == j)
				a[i][j] = sp[k++].elm;
			else
				a[i][j] = 0;
		}
	}

	printf("\nResultant Sparse Matrix : \n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}