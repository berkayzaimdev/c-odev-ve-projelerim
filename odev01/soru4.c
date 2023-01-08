#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c;
    printf("Lutfen abc ucgeninizin kenar uzunluklarini giriniz.\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a<=0||b<=0||c<=0)
     printf("Lutfen pozitif sayi girisi yapiniz.\n");
    else
    {
     if(a>abs(b-c)&&a<b+c&&b>abs(a-c)&&b<a+c&&c>abs(a-b)&&c<b+a)
{
      if(a==b&&a==c)
       printf("Ucgeniniz eskenar ucgendir.\n");
      else if(a==b||a==c||b==c)
       printf("Ucgeniniz ikizkenar ucgendir.\n");
      else
       printf("Ucgeniniz cesitkenar ucgendir.\n");       
}

     else
     printf("Uzunluk verilerini girdiginiz ucgen,ucgen esitsizligini saglamamaktadir.\n");
    }
    
    getch();
}