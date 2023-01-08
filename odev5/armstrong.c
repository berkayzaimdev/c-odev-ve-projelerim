#include "lib.c"

void armstrongNumber(char [],int);

int main()
{
    int index;
    char dizi[10];
    printf("Lutfen kontrol etmek istediginiz sayiyi giriniz:");
    gets(dizi);
    index=strlen(dizi);
    armstrongNumber(dizi,index);
    getch();
    return 0;
}

void armstrongNumber(char dizi[],int index)
{
    double toplam=0;//int tanımlandığı takdirde 5'in küpünü derleyici hatası olarak 124 olarak bulduğu için double kullandım.
    double sayi=atoi(dizi);//atoi bir karakter dizisinin integer değerini bulur,metinsel ifadelerde 0 bulur

    for(int i=0;i<index;i++)
        toplam+=pow(dizi[i]-48,3);//ascii koda göre 1=49 2=50... olduğu için int değerine ulaşmak için 48 çıkarmalıydık

    if(toplam==sayi)
     printf("Girdiginiz sayi bir armstrong sayisidir.");
    else
     printf("Girdiginiz sayi bir armstrong sayisi degildir.");
}