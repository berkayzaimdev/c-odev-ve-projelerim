#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10
#define COUNT2 20

typedef struct
{
	int ogrno;
	int cevap[20];
	int sonuc[3];
}ogr;

main()
{
	srand(time(NULL));
	int i,j,anahtar[20],sonuc[3][10];
	for(i=0;i<COUNT2;i++)
	{
		anahtar[i]=rand()%4+1;
		printf("%d.Soru Cevabi:%d\n",i+1,anahtar[i]);
	}
	ogr* p=(ogr*)malloc(sizeof(ogr)*COUNT);
	for(i=0;i<COUNT;i++)
	{
		(p+i)->ogrno=1000+i;
		(p+i)->sonuc[0]=0;
		(p+i)->sonuc[1]=0;
		(p+i)->sonuc[2]=0;
		for(j=0;j<COUNT2;j++)
		{
			(p+i)->cevap[j]=rand()%5;
			if((p+i)->cevap[j]==anahtar[j])
			   (p+i)->sonuc[0]++;
			else if((p+i)->cevap[j]!=0)
			   (p+i)->sonuc[1]++;
			else
			   (p+i)->sonuc[2]++;
		}
	}
	FILE* dosya;
	if((dosya=fopen("sonuclar.txt","w"))==NULL)
	    printf("\n\nDosya acilamadi.");
	else
	{
		printf("\n\nKayit basarili.");
		fprintf(dosya,"Ogrenci No    Dogru    Yanlis    Bos\n");
		for(i=0;i<COUNT;i++)
	    {
			fprintf(dosya,"%-17d%-11d%-11d%d\n"
			,(p+i)->ogrno
			,(p+i)->sonuc[0]
			,(p+i)->sonuc[1]
			,(p+i)->sonuc[2]);
	    }
	    fclose(dosya);
	}
	free(p);
}
