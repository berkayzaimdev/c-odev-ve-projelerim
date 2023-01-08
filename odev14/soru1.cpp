#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* sayial;
void yazdir(int,int);
void temizle(char**,int);

int main()
{
	int count,i,j;
    printf("Kac tane karmasik sayi toplansin:");
    scanf("%d",&count);
    int real=0,img=0;
    char** karmasik=(char**)malloc(count*sizeof(char*));
    char isaret;
    char* temp[count],reel,imag;
    for(i=0;i<count;i++)
    {
    	karmasik[i]=(char*)malloc(20*sizeof(char));
    	printf("%d.Karmasik Sayi=",i+1);
    	scanf("%s",karmasik[i]);
    	for(j=0;j<strlen(karmasik[i]);j++)
    	{
    	    if(karmasik[i][j]=='+'||(karmasik[i][j]=='-'&&j!=0)||karmasik[i][j]=='i')
    		{
    			if(karmasik[i][j]!='i')
				   temp[i]=strrchr(karmasik[i],karmasik[i][j]);
				else
				   temp[i]=strrchr(karmasik[i],karmasik[i][j+1]);
				break;
		    }    
		}
		if(karmasik[i][j]=='i')
		{
			if(atoi(karmasik[i])==0)
			{
				if(karmasik[i][0]=='-')
				   img-=1;
				else
				   img+=1;
			}
			else
			   img+=atoi(karmasik[i]);
			real+=atoi(temp[i]);
		}
		else
		{
			if(atoi(temp[i])==0)
			{
				if(karmasik[i][j]=='-')
				    img-=1;
				else
				    img+=1;
			}
			else
			    img+=atoi(temp[i]);
			real+=atoi(karmasik[i]);
		}
	}
	yazdir(img,real);
	temizle(karmasik,count);
}

void yazdir(int img,int real)
{
	if(img<0)
	    printf("\nToplam sonucu:%d%di",real,img);
	else if(img==0)
	    printf("\nToplam sonucu:%d",real);
	else
	    printf("\nToplam sonucu:%d+%di",real,img);
}

void temizle(char** karmasik,int count)
{
	int i;
	for(i=0;i<count;i++)
        free(karmasik[i]);
    free(karmasik);
}
