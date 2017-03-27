#include<stdio.h>
void findchar(char *str, char ch);
int main()
{
	char str[100]= "poornima";
	char ch;

	
	printf("enter the character that has to be found\n");
	scanf("%c",&ch);
	findchar(str,ch);
	return 0;
}

void findchar(char *str,char ch)
{
	int i=0;
	int flag =0;
	while(str[i]!='\0')
	{
		if(str[i] == ch)
		{
			flag =1;
			break;
		}
		i++;
		
	}
	if(flag==1)
	printf("character is found at %d th index",i);
	else
		printf("character not found");
	return;
}

