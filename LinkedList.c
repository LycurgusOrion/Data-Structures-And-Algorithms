/*********************************
	Program to:
		-Create a Linked List
		-Insert elements at the
			>Begining
			>Middle
			>End
		-Delete elements from
			>Begining
			>Middle
			>End
*********************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARG 1

typedef struct Student
{
	int rNo;
	char name[50];
	float gpa;
	struct Student *next;
}Node;

Node *start = NULL;

Node *setNode()
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	printf("\nEnter the details : \n");
	printf("\nRollNo : ");
	scanf("%d", &temp -> rNo);
	printf("\nName   : ");
	scanf("%s", temp -> name);
	printf("\nGPA    : ");
	scanf("%f", &temp -> gpa);
	temp -> next = NULL;
	return temp;
}

int count()
{
	int c = 1;
	Node *temp = start;
	while(temp -> next != NULL)
	{
		c++;
		temp = temp -> next;
	}
	return c;
}

void createList()
{
	int ch = 1;
	Node *new, *temp;
	do
	{
		new = setNode();
		if(start == NULL)
		{
			start = new;
		}
		else
		{
			//printf("start not NULL");
			temp = start;
			while(temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp -> next = new;
		}

		printf("\nEnter more? (0/1)...");
		scanf("%d", &ch);
	}while(ch == 1);	
}

void display()
{
	Node *temp = start;
	if(start != NULL)
	{
		while(temp != NULL)
		{
			printf("\n-------------------\n");
			printf("\nRollNo : %d\n", temp -> rNo);
			printf("\nName   : %s\n", temp -> name);
			printf("\nGPA    : %f\n", temp -> gpa);
			printf("___________________\n");
			printf("\t^\n");
			printf("\t|");
			
			temp = temp -> next;
		}
		printf("\n       NULL\n");
	}
	else
		printf("\nList is empty\n");
}

void revTraverse()
{
	Node *temp = start;
	if(start != NULL)
	{
		int nos = count();
		int i, j;

		printf("\n       NULL\n");
		for(i = 0 ; i < nos ; i++)
		{
			temp = start;
			for(j = 1 ; j < nos - i ; j++)
			{
				temp = temp -> next;
			}

			printf("\t^\n");
			printf("\t|");
			printf("\n-------------------\n");
			printf("\nRollNo : %d\n", temp -> rNo);
			printf("\nName   : %s\n", temp -> name);
			printf("\nGPA    : %f\n", temp -> gpa);
			printf("___________________\n");
		}
	}
	else
		printf("\nList is empty\n");	
}

void insertElement()
{
	if(start == NULL)
	{
		printf("\nCreate a list first!\n");
		return;
	}

	int pos, nos = count();
	printf("Enter position to insert at : ");
	scanf("%d", &pos);

	if(pos == 1)
	{
		Node *temp = setNode();
		printf("\nInserting at the begining...\n");
		temp -> next = start;
		start = temp;
	}
	else if(pos < nos)
	{
		Node *new = setNode(), *temp, *prev;
		int i = 1;
		printf("\nInserting in the middle...\n");
		
		temp = start;
		prev = temp;
		while(i < pos)
		{
			prev = temp;
			temp = temp -> next;
			i++;
		}

		new -> next = temp;
		prev -> next = new;
	}
	else if(pos == nos)
	{
		Node *new = setNode();
		printf("\nInserting at the end...\n");
		Node *temp = start;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = new;
	}
}

void delElement()
{
	if(start == NULL)
	{
		printf("\nCreate a list first!\n");
		return;
	}

	int pos, nos = count();
	printf("Enter position to delete from : ");
	scanf("%d", &pos);

	if(pos == 1)
	{
		Node *temp;
		printf("\nDeleting from the begining...\n");
		temp = start;
		start = start -> next;
		free(temp);
	}
	else if(pos < nos)
	{
		Node *temp, *prev;
		int i = 1;
		printf("\nDeleting from the middle...\n");
		
		temp = start;
		prev = temp;
		while(i < pos)
		{
			prev = temp;
			temp = temp -> next;
			i++;
		}

		prev -> next = temp -> next;
		free(temp);
	}
	else if(pos == nos)
	{
		printf("\nDeleting from the end...\n");
		
		Node *temp = start;
		Node *prev = temp;
		while(temp -> next != NULL)
		{
			prev = temp;
			temp = temp -> next;
		}
		
		prev -> next = NULL;
		free(temp);
	}
}

void menu()
{
	int ch;
	do
	{
		printf("\n\n------------------\n");
		printf("SINGLE LINKED LIST\n");
		printf("------------------\n");
		printf("\n----------\n");
		printf("MAIN MENU\n");
		printf("__________\n");

		printf("\n1.Create List\n");
		printf("\n2.Insert Element\n");
		printf("\n3.Delete Element\n");
		printf("\n4.Display Element\n");
		printf("\n5.Reverse Traverse\n");
		printf("\n6.Count\n");
		printf("\n7.Exit\n");

		scanf("%d", &ch);
		if (ch == 1)
		{
			createList();
			if(start == NULL)
				printf("warning : start empty");
		}
		else if(ch == 2)
		{
			insertElement();
		}
		else if(ch == 3)
		{
			delElement();
		}
		else if(ch == 4)
		{
			if(start == NULL)
				printf("warning : start empty");
			display();
		}
		else if(ch == 5)
		{
			revTraverse();
		}
		else if(ch == 6)
		{
			int x = count();
			printf("\n\nThere are %d elements in this list\n", x);
		}
		else if(ch == 7)
		{
			exit(0);
		}
		else 
		{
			printf("\nInvalid Choice!\n");
		}

	}while(ch != 7);
}

int main(int v, char *arg[])
{
	if(v != MAX_ARG)
	{
		printf("\nerror : invalid arguments");
		return -1;
	}

	menu();
}