#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void kelimeuret();//void fonksiyon kullanma sebebim;char* fonksiyon kullandýðýmda free ile ayrýlan bellek fonksiyonun sonunda yok edilemiyordu
int i;
main()
{
	srand(time(NULL));
	for(i=1;i<11;i++)
	 kelimeuret();
}

void kelimeuret()
{
	int j,x;
	const char rakam[]={"0123456789"};
	const char ozel[]={"`~@!$#^*%&()[]{}<>+=_–|/:;‘“,.?"};
	const char harf[2][18]=
	{
	 {'a','e','i','o','u'},
	 {'b','c','d','f','g','h','j','k','l','m','n','p','s','r','t','x','y','z'}
	};
	char *p=(char*)calloc(sizeof(char),8);//malloc kullanýnca hata verdiði için calloc kullandým
	p[0]=harf[0][rand()%strlen(harf[0])];//ilk karakter sesli olmalýydý
	int rakamindis=0,harfindis=0;//kelimenin en az bir rakam ve en az bir sessiz harf içermesi için gereken deðiþkenler
	while(rakamindis==harfindis)
	{
		rakamindis=rand()%6+1;
		harfindis=rand()%6+1;
	}
	p[rakamindis]=rakam[rand()%strlen(rakam)];
	p[harfindis]=harf[1][rand()%strlen(harf[1])];
	for(j=1;j<7;j++)
	{
		x=rand()%2;//sesli harf ya da sessiz harf seçiminin rastgele olmasý için
		if(p[j]=='\0')//o indise önceden bir deðer atanmýþsa tekrar deðiþmemesi için
		{    
		  if(x==0)
		    p[j]=harf[x][rand()%strlen(harf[x])];
		  else 
		  	p[j]=harf[x][rand()%strlen(harf[x])];
		}
	}
	p[j]=ozel[rand()%strlen(ozel)];//son karakter özel olmalýydý
	printf("%3d.Kelime:%s\n",i,p);
	free(p);	
}
