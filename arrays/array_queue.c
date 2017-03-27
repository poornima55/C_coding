#include<stdio.h>
#define MAX 50
struct queue
{
	int rear;
	int front;
	int arr[50];
}q;

void enqueue(int data)
{
	if(q.rear == MAX)
	{
		printf("queue is full\n");
	}
	else
	{
		if(q.front == -1)
			q.front = 0;


	q.arr[q.rear] = data;
	q.rear = q.rear+1;
	}
	return;
}

int dequeue()
{
	int ret;
	if(q.front  == -1 || q.front > q.rear)
	{
		return  -1;
		printf("queue is empty\n");
	}
	else
	{
		ret = q.arr[q.front];
		q.front =  q.front+1;
	}
	return ret;
}

void initialize()
{
	q.front = -1;
	q.rear = 0;
}

int main()
{
	initialize();
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	int i ;
	for(i= q.front; i< q.rear;i++)
	       printf("%d\t",q.arr[i]);
	int val1 = dequeue();
	int val2 = dequeue();
	printf("dequeued values are: %d and %d",val1,val2);
	return 0;
}	

