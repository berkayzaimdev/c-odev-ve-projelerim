#include<stdio.h>
int main(){
    int x;
    int y;
    int z;
    int t;
    printf("Lutfen 3 adet sayi giriniz.");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);	
	if(x>y)
		if(x>z)
			t=x;
		else 
			t=z;
	else
		if(y>z)
			t=y;
		else
			t=z;
	printf("Girdiginiz sayilardan en buyugu %d.",t);
    getch();
    return 0;
}
