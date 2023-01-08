#include "lib.c"

int maxbul(int [],int);

int main()
{
    srand(time(NULL));
    int sayi;
    printf("Diziniz kac elemanli olsun?\n\n");
    scanf("%d",&sayi);
    int dizi[sayi];
    printf("Dizinin tum elemanlari:");
    for(int i=0;i<sayi;i++)
    {   
        dizi[i]=rand()%50+1;
        printf("%d ",dizi[i]);
    }
    printf("\n\nDizinin en buyuk elemani=%d",maxbul(dizi,sayi));
    getch();
    return 0;
}
int maxbul(int dizi2[],int sayi2)
{
    int max;
    if(sayi2==1)//dizi eğer tek elemanlıysa doğru bir sonuç vermesi için bunu kullandım
    {
      max=dizi2[sayi2-1];
      return max;
    }
    else
    {
     if(dizi2[sayi2-2]<dizi2[sayi2-1])
     {
       max=dizi2[sayi2-1];
       dizi2[sayi2-2]=max;
     }
      sayi2--;
      return maxbul(dizi2,sayi2);
    }
}
