#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int obeb(int,int);

int main()
{
    int a,b;
    printf("OBEB'i alinacak iki sayiyi giriniz:");
    scanf("%d %d",&a,&b);
    printf("OBEB(%d,%d) = %d",a,b,obeb(a,b));
    getch();
}

int obeb(int a,int b)
{ 
    if (b!=0)
        return obeb(b,a%b);
    else
        return a;   
}