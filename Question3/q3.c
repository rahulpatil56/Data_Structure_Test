#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void push(int value, struct Node **top)
{
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	if (node == NULL)
	{
		printf("Memory overflow\n");
	}
	else
	{
		node->data = value;
		node->next = *top;*top = node;
	}
}

int pop(struct Node **top)
{
	int value = 0;
	if ( *top == NULL)
	{
		printf("Empty Stack\n");
	}
	else
	{
		struct Node *temp = *top;
		value = temp->data;*top = temp->next;
		free(temp);
		temp = NULL;
	}
	return value;
}

int peek(struct Node *top)
{
	if (top != NULL)
	{
		return top->data;
	}
	else
	{
		return -1;
	}
}

void sort_array(int arr[], int size)
{
	if (size <= 0)
	{
		return;
	}
	struct Node *top = NULL;
	int temp = 0, j = 0;
	for (int i = 0; i < size; ++i)
	{
		if (top == NULL || peek(top) <= arr[i])
		{
			push(arr[i], & top);
		}
		else
		{
			j = i;
			temp = arr[j];
			while (top != NULL && peek(top) > temp)
			{
				arr[j] = pop( & top);
				j--;
			}
			arr[j] = temp;
			for (j; j <= i; j++)
			{
				push(arr[j], & top);
			}
		}
	}
	for (int i = size - 1; i >= 0; --i)
	{
		arr[i] = pop( & top);
	}
}

void display(int arr[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {8, 5, 7, 1, 9, 12, 10};
	int size = sizeof(arr) / sizeof(arr[0]);
	display(arr, size);
	sort_array(arr, size);
	display(arr, size);
	return 0;
}
