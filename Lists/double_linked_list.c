#include <stdio.h>

typedef struct node node;
struct node
{
	int item;

	node *previous;
	node *next;
};

node* create_doubly_linked_list();
node* search(node *head, int item);
node* add_beginning (node *head, int item);
node* add_ending (node *head, int item);
node* remove(node *head, int item);
node* print (node *head);

node* create_doubly_linked_list()
{
	return NULL;
}

node* search(node *head, int item)
{
	while (head != NULL)
	{
		if (head->item == item)
		{
			return head;
		}

		head = head->next;
	}

}

node* add_beginning(node *head, int item)
{
	node *new_node = (node *) malloc(sizeof(node));

	new_node->previous = NULL;
	new_node->next = head;

	return new_node;
}

node* add_ending (node *head, int item)
{
	node *new_node = (node *) malloc(sizeof(node));

	node *current = head;

	if (head == NULL)
	{
		new_node->previous = NULL;
		new_node->next = NULL;

		return new_node;
	}

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = new_node;
	new_node->previous = current;
	new_node->next = NULL;


	return head;

}