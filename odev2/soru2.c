#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{

int sayi,i=6,tahmin;
sayi=rand()%100 + 1;
while(i>0)
{
i--;
printf("Lutfen bir tahmin yapiniz.\n");
scanf("%d",&tahmin);
if(sayi!=tahmin)
 {
     if(sayi>tahmin)
      printf("Kucuk girdiniz!Kalan hakkiniz %d.\n",i);
     else
      printf("Buyuk girdiniz!Kalan hakkiniz %d.\n",i);
 }
else 
 {
      printf("Tahmininiz dogru!");
      break;
 }
}
getch();
return 0;
}