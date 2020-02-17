//πÿ±’À˘”–µ∆
 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int puzzle[6][8],press[6][8];
bool guess(void){
	int c, r;
	for (r=1; r<5;r++ )
	{
		for (c=1; c<7;c++)
		press[r+1][c]=(puzzle[r][c]+press[r][c]+press[r-1][c]+press[r][c-1]+press[r][c+1])%2;
	}
	for (c=1;c<7;c++)
	{
		if((press[5][c-1]+press[5][c]+press[5][c+1]+press[4][c])%2!=puzzle[5][c])
		return false;
	}
}
void enumate(void){
	int c;
	for(c=1;c<7;c++)
	press[1][c]=0;
	while(guess()==false)
	{
		press[1][1]++;
		c=1;
		while(press[1][c]>1)
		{
			press[1][c]=0;
			c++;
			press[1][c]++;
		}
	}
}
int main(void)
{
	int casee,i,r,c;
	scanf("%d",&casee);
	for(r=0;r<6;r++)
	puzzle[r][0]=puzzle[r][7]=0;
	for(c=0;c<8;c++)
	puzzle[0][c]=0;
	for (i=0;i<casee;i++)
	{
		for (c=1;c<6;c++)
		for (r=1;r<7;r++)
		scanf("%d",&puzzle[c][r]);
		enumate();
		printf("PUZZLE #%d\n",i+1);
		for (c=1;c<6;c++){
		for (r=1;r<7;r++)
			printf("%d ",press[c][r]);
			printf("\n");
		}
		
		
	}
	
	
	return 0;
}
