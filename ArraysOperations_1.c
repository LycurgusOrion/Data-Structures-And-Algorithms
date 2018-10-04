/*********************************************

	Program to:
		-Create an array
		-Traverse the array
		-Insert an element at given position
		-Delete an element at given position

	usage: 16CSU001_28Jul_1.exe num_elements_in_array

**********************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_ARG 2

int main(int v, char *arg[])
{
	if(v != MAX_ARG)
	{
		printf("\nError Invalid Arguments\n");
		return -1;
	}

	int a[MAX], b[MAX], c[MAX];
	int i, j, n;

	n = atoi(arg[1]);

//CREATE

	printf("\nEnter %d elements : \n", n);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);

//PRINT

	printf("\nThis is the array : ");
	for(i = 0 ; i < n ; i++)
		printf("%d ", *(a + i));

//INSERT

	int x, px;
	printf("\n\nEnter the element to insert : ");
	scanf("%d", &x);
	printf("\nEnter the position to insert at : ");
	scanf("%d", &px);

	for(i = 0 ; i < n ; i++)
	{
		if(i == px - 1)
		{
			for(j = n ; j > i ; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = x;
		}
	}

	printf("\nThis is the array after insertion : ");
	for(i = 0 ; i < n ; i++)
		printf("%d ", *(a + i));

//DELETE

	int d;
	printf("\n\nEnter the position to delete from : ");
	scanf("%d", &d);
	for(i = 0 ; i < n ; i++)
		if(i == d - 1)
			for(j = i ; j < n ; j++)
				a[j] = a[j + 1];
	
	printf("\nThis is the array after deletion : ");
	for(i = 0 ; i < n ; i++)
		printf("%d ", *(a + i));
}