/**************************************

	Program to concatenate two arrays

	usage: 16CSU001_28Jul_2.exe 
			num_elements_in_first_array
		   	num_elements_in_second_array

***************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_ARG 3

int main(int v, char *arg[])
{
	if(v != MAX_ARG)
	{
		printf("error : invalid arguments\n");
		return -1;
	}

	int a[MAX], b[MAX], c[MAX], n1, n2, i;

	n1 = atoi(arg[1]);
	n2 = atoi(arg[2]);

	printf("\nEnter first the Array : \n");
	for(i = 0 ; i < n1 ; i++)
		scanf("%d", &a[i]);

	printf("\nEnter second the Array : \n");
	for(i = 0 ; i < n2 ; i++)
		scanf("%d", &b[i]);

	int k = 0;
	printf("\nThis is the concatenated Array : ");
	for(i = 0 ; i < n1 ; i++)
		c[i] = a[i];

	k = i;
	
	for(i = 0 ; i < n2 ; i++)
		c[k++] = b[i];
	for(i = 0 ; i < n1 + n2 ; i++)
		printf("%d ", *(c + i));
}