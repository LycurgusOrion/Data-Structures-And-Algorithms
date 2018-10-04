/* Program to implement merge sort */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 100
#define MAX_ARG 3

int main(int v, char * arg[])
{
	if(v != MAX_ARG)
	{
		printf("error : ivalid arguments");
		return -1;
	}

	int a[MAX], b[MAX], c[MAX], n1, n2, i, j, k;

	n1 = atoi(arg[1]);
	n2 = atoi(arg[2]);

	printf("\nEnter the first array : \n");
	for(i = 0 ; i < n1 ; i++)
		scanf("%d", &a[i]);

	printf("\nEnter the second array : \n");
	for(i = 0 ; i < n2 ; i++)
		scanf("%d", &b[i]);

	a[n1] = INT_MAX;
	b[n2] = INT_MAX;
	i = 0;
	j = 0;

	for(k = 0 ; k < (n1 + n2) ; k++)
	{
		if(a[i] <= b[j])
			c[k] = a[i++];
		else
			c[k] = b[j++];
	}

	printf("\nThe merged array is : ");
	for(i = 0 ; i < (n1 + n2) ; i++)
		printf("%d ", c[i]);
}