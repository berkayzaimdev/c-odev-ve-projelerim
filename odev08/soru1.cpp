#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int swapArr(int*,int);
int main()
{
	srand(time(NULL));
	int* p;
	int i,swap,arr[20];
	printf("Dizinin ilk hali = ");
	for(i=0;i<20;i++)
	{
		arr[i]=rand()%50+1;
		printf("%d ",arr[i]);
	}
	p=arr;
	printf("\n\n\nDizi kac eleman boyunca kaydirilsin = ");
	scanf("%d",&swap);
	*p=swapArr(p,swap);
	printf("\n\n\nDizinin son hali = ");
	for(i=0;i<20;i++)
		printf("%d ",*(p+i));
}

int swapArr(int *p,int swap)
{
	int j,k,temp,temp1,temp2,temp3;
	for(j=0;j<swap;j++)
	{ 
	  temp=*(p+19);
		for(k=19;k>0;k--)
		{
		 *(p+k)=*(p+k-1);
		}
	  *p=temp;
	}
	return *p;
}
