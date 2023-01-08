#include<stdio.h>
#include<conio.h>
int main(){
    int x,y,sonuc;
    int z;
    printf("1 - Toplama.\n2 - Cikarma\n3 - Carpma\n4 - Bolme\n5 - Mod alma\n\nLutfen iki adet sayi giriniz.\n");
    scanf("%d",&x);
    scanf("%d",&y);
    printf("Lutfen yukarida verilen islemlerden kullanmak istediginizi seciniz.\n");
    scanf("%d",&z);
    switch(z)
    {
        case 1:
        sonuc=x+y;
        printf("a ile b'nin toplami = %d",sonuc);
        break;

        case 2:
        sonuc=x-y;
        printf("a ile b'nin farki a-b = %d",sonuc);
        break;

        case 3:
        sonuc=x*y;
        printf("a ile b'nin carpimi = %d",sonuc);
        break;

        case 4:
         if(y==0)
          printf("Sifira bolme islemi yapilamaz.");
         else
          {sonuc=x/y;
          printf("a'nin b'ye bolumu = %d",sonuc);
          }
        break;

        case 5:
         if(y==0)
          printf("Sifira bolme islemi yapilamaz.");
         else
          {
          sonuc=x%y;
          printf("a'nin b'ye bolumunden kalan = %d",sonuc);
          }
        break;

        default:
         printf("Lutfen gecerli bir sayi giriniz.");
         break;
    }
    getch();
    return 0;
}
