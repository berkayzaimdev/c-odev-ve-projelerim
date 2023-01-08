#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,j,dizi[10],toplam=0;
    float ort=0,sapma=0;
    printf("Lutfen 10 adet sayi giriniz.\n");
    for(i=0;i<10;i++)
    {
     scanf("%d",&dizi[i]);
     ort+=dizi[i];
    }
    ort/=10;
    for(j=0;j<10;j++)
    {
    sapma+=pow((dizi[j]-ort),2)/9;
    }
    sapma=sqrt(sapma);
    printf("Dizinizin aritmetik ortalamasi = %0.2f\n",ort);
    printf("Dizinizin standart sapmasi = %0.2f\n",sapma);
    getch();
    return 0;
}