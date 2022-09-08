#include <stdio.h>
#include <stdlib.h>

void display(void);
void insertEnd(void);

struct node
{
	int data;
	struct node *next;
};

struct node *head, *new, *temp;

int main()
{
	int size, i, n;
	head = NULL;
	printf("Enter a size of the Linked list :");
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		new = (struct node *)malloc(sizeof(struct node));
		printf("Enter element %d :", i + 1);
		scanf("%d", &new->data);
		if (head == NULL)
		{
			head = temp = new;
		}
		else
		{
			temp->next = new;
			temp = new;
		}
	}
	printf("Before Insertion ");
	display();
	insertEnd();
	return 0;
}

void display()
{
	temp = head;
	printf("Linked list is :\t");
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void insertEnd()
{
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	new = (struct node *)malloc(sizeof(struct node));
	printf("Enter an integer to insert at end :");
	scanf("%d", &new->data);
	temp->next = new;
	new->next = NULL;
	printf("%d is inserted successfully at end\n", new->data);
	printf("After Insertion ");
	display();
}
