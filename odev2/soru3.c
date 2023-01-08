#include <stdio.h>
#include <stdlib.h>
main()
{
    int sayi,i,toplam=0;
    for(i=1;i<15000;i++)
    {
        for(sayi=1;sayi<i;sayi++)
        {
            if(i%sayi==0)
             toplam+=sayi;
        }
        
        if(toplam==i)
         printf("%d bir mukemmel sayidir.\n",i);

        toplam=0;
    }
    getch();
    return 0;
}