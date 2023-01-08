#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int sayi,i,j,k,degistir,min,dizi[50];
    srand(time(NULL));
    printf("1-Kabarcik Siralama\n2-Secmeli Siralama\n\nSectiginiz yontemin sayisini giriniz.");
    scanf("%d",&sayi);
    for(i=0;i<10;i++)
    {
     dizi[i]=rand()%10+1;
     printf("%d ",dizi[i]);
    }
    if(!--sayi)
    {
    for(j=0;j<10;j++)
      {
        for(k=0;k<9;k++)
        {
            if(dizi[k]>dizi[k+1])
             {
                 degistir=dizi[k];
                 dizi[k]=dizi[k+1];
                 dizi[k+1]=degistir;
             }

        }
      }
    printf("\n");
     for(i=0;i<10;i++)
      printf("%d ",dizi[i]);
    }
    else
    {
    for(j=0;j<9;j++)
      {
          min=j;
          for(k=j+1;k<10;k++)
          {
              if(dizi[k]<dizi[min])
                min=k;           
          }
              degistir=dizi[j];
              dizi[j]=dizi[min];
              dizi[min]=degistir;   
      }
    printf("\n");
    for(i=0;i<10;i++)
     printf("%d ",dizi[i]);
      
    }
    getch();
    return 0;
}