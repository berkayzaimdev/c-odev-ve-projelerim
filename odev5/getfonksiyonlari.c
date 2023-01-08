#include "lib.c"

void main()
{
    printf("*********************************************************\n*Bu fonksiyonlarin detayli aciklamasi klasordeki slaytta*\n*********************************************************\n\n");
    printf("getc() fonksiyonu deneme\nGiris:"); 
    printf("Cikis:%c",getc(stdin));
    printf("\n\n\ngetchar() fonksiyonu deneme\nGiris:"); 
    printf("\nCikis:%c",getchar());
    printf("\ngetc() ve getchar() fonksiyonlari ayni programda kullanildigi icin ikinci girilen karakteri direkt yazdirdi.");
    printf("\n\n\ngetch() fonksiyonu deneme\nGiris:");  
    printf("\nCikis:%c",getch());
    printf("\n\n\ngetche() fonksiyonu deneme\nGiris:"); 
    printf("\nCikis:%c",getche());

    getch();
}