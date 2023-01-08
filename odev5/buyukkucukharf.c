#include "lib.c"

void harfkontrol(char [],int);
int main()
{
    int index;
    char sifre[50];
    printf("Lutfen sifrenizi giriniz:");
    gets(sifre);
    index=strlen(sifre);
    harfkontrol(sifre,index);
    getch();
    return 0;
}
void harfkontrol(char sifre[],int index)
{
    int bharf=0,kharf=0,rakam=0;
    for(int i=0;i<index;i++)
    {
        if('a'<=sifre[i]&&sifre[i]<='z')
          kharf++;
        if('A'<=sifre[i]&&sifre[i]<='Z')
          bharf++;
        if('0'<=sifre[i]&&sifre[i]<='9')
          rakam++;
    }
    if(kharf==0||bharf==0||rakam==0||index<10)
    { 
     printf("\n\nSifreniz gecerli degildir.\n");
    if(index<10)
     printf("\n*Sifreniz en az 10 karakterden olusmali.");
    if(kharf==0)
     printf("\n*Sifrenizde kucuk harf bulunmali.");
    if(bharf==0)
     printf("\n*Sifrenizde buyuk harf bulunmali.");
    if(rakam==0)
     printf("\n*Sifrenizde rakam bulunmali.");    
    }
    else
     printf("\n\nSifreniz gecerlidir.");
}