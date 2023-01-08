#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void charBul(char *,int);

int main()
{
	char *p=(char *)malloc(50*sizeof(char));
	printf("String metninizi giriniz : ");
	gets(p);
	charBul(p,strlen(p));
}

void charBul(char *p,int uzunluk)
{
	char karakter;
	printf("\nMetinde bulmak istediginiz karakteri giriniz : ");
	karakter=getche();
	int i,j=0;
	int *r=(int*)malloc(uzunluk*sizeof(int));
	printf("\n\n");
	for(i=0;i<uzunluk;i++)
	{
		if(karakter==*(p+i))
		{
			if(j==0)	
			  printf("'%c' ilk kez metnin %d.karakterinde bulunur.\nBellek adresi = %p\n"
			  ,karakter,i+1,strchr(p,karakter));
			  
		    else
			  printf("\nMetnin %d.karakterinde de '%c' bulunur.\nBellek adresi = %p\n"
			  ,i+1,karakter,strchr(p,karakter)+i);
			  //onaltýlýk sayý sisteminde artýrýr
			  
		    *(r+j)=i;
			//r dizisi,istenen karakterin geçtiði tüm indisleri tutan dizi
		    j++;
			//j, istenen karakterin stringte kaç kere geçtiðinin sayýsý
		
		}
	}
	if(j!=0)
	 printf("\n\nMetinde toplam %d adet '%c' karakteri bulunur",j,karakter);
	else
	 printf("\n\nMetinde '%c' karakteri bulunmamaktadir.",karakter);
	 
	free(p);
	free(r);
}
