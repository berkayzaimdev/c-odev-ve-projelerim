#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10

typedef struct
{
	char isim[20];
	char soyisim[20];
	int vizeoran;
	int vize;
	int final;
	float ort;
}ogrenci;

void bilgial(ogrenci*,int,int);
int maxbul(ogrenci*,int);

main()
{
	int vizeoran,i,maxindis2;
	ogrenci* p=(ogrenci*)malloc(sizeof(ogrenci)*COUNT);
	printf("Vize orani=");
	scanf("%d",&vizeoran);
	printf("Final orani=%d\n\n",(100-vizeoran));
	printf("Lutfen ogrenci bilgilerini giriniz.");
	for(i=0;i<COUNT;i++)
	{
		bilgial(p+i,vizeoran,i);
		maxindis2=maxbul(p+i,i);
	}
	printf("\n\n\nEn yuksek ortalama:%0.2f\nBu ortalamaya sahip olan ogrenci:%s %s"
	,(p+maxindis2)->ort
	,(p+maxindis2)->isim
	,(p+maxindis2)->soyisim
	);
	free(p);//sadece free kullanmak bellek temizleme i�lemini tam olarak yap�yor mu bunun cevab�na ula�amad�m
}

void bilgial(ogrenci* p,int vizeoran,int i)
{
	srand(time(NULL));
	printf("\n\n%d.Ogrencinin Bilgileri\n    -------------\nIsim:",i+1);
	scanf("%s",&(p->isim));
	printf("Soyisim:");
	scanf(" %s",&(p->soyisim));
	p->vize=rand()%101;//notlar�n rastgele olmas� daha ger�ek�i sonu�lar verece�i i�in bu �ekilde yapt�m
	printf("-Vize Notu:%d\n",p->vize);
	p->final=rand()%101;
	printf("-Final Notu:%d\n",p->final);
	p->ort=float((vizeoran*p->vize)+((100-vizeoran)*p->final))/float(100);
	printf(" -Ortalamasi:%0.2f",p->ort);	
}

int maxbul(ogrenci* p,int i)
{
	static float max=0;
	static int maxindis;
	if(p->ort>max)
	{
		max=p->ort;
		maxindis=i;
	}
	return maxindis;
}