#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* string_concat(char str1[],char str2[])
{
	int i=0;
	int j;
	char *str= (char *)malloc(sizeof(char)*100);
	while(str1[i]!='\0')
	{
		*(str+i) = str1[i];
		i++;
	}
	*(str+i)=' ';
	i++;
	for(int j=0;str2[j]!='\0';j++)
	{
		*(str+i)=str2[j];
		i++;
	}
	return str;
}
static int 
str_parse(char *str, char a[20][20])
{
	char temp[20];
	int i;
	int k=0;
	int j=0;


	for(i=0; str[i]!='\0';i++)
	{
		if(str[i]!= ' ')
		{
			a[k][j]= str[i];
			j++;
		}
		else
		{
			a[k][j] ='\0';
			k++;
			j=0;
		}
	}
	a[k][j]='\0';
		for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(strcmp(a[j-1],a[j])>0)
			{
				strcpy(temp,a[j-1]);
				strcpy(a[j-1],a[j]);
				strcpy(a[j],temp);
			}
		}
	}

	return k;
}
void searching(char a[][20],char *search,int k)
{
	int i;
	int flag=0;
	for(i=0;i<=k;i++)
	{
		if(strcmp(a[i],search)==0)
		{
			flag = 1;
			break;
		}
	}
	if(flag==1)
		printf("search successfful found at %d th position\n",i+1);
	else
		printf("not found:(");

	return;
}


int main()
{
	char str1[100]="i love c programming";
	char str2[] = "and c++programming too";
	int i=0;
	int k,j;
	char *search = "tour";
	char a[20][20];

	char temp[20],p[100];

	char *str = string_concat(str1,str2);
	printf("%s\n",str);
	
	k = str_parse(str,a);
	


	printf("the sorted stringlist:\n");
	for(i=0;i<=k;i++)
	{
	printf("%s\n",a[i]);
	}

	
	searching(a,search,k);	

	return 0;
}

