#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_ARG 3

int main (int argc, char const *argv[])
{
	if (argc != MAX_ARG)
	{
		printf("error : invalid arguments\n");
		return -1;
	}

	int n = atoi(arg[1]);
	int a = atoi(arg[2]);

	int input[MAX], output[MAX]; 
	int i, j, k, l;

	for (i = 0 ; i < n ; i++)
		for (j = 0; j < a; j++)
			scanf("%d", &input[i][j]);	

	for (i = 0 ; i < n ; i++)
		for (j = 0 ; j < n ; j++)
			output[i][j] = 0;

	i = 0;
	j = 0;
	for (k = 0 ; k < n ; k++)
	{
		if (i < n && j < n && i == j)	
	}

	return 0;
}
/*
	00 01 02 03
	10 11 12 13
	20 21 22 23
	30 31 32 33
*/