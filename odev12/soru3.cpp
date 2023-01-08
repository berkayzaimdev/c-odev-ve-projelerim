#include <stdio.h>
#include <stdlib.h>

int replace(char *s,char a,char b);

main()
{
	char* s=(char*)malloc(20*sizeof(char));
	char a,b;
	printf("Lutfen kelimenizi girin:");
	gets(s);
	printf("Degistirmek istediginiz harf:");
	a=getchar();
	getchar();//kullan�m hatas� olmamas� i�in sat�r atlad�k
	printf("Yerine gelecek harf:");
	b=getchar();
	printf("\n\n'%c' karakteri,%d kez '%c' karakteri ile degistirildi.\nYeni kelime:%s",a,replace(s,a,b),b,s);
	free(s);
}

int replace(char *s,char a,char b)
{
	int i=0,n=0;
	while(*(s+i)!='\0')
	{
		if(*(s+i)==a)
		{
			*(s+i)=b;
			n++;
		}
		i++;
	}
	return n;
}
