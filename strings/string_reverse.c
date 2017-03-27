#include<stdio.h>
#include<string.h>
void reverse(char str[], int length);
int main()
{
	char str[20];
	printf("enter the string\n");
	scanf("%s",str);
	int length = strlen(str);
	reverse(str,length);
	printf("the reverse string is:%s",str);
	return 0;
}

void reverse(char str[],int length)
{
	char temp;
	int i,j;
	i=0;
	j=length -1;
	while(i<j)
	{
	  temp = str[i];
	 str[i] = str[j];
	 str[j]= temp;
	  i++;
	  j--;
	 }
	
	return;
}

