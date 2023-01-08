#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 3

typedef struct
{
	char isim[12];
	int deger[30];
	int oran[29];//1'den 2ye ge�i� ... 29'dan 30a ge�i� toplam 29 say� eder
	int egim[29];//�stteki ifade buras� i�in de ge�erli
	int maxbaslangic;
	int maxbitis;
	int haftamaxbaslangic[5];
	int haftamaxbitis[5];
}hisse;

typedef struct
{
	int gun[30];
	int ay[30];
	int yil[30];
}tarih;

void bilgi(hisse*,int);
void tarihuret(tarih*);
void degerdoldur(hisse*,tarih*);
void gunluk(hisse*,tarih*);
void haftalik(hisse*,tarih*);

main()
{
	int i;
	srand(time(NULL));
	hisse *p=(hisse*)malloc(sizeof(hisse)*COUNT);
	tarih *t=(tarih*)malloc(sizeof(tarih));
    tarihuret(t);
	for(i=0;i<COUNT;i++)
	{
		bilgi(p,i);
		degerdoldur(p+i,t);
		printf("\n\nTarih:%d/%d/%d Eldeki Para:10.000 TL",t->gun[0],t->ay[0],t->yil[0]);
		gunluk(p+i,t);
		haftalik(p+i,t);
	}
	free(p);//bellek tam olarak temizleniyor mu emin de�ilim
	free(t);
}

void tarihuret(tarih* t)
{
	int i;
	srand(time(NULL));
	t->gun[0]=rand()%30+1;
    t->ay[0]=rand()%2+11;
    t->yil[0]=rand()%40+1982;
    for(i=1;i<30;i++)
    {
    	if(t->gun[i-1]==30)
    	{
    		t->gun[i]=1;
    		if(t->ay[i-1]==12)//ay 12 ve g�n 30 oldu�unda yeni y�la ve yeni aya ge�i� yapar
    		{
    			t->ay[i]=1;
    			t->yil[i]=(t->yil[i-1])+1;
			}
			else//g�n 30 oldu�unda yeni aya ge�i� yapar
			{
			    t->ay[i]=(t->ay[i-1])+1;
			    t->yil[i]=t->yil[i-1];
			}
		}
		else
		{	
		     t->gun[i]=t->gun[i-1]+1;
		     t->ay[i]=t->ay[i-1];
		     t->yil[i]=t->yil[i-1];
		}
	}
}

void bilgi(hisse* p,int i)
{
	srand(time(NULL));
	printf("\n\n%d.Hissenin Adi:",i+1);
	scanf("%s",(p+i)->isim);
	(p+i)->deger[0]=rand()%901+100;//hisselere 100 ile 1000 aras� rastgele de�er atad�m
}

void degerdoldur(hisse* p,tarih* t)
{
	srand(time(NULL));
	int j=0;
	printf("\n%2d.gun degeri:%-9dTarih:%d/%d/%d"
	,j+1
	,p->deger[j]
	,t->gun[j]
	,t->ay[j]
	,t->yil[j]
	);
	for(j=1;j<30;j++)
	{
		p->egim[j-1]=rand()%3-1;//bu �ekilde -1,0,1 say�lar�ndan birini elde ederiz.
	//Hisse de�erinin art���(1),azal���(-1) ya da sabit(0) kal��� belirlenmi� olacak.
	    p->oran[j-1]=rand()%20+1;// %1 - %20 aras� de�i�im oran�n� olu�turduk
	    p->deger[j]=p->deger[j-1]+((p->egim[j-1]*p->deger[j-1]*p->oran[j-1])/100);
		printf("\n%2d.gun degeri:%-9dDegisim orani:%c%-8dTarih:%d/%d/%d"
		,j+1
		,p->deger[j]
		,'%'
		,p->egim[j-1]*p->oran[j-1]
		,t->gun[j]
		,t->ay[j]
		,t->yil[j]
		);
	}
}


void gunluk(hisse* p,tarih* t)
{
	int j,k,temp,max=0;
	for(j=0;j<29;j++)
	{
		for(k=j+1;k<30;k++)
		{
			temp=(p->deger[k])-(p->deger[j]);
			if(max<temp)
			 {
			   max=temp;
			   p->maxbaslangic=j+1;
			   p->maxbitis=k+1;
			 }
		}
	}
	int adet;
	float kar;
	adet=10000/(p->deger[(p->maxbaslangic)-1]);
	kar=float((p->deger[(p->maxbitis)-1])-(p->deger[(p->maxbaslangic)-1]))/float((p->deger[(p->maxbaslangic)-1]));
	printf("\n\nAylik baz = %d/%d/%d tarihinde %d adet alip %d/%d/%d tarihinde satmak %d TL kar getirir.Kar yuzdesi:%c%0.2f"
	,t->gun[p->maxbaslangic-1]
	,t->ay[p->maxbaslangic-1]
	,t->yil[p->maxbaslangic-1]
	,adet
	,t->gun[p->maxbitis-1]
	,t->ay[p->maxbitis-1]
	,t->yil[p->maxbitis-1]
	,adet*((p->deger[(p->maxbitis)-1])-(p->deger[(p->maxbaslangic)-1]))
	,'%'
	,100*kar);
}

void haftalik(hisse* p,tarih* t)
{
	//1.g�nden 7.g�ne kadar 7-1,7-2,7-3.. 6-1 6-2 6-3...
	int j,k,l,temp,countmax=0,max;
	int tempbaslangic,tempbitis;
	for(l=0;l<5;l++)
	{//l<5 olmas�n�n sebebi 4 hafta 28 g�n.
	 //Bu �ekilde 29 ve 30.g�n a��kta kal�yor.Ben bunu da kontrol etmesini sa�lad�m
		max=0;//hafta boyunca kontrol etti�i i�in her ad�mda max de�erini s�f�rlamal�y�z
	    for(j=7*l;j<7*(l+1);j++)
	    {
		    for(k=j+1;k<7*(l+1);k++)
		    {
		        if(j<30&&k<=30)
		        {
			  
			        temp=(p->deger[k])-(p->deger[j]);
			        if(max<temp)
			        {
			            max=temp;
			            tempbaslangic=j+1;
			            tempbitis=k+1;
			        }
			    }
		    }
 	    }
 	    p->haftamaxbaslangic[countmax]=tempbaslangic;
	    p->haftamaxbitis[countmax]=tempbitis;
	    if(max!=0)
	    {
	    	int adet;
	        float kar;
	        adet=10000/(p->deger[p->haftamaxbaslangic[countmax]-1]);
	        kar=float((p->deger[p->haftamaxbitis[countmax]-1])-(p->deger[p->haftamaxbaslangic[countmax]-1]))/float((p->deger[p->haftamaxbaslangic[countmax]-1]));
	        printf("\n%d.hafta = %d/%d/%d tarihinde %d adet alip %d/%d/%d tarihinde satmak %d TL kar getirir.Kar yuzdesi:%c%0.2f"
			,l+1
			,t->gun[p->haftamaxbaslangic[countmax]-1]
			,t->ay[p->haftamaxbaslangic[countmax]-1]
			,t->yil[p->haftamaxbaslangic[countmax]-1]
			,adet
			,t->gun[p->haftamaxbitis[countmax]-1]
			,t->ay[p->haftamaxbitis[countmax]-1]
			,t->yil[p->haftamaxbitis[countmax]-1]
			,adet*((p->deger[p->haftamaxbitis[countmax]-1])-(p->deger[p->haftamaxbaslangic[countmax]-1]))
			,'%'
			,100*kar);
		}
	    else //hisse,hafta boyunca d���� e�iliminde olabilece�i i�in if ile bunu kontrol etmesini istedim
	     printf("\n%d.hafta = Kar edebileceginiz bir zaman bulunmamaktadir.",l+1);
	    countmax++;
	}
}

