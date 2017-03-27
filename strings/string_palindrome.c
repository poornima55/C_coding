#include<stdio.h>
#include<string.h>
int ispalindrome(char str[],int length)
{
	char temp;
	int index =0;
	
	char str1[length+1];
	strcpy(str1,str);
	str1[length+1] = '\0';

	while(index<=length/2)
	{
		temp = str[index];
		str[index] = str[length-index];
		str[length-index] = temp;
		index++;
	}
	printf("%s",str);
	if(strcmp(str1,str)==0)
		return 1;
	else
		return 0;
}



int main()
{
	char str[] = "abbcdba";
	int len = strlen(str);
	int flag = ispalindrome(str,len);
	printf("%s",str);
	if(flag==1)
		printf("is palindrome\n");
	else
		printf("not palindrome\n");
	return 0;
}

