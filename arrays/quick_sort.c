#include<stdio.h>
#define MAX 8
int a[8] = {14,33,27,10,35,19,42,44};

void swap(int leftptr,int rightptr)
{
	int temp = a[leftptr];
	a[leftptr] = a[rightptr];
	a[rightptr]= temp;
}

int partitionfun(int left,int  right,int pivot)
{
	int leftptr = left-1;
	int rightptr = right;
	while(1)
	{
	while(a[++leftptr]<pivot)
	{}
	while(rightptr>0 && a[--rightptr]>pivot)
	{}
	if(leftptr>=rightptr)
	{
		break;
	}
	else
	{
		swap(leftptr,rightptr);
	}
	}
	swap(leftptr,right);
	return leftptr;
}


void quick_sort(int  left,int right)
{
	int partitionpt,pivot;
	if(left>=right)
		return;
	else
	{
		pivot = a[right];
		partitionpt = partitionfun(left,right,pivot);
		quick_sort(left,partitionpt-1);
		quick_sort(partitionpt+1,right);
	}
}



int main()
{
	int i;
	quick_sort(0,MAX-1);
	for(i=0;i<MAX;i++)
		printf("%d\t",a[i]);
	return 0;
}


