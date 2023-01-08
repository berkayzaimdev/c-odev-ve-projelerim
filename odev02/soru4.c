#include <math.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
    int i,j;
    double x,toplam=0,faktoriyel=1;
    printf("Lutfen x degerinizi giriniz.\n");
    scanf("%lf",&x);
    for(i=0;i<15;i++)
    {
        for(j=1;j<=i;j++)
        {
         faktoriyel*=j;
        }

      toplam+=pow(x,i)/faktoriyel;
      faktoriyel=1;
    }
    printf("e^%.0lf sonucunuz = %lf",x,toplam);
    getch();
    return 0;
}