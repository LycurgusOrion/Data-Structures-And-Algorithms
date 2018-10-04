/*************************************

	Program to store a 2D Array in:
		-Row Major &
		-Column Major form

	usage: 16CSU001_28Jul_3.exe 
			number_of_rows
			number_of_columns

**************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_ARG 3 

int main(int v, char * arg[])
{
	if(v != MAX_ARG)
	{
		printf("error : invalid arguments\n");
		return -1;
	}

	int a[MAX][MAX], b[MAX][MAX];
	int r, c, i, j;

	r = atoi(arg[1]);
	c = atoi(arg[2]);

	printf("\nEnter the Array : \n");
	for(i = 0 ; i < r ; i++)
		for(j = 0 ; j < c ; j++)
			scanf("%d", (*(a + i) + j));

	printf("\nRow Major\n");
	printf("\nIndex\tValue\tAddress\n");
	for(i = 0 ; i < r ; i++)
		for(j = 0 ; j < c ; j++)
			printf("(%d, %d)\t%d\t%d\n", i, j, *(*(a + i) + j), (*(a + i) + j));

	printf("\nEnter the Array : \n");
	for(i = 0 ; i < r ; i++)
		for(j = 0 ; j < c ; j++)
			scanf("%d", (*(b + j) + i));

	printf("\nColumn Major\n");
	printf("\nIndex\tValue\tAdress\n");
	for(i = 0 ; i < r ; i++)
		for(j = 0 ; j < c ; j++)
			printf("(%d, %d)\t%d\t%d\n", i, j, *(*(b + i) + j), (*(b + i) + j));	
}