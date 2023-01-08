#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int satir,sutun,i,j;
int** doldur(int**);
void maxbul(int**);

main()
{
	printf("Lutfen satir sayisini girin:");
	scanf("%d",&satir);
	printf("Lutfen sutun sayisini girin:");
	scanf("%d",&sutun);
	int** arr=(int**)malloc(satir*sizeof(int*));//double pointer kullan�m� ile iki boyutlu dizi olu�turma
	for(i=0;i<satir;i++)
	 arr[i]=(int*)malloc(sutun*sizeof(int));//her sat�ra,s�tun say�s� kadar int alan a��yoruz
	doldur(arr);
	maxbul(arr);
	for(i=0;i<satir;i++)
	 free(arr[i]);//double pointer oldu�u i�in �nce t�m sat�rlar� sonra pointer�n kendisini temizledik
	free(arr);
}

int** doldur(int** arr)
{
	int max,min;
	srand(time(NULL));
	printf("\nDizi elemanlarinin maksimum degerini giriniz:");
	scanf("%d",&max);
	printf("Dizi elemanlarinin minimum degerini giriniz:");
	scanf("%d",&min);
	for(i=0;i<satir;i++)
	{
		printf("\n   ");
		for(j=0;j<sutun;j++)
		{
			arr[i][j]=rand()%(max-min+1)+min;
			printf("%d ",arr[i][j]);
		}
	}
}

void maxbul(int** arr)
{
	int temp;
	int* maksimum=(int*)malloc(sizeof(int)*satir);
	printf("\n\n");
	for(i=0;i<satir;i++)
	{
		temp=arr[i][0];
		for(j=1;j<sutun;j++)
		{
			if(temp<arr[i][j])
			 temp=arr[i][j];
		}
		maksimum[i]=temp;
		printf("\n%d.satirin en buyuk elemani = %d",i+1,maksimum[i]);
	}
	free(maksimum);
}
