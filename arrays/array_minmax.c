#include<stdio.h>
struct pair
{
	int min;
	int max;
};
struct pair getmaxmin(int a[],int low, int high)
{
	struct pair minmax,mml,mmr;
	int mid;
	if(low==high)
	{
		minmax.min =  a[low];
		minmax.max = a[low];
		return minmax;
	}
	else if(low+1==high)
	{
		minmax.min = a[low];
		minmax.max = a[high];
		return minmax;
	}
	else
	{
		mid = (low+high)/2;
		
		mml = getmaxmin(a,low,mid);
		mmr = getmaxmin(a,mid+1,high);
		if(mml.min<mmr.min)
		{
			minmax.min = mml.min;
		}
		else
		{
			minmax.min = mmr.min;
		}

		if(mml.max>mmr.max)
		{
			minmax.max = mml.max;
		}
		else
		{
			minmax.max= mmr.max;
		}
		return minmax;
	}
}


int main()
{
	int a[]={14,45,23,21,122,12,87,34,56};
	struct pair p = getmaxmin(a,0,8);
	printf("the min element is %d and the max is %d",p.min,p.max);
	return 0;
}
