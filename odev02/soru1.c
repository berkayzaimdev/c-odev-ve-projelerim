#include <stdio.h>
main()
{
int bosluk,yildiz,i,j,k;
bosluk=18;
yildiz=1;
for(i;i<19;i++)
 {  
    for(j=0;j<bosluk;j++)
    {
     printf(" ");
    }
    for(k=0;k<yildiz;k++)
    {
    printf("*"); 
    }
    printf("\n");
    bosluk--;
    yildiz+=2;  
 }
getch();
}