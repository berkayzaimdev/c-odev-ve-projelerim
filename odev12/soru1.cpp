#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char kelime[20];
	int sesli;
	int sessiz;
	int sayi;
}s;

void doldur(s *p,int);
void verial(s *p,int);
void yazdir(s *p,int);

int main()
{
	int i,j;
	s *p=(s*)malloc(15*sizeof(s));
	for(i=0;i<15;i++)
	{
		doldur(p,i);
		verial(p,i);
		yazdir(p,i);
	}
}

void doldur(s *p,int i)
{
	char kelimedizi[15][20]=
	{
		"+M-a3RM6arA5","kaLEM","7k89It!ap","eLMA","bilg123is_ayar125",
		"DoLAp","silgi97","1232r#eSIm","Oy&UN657","dEFter",
		"805Pro*2gram1","34oK/.uL658","1saAT7.80",",tabak","485def3;:4ter436"		
	};
	strcpy((p+i)->kelime,kelimedizi[i]);
}

void verial(s *p,int i)
{
	int j,k,sayicarpani;
	const char *sesli="aeiouAEIOU";
	const char *sessiz="bcdfghjklmnprstxyvzBCDFGHJKLMNPRSTXYVZ";
	(p+i)->sesli=0;
	(p+i)->sessiz=0;
	(p+i)->sayi=0;
	sayicarpani=1;
	for(j=strlen((p+i)->kelime)-1;j>-1;j--)//say� degerinin do�ru hesaplanmas� i�in d�ng�de sondan ba�a do�ru gittim
	{			
		if((p+i)->kelime[j]>47&&(p+i)->kelime[j]<58)//rakamlar�n ascii aral���n� sa�l�yorsa say� de�erini artt�r�r
		{
			(p+i)->sayi+=((p+i)->kelime[j]-48)*sayicarpani;//48 ��kartmazsak ascii koda g�re hatal� sonu� elde ederdik
			sayicarpani*=10;
		}
		k=0;
		while(*(sessiz+k)!='\0'||*(sesli+k)!='\0')//kelime i�erisinde �zel karakter olmas� ihtimaline kar��n ���nc� bir d�ng�ye ihtiya� duyuyoruz
		{//iki dizinin de sonuna ula��ld���nda d�ng� sonlanmal�
			if((p+i)->kelime[j]==*(sesli+k)&&k<strlen(sesli))
				(p+i)->sesli++;
			if((p+i)->kelime[j]==*(sessiz+k)&&k<strlen(sessiz))
			 (p+i)->sessiz++;
			k++;
		}
	}
}

void yazdir(s *p,int i)
{
	printf("Kelime:%s\n -Sesli Harf Sayisi = %d\n -Sessiz Harf Sayisi = %d\n -Sayi Degeri = %d\n\n\n"
			,(p+i)->kelime
			,(p+i)->sesli
			,(p+i)->sessiz
			,(p+i)->sayi);
}