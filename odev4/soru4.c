#include <stdio.h>
#include <math.h>
#include <time.h>
int main()
{
    int i,j,k,n,m,p;
    srand(time(NULL));
    printf("Lutfen dizinin eleman sayisini giriniz.\n");
    scanf("%d",&n);
    int dizi[n];
    printf("Dizinin ilk hali = ");
    for(i=0;i<n;i++)
    {
        dizi[i]=rand()%10+1;
        printf("%d ",dizi[i]);
    }
    for(j=0;j<n;j++)
    {
        for(k=j+1;k<n;k++)
         {
             if(dizi[k]==dizi[j])
              {
               n--;
               for(m=0;m<n;m++)
               {
                 dizi[k+m]=dizi[k+m+1];  
               }
               j=-1;
               break;
              }
         }
    }
    printf("\nDizinin son hali = ");
    for(i=0;i<n;i++)
    {
        printf("%d ",dizi[i]);
    }
    getch();
    return 0;
}