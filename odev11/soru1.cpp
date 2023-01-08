#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int i,j,satir,sutun;
int* sirala(int*);
int* degerbul(int*,int*);

main()
{
	srand(time(NULL));
	printf("Matrisiniz kac satir olsun = ");
	scanf("%d",&satir);
	printf("Matrisiniz kac sutun olsun = ");
	scanf("%d",&sutun);
	printf("\n\n");
	int *p=(int*)malloc(satir*sutun*sizeof(int));
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
		{
			*(p+i*sutun+j)=rand()%9+1;
			printf("%d ",*(p+i*sutun+j));
		}
		printf("\n");
	}
	p=sirala(p);
	printf("\nSiralanmis Matris:\n\n");
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
			printf("%d ",*(p+i*sutun+j));
		printf("\n");
	}
	int *pdeger=(int*)malloc(sutun*3*sizeof(int));
	pdeger=degerbul(p,pdeger);
	printf("\n\n");
	for(i=0;i<sutun;i++)
	{
	    printf("%d.Sutun Degerleri",i+1);
		printf("\n-En kucuk eleman = %d",*(pdeger+i*3));
		printf("\n-En buyuk eleman = %d",*(pdeger+i*3+1));
		printf("\n-Ortalama = %0.2f",float(*(pdeger+i*3+2))/float(satir));
		printf("\n\n");
	}
	free(p);
	free(pdeger);
}

int* sirala(int* p)
{                          
	int temp,k; 
	for(k=0;k<satir;k++)
	{                   
	for(i=0;i<sutun;i++)
	 {
		for(j=0;j<satir-1;j++)
		{ 
			if(*(p+j*sutun+i)>*(p+(j+1)*sutun+i))
			{
				temp=*(p+j*sutun+i);
				*(p+j*sutun+i)=*(p+(j+1)*sutun+i);
				*(p+(j+1)*sutun+i)=temp;
			}
	 	}
   	 }
	}
	return p;
}

int* degerbul(int* p,int* pdeger)
{
	int ort;
	for(i=0;i<sutun;i++)
	{ 
	   ort=0;
	   for(j=0;j<satir;j++)
			ort+=*(p+j*sutun+i);
	   *(pdeger+i*3)=*(p+i);
	   *(pdeger+i*3+1)=*(p+(sutun*(satir-1)+i));
	   *(pdeger+i*3+2)=ort;//int pointer olduðu için float yerine int olarak toplam deðer atadým ekrana yazdýrýrken satýr sayýsýna bölünüp ortalamasý alýnmýþ olacak
	}
	return pdeger;
}
