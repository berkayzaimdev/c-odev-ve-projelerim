#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxbul(int[],int,int,int,int);

int main()
{
    srand(time(NULL));
    int count=10;
    int dizi[count];
    for(int i=0;i<10;i++)
    {
        dizi[i]=rand()%20+1;
        printf("%d ",dizi[i]);
    }
    maxbul(dizi,count,1,dizi[0],0);
    return 0;
}

void maxbul(int dizi[],int count,int k,int max,int temp)
{
    if(k<count)
     {
        if(max<dizi[k])
        {
          max=dizi[k];
          temp=k;
        }
        return maxbul(dizi,count,k+1,max,temp);
     }
     printf("\nDizinin en buyuk elemani = %d\nindisi = %d",max,temp);
}