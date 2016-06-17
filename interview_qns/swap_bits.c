#include <stdio.h>

reverse(char *str)
{
	char *beg=str;
	char *end=str;
	char temp;
	while(*end!='\0')
	{
		end++;
	}
	end--;
	while(beg<end)
	{
		temp = *beg;
		*beg = *end;
		*end = temp;
		beg++;
		end--;
	}
}

int main()
{
	char *str=NULL;
	char name[32]= "Kashinath";
	str = name;
	printf("Original Name: %s\n",name);
	reverse(str);
	printf("Reversed name is: %s\n",name);
}

