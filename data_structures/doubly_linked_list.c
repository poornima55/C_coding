#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head = NULL;
struct node *last = NULL;
void push(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if(head==NULL)
	{
		head=last = temp;
	}
	else
	{
		head->prev = temp;
		temp->next = head;
		head = temp;

	}
}

void insert_last(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if(last == NULL)
	{
		last = temp;
	}
	else
	{
		last->next = temp;
		temp->prev= last;
		last = temp;
	}
}

void display()
{
	printf("displaying the nodes from head");
	struct node *current = head;
	while(current!=NULL)
	{
		printf("%d\t",current->data);
		current = current->next;
	}
}

void display_rev()
{
	printf("displaying the nodes from the last");
	struct node *current = last;
	while(current!=NULL)
	{
		printf("%d\t",current->data);
		current = current->prev;
	}
}

void delete_first()
{
	if(head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		head->next->prev= NULL;

		head = head->next;
	}
}

void delete_last()
{
	if(head->next==NULL)
	{
		head=NULL;
	}
	else
	{
		last->prev->next = NULL;
		last = last->prev;
	}
}

void delete_data(int data)
{
	struct node *current= head;
	while(current->data!=data)
	{
		current = current->next;
	}
	if(current == head)
	{
		head = head->next;
	}
	else
	{
		current->prev->next = current->next;
	}
	if(current == last)
	{
		last = last->prev;
	}
	else
	{
		current->next->prev = current->prev;

	}
}

void insert_after(int data, int newentry)
{
	struct node *current = head;
	struct node *newnode = (struct node*)malloc(sizeof(struct node));

	newnode->data = newentry;
		
	while(current->data!=data)
	{
		current = current->next;
	}
		
	if(current == last)
	{
		newnode->next = NULL;
		
		last->next = newnode;
		
	}
	else
	{
		current->next->prev = newnode;
		newnode->next = current->next;
	}
	current->next = newnode;
	newnode->prev = current;
}

	

void reverse(struct node **head,struct node **head_next)
{
	if(*head!=NULL)
	{
		struct node *temp = (*head_next)->next;
		(*head_next)->next = *head;
		*head = (*head_next);
		(*head_next) = temp;
		reverse(head,(head_next));
	}
}



	
int main()
{
	push(2);
	push(3);
	push(4);
	push(5);
	insert_last(6);
	insert_last(7);
	display();
	printf("\n");
	display_rev();
	printf("\n");
	delete_first();
	printf("\n");
	display();
	delete_last();
	printf("\n");
	display();
	printf("\n");
	delete_data(4);
	printf("\n");

	display();
	printf("\n");
	insert_after(3,8);
	display();
	reverse(&head,&(head->next));
	display();
	return 0;
}	
