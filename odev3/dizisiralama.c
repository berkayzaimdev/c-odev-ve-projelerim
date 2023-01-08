#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    
    int dizi[15],degistir=0,i,j,imax;
    bool sayac=true;
    float ort=0;
    for(i=0;i<15;i++)
    {
        dizi[i]=20+rand()%40;
    }
    for(i=0;i<15;i++)//dizinin elemanlarını büyükten küçüğe sıralamak için döngü
    {
     for(j=0;j<15;j++)
     {
        if(dizi[i]>dizi[j])//dizinin 1.elemanı 5 2.elemanı 7 olsun 7-5 olarak yazmalı 5,7 -> 5<7 -> 7,5
        {
            degistir=dizi[i];
            dizi[i]=dizi[j];
            dizi[j]=degistir;
        }
        
     }
    }
    imax=dizi[0];//en büyük eleman ile en büyük ikinci elemanın eşit olması ihtimaline karşı değişken
    for(i=0;i<15;i++)
    {
     ort+=dizi[i];
     if(imax>dizi[i]&&sayac)
     {
      imax=dizi[i];
      sayac=false;
     }
     printf("%d\n",dizi[i]);
     
    }
    printf("\n\nDizinin en buyuk elemani = %d\n",dizi[0]);
    printf("Dizinin en kucuk elemani = %d\n",dizi[14]);
    printf("Dizinin ikinci en buyuk elemani = %d\n",imax);
    printf("Dizideki degerlerin aritmetik ortalamasi = %0.2f",ort/15);
    getch();
    return 0;
}
