/******************************

	Program to:
		-Create a Double 
		 Linked List
		-Insert elements at the
			>Begining
			>Middle
			>End
		-Delete elements from
			>Begining
			>Middle
			>End

******************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARG 1

typedef struct Student
{
	int rNo;
	char name[50];
	float gpa;
	struct Student *next;
	struct Student *prev;
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
	temp -> prev = NULL;
	return temp;
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
			new -> prev = temp;
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
		start -> prev = temp;
		start = temp;
		
	}
	else if(pos < nos)
	{
		Node *new = setNode(), *temp;
		int i = 1;
		printf("\nInserting in the middle...\n");
		
		temp = start;
		while(i < pos)
		{
			temp = temp -> next;
			i++;
		}

		new -> prev = temp -> prev -> next;
		temp -> prev -> next = new;
		new -> next = temp;
		temp -> prev = new;
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
		new -> prev = temp;
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
		start -> prev = NULL;
		free(temp);
	}
	else if(pos < nos)
	{
		Node *temp;
		int i = 1;
		printf("\nDeleting from the middle...\n");
		
		temp = start;
		while(i < pos)
		{
			temp = temp -> next;
			i++;
		}

		temp -> prev -> next = temp -> next;
		temp -> next -> prev = temp -> prev;
		free(temp);
	}
	else if(pos == nos)
	{
		printf("\nDeleting from the end...\n");
		
		Node *temp = start;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> prev -> next = NULL;
		free(temp);
	}
}

void revTraverse()
{
	Node *temp = start;
	if(start != NULL)
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}

		printf("\n       NULL\n");
		while(temp != NULL)
		{			
			printf("\t^\n");
			printf("\t|");
			printf("\n-------------------\n");
			printf("\nRollNo : %d\n", temp -> rNo);
			printf("\nName   : %s\n", temp -> name);
			printf("\nGPA    : %f\n", temp -> gpa);
			printf("___________________\n");
			
			temp = temp -> prev;
		}
	}
	else
		printf("\nList is empty\n");	
}

void menu()
{
	int ch;
	do
	{
		printf("\n------------------\n");
		printf("DOUBLE LINKED LIST\n");
		printf("------------------\n");
		printf("\n\n----------\n");
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
			int c = count();
			printf("\n\nThere are %d elements in this list\n", c);
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