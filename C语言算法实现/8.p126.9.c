#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void generate_random_walk(char walk[12][12]);

int main()
{
   char ch[12][12];
   int i,j,direction,t,a;
   srand(time(NULL));
   for(i=1;i<=10;i++)
   {
       for(j=1;j<=10;j++)
       {
           ch[i][j]='.';
       }
   }
   for(i=0;i<12;i++){
   	ch[i][0]='?';
   	ch[i][11]='?';
   }
   for(j=0;j<12;j++)
   {
   	ch[0][j]='?';
   	ch[11][j]='?';
   }
   i=1,j=1;
    ch[1][1]='A';
         t=0;a=0;
       while(j<=10&&i<10&&t<26&&ch[i][j]>='A'&&ch[i][j]<='Z')
       {
         direction=rand()%4;
         switch(direction)
         {
			 case 0:
			 if(ch[i][j-1]!='.'&&ch[i][j+1]!='.'&&ch[i+1][j]!='.'&&ch[i-1][j]!='.')
             goto b;
             if(ch[i+1][j]=='.')
             {
                 ch[i+1][j]=ch[i][j]+1;
                 i++;
                 t++;
             }
             break;

               case 1:
               if(ch[i][j-1]!='.'&&ch[i][j+1]!='.'&&ch[i+1][j]!='.'&&ch[i-1][j]!='.')
             goto b;
             if(ch[i-1][j]=='.')
             {
                 ch[i-1][j]=ch[i][j]+1;
                 i--;
                 t++;
             }
             break;
             case 2:
             if(ch[i][j-1]!='.'&&ch[i][j+1]!='.'&&ch[i+1][j]!='.'&&ch[i-1][j]!='.')
             goto b;
             if(ch[i][j+1]=='.')
             {
                 ch[i][j+1]=ch[i][j]+1;
                 j++;
                 t++;
             }
             break;
             case 3:
             if(ch[i][j-1]!='.'&&ch[i][j+1]!='.'&&ch[i+1][j]!='.'&&ch[i-1][j]!='.')
             goto b;
             if(ch[i][j-1]=='.')
             {
                 ch[i][j-1]=ch[i][j]+1;
                 j--;
                 t++;
             }
              break;
          }
       }
    
   b:
   if(ch[i][j]=='[')
   ch[i][j]='.';
   for(i=1;i<=10;i++)
   {
       for(j=1;j<=10;j++)
       {
           printf("%c",ch[i][j]);
       }
       printf("\n");
   }
   return 0;
}
