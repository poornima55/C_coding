#include<stdio.h>
	int a[10] = {98,76,45,99,34,54,43,23,32,21};
int b[10];
void merging(int low,int mid,int high)
{
	int l1,l2,i;
	for(i=low,l1=low,l2 = mid+1;l1<=mid && l2<=high;i++)
	{
		if(a[l1]<a[l2])
		{
			b[i] = a[l1];
			l1++;
		}

		else
		{
			b[i] = a[l2];
			l2++;
		}
	}
	while(l1<=mid)
	{
		b[i] = a[l1];
		i++;l1++;
	}
	while(l2<=high)
	{
		b[i] = a[l2];
		i++;l2++;
	}
	for(i=low;i<=high;i++)
	{
		a[i] = b[i];
	}
}


void merge_sort(int low, int high)
{
	if(low>=high)
		return;
	else
	{
		int mid = (low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merging(low,mid,high);
	}
}


int main()
{
	merge_sort(0,9);

	for(int i=0;i<10;i++)
	printf("%d\n",a[i]);
	return 0;
}
