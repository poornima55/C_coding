#include<stdio.h>
#include<string.h>

int  check_palindrome(char str[],int size)
{
	int i,j;

	int flag =1;
	j=size-1;
	i=0;
	while(i<j)
	{
		if(str[i]!=str[j])
		{
			flag = 0;
			break;
		}
	}
	if(flag==1)
		return 1;
	else
		return 0;
}
	

int main()
{
	char *str="abc abcbcba abcdcba bcd";
	char a[20][20],b[20][20];
	int i,j,k,l;
	int flag =0;
	int size;
	int ret;
	char max_string[20],min_string[20];
	
	k=0;
	j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			a[k][j]= str[i];
			j++;
		
		}
	
		else
		{
			a[k][j]= '\0';
			k++;
			j=0;
		}
	}
	a[k][j]= '\0';
	l=0;
	for(i=0;i<=k;i++)
	{
	printf("the substrings are :%s\n",a[i]);
	
	

	strcpy(b[l],a[i]);
		l++;
	}

	for(i=0;i<=l;i++)
		printf("%s\t",b[i]);


	strcpy(max_string,b[0]);
	strcpy(min_string,b[0]);
	for(i=1;i<=l;i++)
	{
		if(strlen(b[l])>strlen(max_string))
		{
			strcpy(max_string,b[l]);
		}
	}

	printf("the max palindrome is %s",max_string);

	return 0;

	
}
