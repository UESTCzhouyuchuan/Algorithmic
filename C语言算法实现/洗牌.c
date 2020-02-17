#include<stdio.h>
#include<stdlib.h>

void max_poker(char poker[][4],int num[],int times);
struct Poker{
	char Poker[54][4];
}part1,part2;
int main(void){               
	int counter=0;                                 
	int save_number[54];                          //储存输入的54个数字 
	char poker[54][4]={"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
	                   "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
					   "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
					   "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1","J2"};
	int i,j;
	for(i=0;i<54;i++)
	for(j=0;j<4;j++)
	part1.Poker[i][j]=poker[i][j];
	scanf(" %d",&counter);                        //记录重复次数 
	for(i=0;i<54;i++)
	scanf(" %d",&save_number[i]);
	
	max_poker(poker,save_number,counter);
	return 0; 
}
void max_poker(char poker[][4],int num[],int times){
	int i;
   for(i=0;i<times;i++){
   	part2=part1;
   	int j,k;
   	for(j=0;j<54;j++){
   		for(k=0;k<4;k++)
   		part1.Poker[num[j]-1][k]=part2.Poker[j][k];
   	}
   }
   for(i=0;i<54;i++)
   printf("%s ",part1.Poker[i]);
   return ; 
} 
