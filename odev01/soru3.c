#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c,delta;
    float x1,x2;
    printf("Lutfen ax^2+bx+c=0 seklindeki denkleminizin a,b,c katsayilarini giriniz.\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a==0)

        printf("Denkleminiz ikinci derece denklem degildir..");

    else
{
    delta=(b*b)-(4*a*c);
    printf("Deltaniz = %d\n",delta);
    if(delta<0)
        printf("Denkleminizin reel koku yoktur.");

    else if(delta>0)
    {
        x1=(-b+sqrt(delta))/(2*a);
        printf("Denkleminizin birinci koku = %d.\n",x1);
        x2=(-b-sqrt(delta))/(2*a);
        printf("Denkleminizin ikinci koku = %d.",x2);
    }

    else
    {
        x1=-b/(2*a);
        printf("Denkleminizin koku = %d.",x1);
    }
}
    getch();
    return 0;
}