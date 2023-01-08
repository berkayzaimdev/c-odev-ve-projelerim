#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max,min;
int *maxp,*minp;
float *avgp;
void hesap(int [],int,int,int,float*);
void hesap(int arr[],int n,int enb,int enk,float *ort)
{
	int j;
	float avg=0;
	int *p=arr;
	maxp=p;
	minp=p;
	for(j=0;j<n;j++)
	{
	    avg+=float(*(p+j))/n;
		if(*maxp<*(p+j))
		 maxp=(p+j);
		if(*minp>*(p+j))
		 minp=(p+j);
	}
	avgp=&avg;
	max=*maxp;
    min=*minp;
}
int main()
{
	int n=10;
	srand(time(NULL));
	int i,arr[n];
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%50+1;
		printf("%d ",arr[i]);
	}
	max=arr[0];
	min=arr[0];
	hesap(arr,n,max,min,avgp);
	printf("\nDizinin en buyuk degeri = %d\nDizinin en kucuk degeri = %d\nDizinin ortalamasi = %0.3f",*maxp,*minp,*avgp);
}


