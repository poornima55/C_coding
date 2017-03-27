#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void insert(struct node **head, int data)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	if(*head==NULL)
	{
		*head = temp;
	}
	else
	{
		temp->next = *head;
		*head = temp;
	}
return;
}

void display(struct node *head)
{
	
    if(head==NULL)
	    return;
    printf("%d\t",head->data);
    display( head->next);

}
void dis_reverse(struct node *head)
{
	if(head==NULL)
	{
		return;
	
	}
	dis_reverse(head->next);
	
	printf("%d\t",head->data);
	
}
void  search(struct node *head,int data,int index)
{
	if(head->data == data)
	{
		printf("data found at %d position",index);
		return;
	}
	if(head==NULL)
		return;
	search(head,data,index-1);
}
void reverse(struct node **head)
{
	struct node *temp = *head;
	struct node *previous = NULL;
	struct node *next = NULL;
	while(temp!=NULL)
	{
		next = temp->next;
		temp->next = previous;
		previous = temp;
		temp = next;
	}
	*head =  previous;
}

void insert_pos(struct node *head,int data,int pos)
{
	int i;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	struct node *current = head;
	struct node *previous= NULL;
	for(i=0;i<=pos;i++)
	{
		previous = current;
		current = current->next;
		
	}
	previous = current->next;
	current->next = temp;
	temp->next = previous;
	
}



int main()
{
	struct node *head= NULL;
	insert(&head,25);
	insert(&head,32);
	insert(&head,43);
	insert(&head,54);
	insert(&head,65);
	display(head);
	reverse(&head);
	display(head);
	insert_pos(head,33,2);
	printf("newlist\n");
	display(head);
	return 0;
}
