#include<stdio.h>
#include<string.h>
int main()
{
	char *str = " i love C programming very much";
	int i,j,k;
	char a[20][20];
	int pos;
	char *word= "very";
	j=0;k=0;

	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			a[k][j] = str[i];
			j++;
		}
		else
		{
			a[k][j]='\0';
			k++;
			j=0;
		}
	}
	a[k][j]='\0';
	for(i=0;i<=k;i++)
	{
		printf("%s\n",a[i]);
	}
	for(i=0;i<k;i++)
	{
		if(strcmp(a[i],word)==0)
		{
			pos = i;
			break;
		}
	}
	for(i=pos;i<k+1;i++)
	{
		strcpy(a[i],a[i+1]);
	}
	k--;
	for(i=0;i<k;i++)
	{
		printf("%s ",a[i]);
	}
	return 0;
}
