#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void kelimeuret();//void fonksiyon kullanma sebebim;char* fonksiyon kulland���mda free ile ayr�lan bellek fonksiyonun sonunda yok edilemiyordu
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
	const char ozel[]={"`~@!$#^*%&()[]{}<>+=_�|/:;��,.?"};
	const char harf[2][18]=
	{
	 {'a','e','i','o','u'},
	 {'b','c','d','f','g','h','j','k','l','m','n','p','s','r','t','x','y','z'}
	};
	char *p=(char*)calloc(sizeof(char),8);//malloc kullan�nca hata verdi�i i�in calloc kulland�m
	p[0]=harf[0][rand()%strlen(harf[0])];//ilk karakter sesli olmal�yd�
	int rakamindis=0,harfindis=0;//kelimenin en az bir rakam ve en az bir sessiz harf i�ermesi i�in gereken de�i�kenler
	while(rakamindis==harfindis)
	{
		rakamindis=rand()%6+1;
		harfindis=rand()%6+1;
	}
	p[rakamindis]=rakam[rand()%strlen(rakam)];
	p[harfindis]=harf[1][rand()%strlen(harf[1])];
	for(j=1;j<7;j++)
	{
		x=rand()%2;//sesli harf ya da sessiz harf se�iminin rastgele olmas� i�in
		if(p[j]=='\0')//o indise �nceden bir de�er atanm��sa tekrar de�i�memesi i�in
		{    
		  if(x==0)
		    p[j]=harf[x][rand()%strlen(harf[x])];
		  else 
		  	p[j]=harf[x][rand()%strlen(harf[x])];
		}
	}
	p[j]=ozel[rand()%strlen(ozel)];//son karakter �zel olmal�yd�
	printf("%3d.Kelime:%s\n",i,p);
	free(p);	
}
