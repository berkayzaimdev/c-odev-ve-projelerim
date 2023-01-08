#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
	char tamsayi[6];
	char okunus[9][7];
}sayi;

int main()
{
    const char sayilar[2][9][7]=
    {
	 {"bir","iki","uc","dort","bes","alti","yedi","sekiz","dokuz"},
	 {"on","yirmi","otuz","kirk","elli","altmis","yetmis","seksen","doksan"}
    };
	sayi* p=(sayi*)malloc(sizeof(sayi));
	printf("Lutfen sayinizi girin:");
	scanf("%s",&p->tamsayi);
	int basamak=0,temp=atoi(p->tamsayi);
	int i;
	while(temp>0)
	{
		temp/=10;
		basamak++;
	}
	int count=0;
	if(basamak<=3)
	{
		for(i=0;i<basamak;i++)
		{
			if(i!=2&&p->tamsayi[basamak-i-1]-49!=-1)
		  	{
				strcpy(p->okunus[count],sayilar[i%2][p->tamsayi[basamak-i-1]-49]);
				count++;
			}
			else if(p->tamsayi[basamak-i-1]-49!=-1)
		 	{
			 	strcpy(p->okunus[count],"yuz");
			 	count++;
			 	if(p->tamsayi[basamak-i-1]-49!=0)
		 	    {
					strcpy(p->okunus[count],sayilar[i%2][p->tamsayi[basamak-i-1]-49]);
					count++;
				}
			}
		}
	}
	else
	{
		for(i=0;i<3;i++)
		{
			if(i!=2&&p->tamsayi[basamak-i-1]-49!=-1)
		  	{
				strcpy(p->okunus[count],sayilar[i%2][p->tamsayi[basamak-i-1]-49]);
				count++;
			}
			else if(p->tamsayi[basamak-i-1]-49!=-1)
		 	{
			 	strcpy(p->okunus[count],"yuz");
			 	count++;
			 	if(p->tamsayi[basamak-i-1]-49!=0)
		 	    {
					strcpy(p->okunus[count],sayilar[i%2][p->tamsayi[basamak-i-1]-49]);
					count++;
					i++;
				}
			}
		}
		strcpy(p->okunus[count],"bin");
		count++;
		for(i=3;i<basamak;i++)
		{
			if(i!=5&&p->tamsayi[basamak-i-1]-49!=-1)
		  	{
				strcpy(p->okunus[count],sayilar[(i-1)%2][p->tamsayi[basamak-i-1]-49]);
				count++;
			}
			else if(p->tamsayi[basamak-i-1]-49!=-1)
		 	{
			 	strcpy(p->okunus[count],"yuz");
			 	count++;
			 	if(p->tamsayi[basamak-i-1]-49!=0)
		 	    {
					strcpy(p->okunus[count],sayilar[(i-1)%2][p->tamsayi[basamak-i-1]-49]);
					count++;
					i++;
				}
			}
		}
	}
	printf("\nSayinizin okunusu:");
	int temp2=count;
    p->okunus[count-1][0]-=32;
	for(count-=1;count>=0;count--)
	{
		if(strcmp(p->okunus[count],"Bir"))
		{
		   printf("%s ",p->okunus[count]);
		}
	}
	free(p);
}
