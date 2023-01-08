#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int z1,z2,i,k,j,m,n,dizi[6][6],toplam=0;
    srand(time(NULL));
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)//kaç kez(x,y) durumu geldiğini kontrol etmek için tüm diziye 0 atadık
        {
            dizi[i][j]=0;//standart olarak tüm olasılıkları gerçekleşmemiş kabul ettik
        }       
    }
    for(k=0;k<100;k++)
    {
        z1=rand()%6+1;
        z2=rand()%6+1;
        dizi[z1-1][z2-1]++; //z1-1 yapmamızın sebebi dizi 6 elemanlı fakat en çok 5.indis alabiliyor.Zarda 6 geldiyse bunu 5.indise(6.elemana) atmalıyız
    }
    for(m=0;m<6;m++)  //Bütün olasılıkları yazdırmak için olan kod bloğu
    {
        for(n=0;n<6;n++)
        {
         printf("(%d,%d) gelme durumu = %d\n",m+1,n+1,dizi[m][n]);
         toplam+=dizi[m][n];
        }

    }
    printf("\n\nToplam durum = %d",toplam);
    getch();
    return 0;
}