#include "lib.c"
void adamciz(int);
int main()
{
    int kategori,kelime,i=0;
    char sontahmin[15];
    srand(time(NULL));
    kategori=rand()%4;//rastgele kategorinin indisi
    kelime=rand()%10;//rastgele kelimenin indisi
    char kelimeler[4][10][15]=
    {
        {"yunus","timsah","kaplan","leopar","akbaba","kartal","karga","balina","maymun","kanguru"},
        {"portakal","orkide","manolya","armut","ceviz","akasya","incir","begonya","zencefil","kavun"},
        {"kalem","eldiven","fener","bilye","lastik","lamba","ceket","tabak","defter","anahtar"},
        {"avusturya","japonya","hindistan","cezayir","filipinler","meksika","arjantin","italya","polonya","almanya"}   
    };
    switch(kategori)//kelimeleri kategorize ettim,rastgele bir kategori gelmesi için switch case kullanıldı
    {
        case 0:
        printf("Kategoriniz = Hayvan\n\n\n");
        break;
        
        case 1:
        printf("Kategoriniz = Bitki\n\n\n");
        break;
        
        case 2:
        printf("Kategoriniz = Esya\n\n\n");
        break;
        
        case 3:
        printf("Kategoriniz = Ulke\n\n\n");
        break;
        
        default:
        break;
    }
    char tahminler[i];
    while(kelimeler[kategori][kelime][i]!='\0')
    {
        tahminler[i]='_';
        printf("%c",tahminler[i]);
        i++;
    }
    int kalanhak=2*i;//kullanıcıya kelime uzunluğunun 2 katı hak verildi
    int j=i;
    char tahmin;
    while(i!=0&&kalanhak>0)//boş harf kalmadığı anda veya hak bittiği anda döngüden çıkış sağlanacak
    {
        printf("\n\nKalan hakkiniz %d.Lutfen bir harf tahmin ediniz.\n\n",kalanhak);
        tahmin=getche(); 
        printf("\n");
        for(int m=0;m<j;m++)    
        {
            if(tahmin==kelimeler[kategori][kelime][m]&&tahminler[m]=='_')
            {
             tahminler[m]=tahmin;
             i--;
            } 
        }
        if(i!=0)
         adamciz(kalanhak);
        for(int m=0;m<j;m++)//burada mecburen ikinci döngüyü kullandım yukarıdaki önkoşuldan sonra gelmesi için
         printf("%c",tahminler[m]);
        printf("\n");     
        kalanhak--;  
    }
    if(i==0)
        printf("\n\n************************************\n*Tebrikler,kelimeyi dogru bildiniz!*\n************************************");
    else
    {
        printf("\n\nSon bir sansiniz daha var,lutfen tahmininizi tam olarak yaziniz.\n\n");
        scanf("%s",&sontahmin);
        if(strcmp(sontahmin,kelimeler[kategori][kelime]))
        {
          adamciz(kalanhak);
          printf("Maalesef kaybettiniz.");
        }
        else
          printf("\n\n************************************\n*Tebrikler,kelimeyi dogru bildiniz!*\n************************************");
    }
    getch();
    return 0;
}
void adamciz(int kalanhak)
{
    
    switch(kalanhak)
    {
      case(6):
        printf("\n+-------+");
        printf("\n|       |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|\n\n");
        break;

      case(5):
        printf("\n+-------+");
        printf("\n|       |");
        printf("\n|       O");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|\n\n");
        break;

      case(4):
        printf("\n+-------+");
        printf("\n|       |");
        printf("\n|       O");
        printf("\n|       |");
        printf("\n|");
        printf("\n|");
        printf("\n|\n\n");
        break;

      case(3):
        printf("\n+-------+");
        printf("\n|       |");
        printf("\n|       O");
        printf("\n|      /|");
        printf("\n|");
        printf("\n|");
        printf("\n|\n\n");
        break;

      case(2):
        printf("\n+-------+");
        printf("\n|       |");
        printf("\n|       O");
        printf("\n|      /|\\");
        printf("\n|");
        printf("\n|");
        printf("\n|\n\n");
        break;

      case(1):
        printf("\n+-------+");
        printf("\n|       |");
        printf("\n|       O");
        printf("\n|      /|\\");
        printf("\n|      /");
        printf("\n|");
        printf("\n|\n\n");
        break;

      case(0):
        printf("\n+-------+");
        printf("\n|       |");
        printf("\n|       O");
        printf("\n|      /|\\");
        printf("\n|      / \\");
        printf("\n|");
        printf("\n|\n\n");
        break;

    default:
    break;
    }

}
