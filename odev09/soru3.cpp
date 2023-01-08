#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
int sirala(int*,int);
int i,j,temp;
int main()
{
	int arr1[N],arr2[N];
	srand(time(NULL));
	int *p,*r,*pr;
	p=arr1;
	r=arr2;
	for(i=0;i<N;i++)
	{
		*(p+i)=rand()%50+1;
		*(r+i)=rand()%50+1;
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-1;j++)
		 {
		 	if(*(p+j)>*(p+j+1))
		 	{
		 		temp=*(p+j);
		 		*(p+j)=*(p+j+1);
		 		*(p+j+1)=temp;
			}
			if(*(r+j)>*(r+j+1))
		 	{
		 		temp=*(r+j);
		 		*(r+j)=*(r+j+1);
		 		*(r+j+1)=temp;
			}
		 }
	}
	printf("Dizi 1  = ");
	for(i=0;i<N;i++)
	 printf("%d ",*(p+i)); 
	printf("\nDizi 2  = ");
	for(i=0;i<N;i++)
	 printf("%d ",*(r+i));
	int dizi[2*N];
	pr=dizi;
	for(i=0;i<2*N;i++)
	{
		if(i<=9)
		 *(pr+i)=*(p+i);
		else
		 *(pr+i)=*(r+i-10);
	}
	*pr=sirala(pr,2*N);
	printf("\n\nSiralanmis Dizi = ");
	for(i=0;i<2*N;i++)
	 printf("%d ",*(pr+i));
}

int sirala(int *pr,int count)
{
	for(i=0;i<count;i++)
	{
	 	for(j=0;j<count-1;j++)
	 	{
	 	 if(*(pr+j)>*(pr+j+1))
		 {
		 		temp=*(pr+j);
		 		*(pr+j)=*(pr+j+1);
		 		*(pr+j+1)=temp;
		 }		
		}
	}
	return *pr;		
}
