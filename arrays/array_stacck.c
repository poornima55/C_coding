#include<stdio.h>
#define MAX 50

struct stack
{
	int arr[MAX];
	int top;
}s;

void push(int data)
{
	if(s.top == MAX)
	{
		printf("stack is full\n");
		return;
	}
	else
	{
	s.top  =  s.top+1;
	s.arr[s.top]= data;
	return;
	}
}

int pop()
{
	int ret;
	if(s.top == -1)
	{
		printf("stack is empty\n");
		return -1;
	}
	else
	{
		 ret =  s.arr[s.top];
		s.top = s.top-1;
	}
	return ret;
}

int peek()
{
	return s.arr[s.top];
}

void initialize()
{
	s.top = -1;
}

int main()
{
	initialize();
	push(2);
	push(3);
	push(4);
	push(5);
	printf("the topmost element:%d",peek());
	int val1 = pop();
	int val2 = pop();
	printf("now  popping the elements %d and %d\n",val1,val2);
	return 0;
}
