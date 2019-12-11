#include <stdio.h>
#include <stdlib.h.h>
typedef struct node node;
struct node
{
	int item;
	node *next;
};

node* create_linked_list();
node* add(node *head, int item);
node* search(node *head, int item);
node* remove(node *head, int item);
int is_empty(node *head);
void print_linked_list(node *head);

node* create_linked_list ()
{
	return NULL;
}

node* new_node(node *head, int item)
{
	node *new_node = (node *) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = NULL;

	return new_node;
}

node* add_beggining(node *head, int item)
{
	node *new_node = (node *) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;

	return new_node;
}


node* add_ending(node *head, int item)
{
	node *n_node = new_node(head, item);
	
	node *current = head;

	if (head == NULL)
		return n_node;

	while (current->next != NULL)
		current = current->next;

	current->next = n_node;
	
	return head;
}

node* search(node *head, int item)
{
	while(head != NULL)
	{
		if (head->item == item)
		{
			return head;
		}
		head = head->next;
	}

	return NULL;
}

node* remove(node *head, int item)
{
	node *previous = NULL;
	node *current = head;

	while(current != NULL && current->item != item)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return head;
	}
	if (previous == NULL)
	{
		head = head->next;
	}
	else
	{
		previous->next = current->next;
	}

	free(current);

	return head;	
}

int is_empty(node *head)
{
	return (head == NULL);
}

void print_linked_list(node *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->item);

		head = head->next;
	}
}
