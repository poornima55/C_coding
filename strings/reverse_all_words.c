#include<stdio.h>
#include<string.h>
void reverse(char *begin,char *end)
{
	char temp;
	while(begin<end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}


void reverse_string(char *str)
{
	char *word =str;
	char  *temp = str;
	while(*temp)
	{
		temp++;
		if(*temp=='\0')
		{
			reverse(word,temp-1);
		}
		if(*temp==' ')
		{
			reverse(word,temp-1);
			word = temp+1;
		}
	}
	
}



int main()
{
	char str[100]= "i love my india";
	int len = strlen(str)-1;

	reverse_string(str);
	printf("the reversed string is %s",str);
	return 0;
}
