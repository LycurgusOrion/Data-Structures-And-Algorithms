// To make a SLL by selecting alternate elements from given SLL
#include <stdio.h>
#include <stdlib.h>

typedef struct list1 NODE1;
typedef struct list2 NODE2;

struct list1
{
	int data;
	NODE1 *link;
};

struct list2
{
	int data;
	NODE2 *link;
};


void main()
{
	int ch,i,c=1;
	NODE1 *start1,*temp1,*ptr1;
	NODE2 *start2,*temp2,*ptr2;
	temp1=(NODE1 *)malloc(sizeof(NODE1));
	printf("Enter the data number : ");
	scanf("%d",&temp1->data);
	temp1->link=NULL;
	start1=temp1;
	ptr1=start1;
	printf("Continue ? (1 : Y  0 : N) : ");
		scanf("%d",&ch);
	while(ch==1)
	{
		c++;
		temp1=(NODE1 *)malloc(sizeof(NODE1));
		printf("Enter the data number : ");
		scanf("%d",&temp1->data);
		temp1->link=NULL;
		ptr1->link=temp1;
		ptr1=temp1;
		printf("Continue ? (1 : Y  0 : N) : ");
		scanf("%d",&ch);
	}

	ptr2 = start1;
	temp2 = (NODE2 *)malloc(sizeof(NODE2));
	temp2->data = ptr2->data;
	temp2->link = ptr2->link->link;
	start2 = temp2;
	ptr2 = ptr2->link->link;

//i<(c/2) possible condition for while loop
	while(ptr2->link->link!=NULL)
	{
		printf("hi\n");
		temp2=(NODE2 *)malloc(sizeof(NODE2));
		temp2->data=ptr2->data;
		temp2->link=ptr2->link->link;
		ptr2=ptr2->link->link;
		printf("hello\n");
	}
	ptr2->link=NULL;
	printf("The original list is :\n");
	ptr1=start1;
	while(ptr1!=NULL)
	{
		printf("data : %d \n",ptr1->data);
		ptr1=ptr1->link;
	}
	printf("The copied list is :\n");
	ptr2=start2;
	while(ptr2!=NULL)
	{
		printf("data : %d \n",ptr2->data);
		ptr2=ptr2->link;
	}
}