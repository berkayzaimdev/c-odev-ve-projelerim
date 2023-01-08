#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int main()
{
	char *p=(char *)malloc(sizeof(char)*50);
	printf("     Kelime giriniz = ");
	gets(p);
	int i,j,temp;
	printf("\n");
	for(i=0;i<strlen(p);i++)//küçük harfe çevirme döngüsü
		if(64<*(p+i)&&*(p+i)<91)
			*(p+i)+=32;
	for(i=0;i<strlen(p);i++)//harfleri sýralama döngüsü bubble sort
	{
		for(j=1;j<strlen(p);j++)
		{
			if(*(p+j-1)>*(p+j))
			{
				temp=*(p+j);
				*(p+j)=*(p+j-1);
				*(p+j-1)=temp;
			}
		}
	}
	printf(" Duzenlenmis kelime = ");
	puts(p);
	free(p);
}
