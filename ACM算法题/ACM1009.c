#include<stdio.h>

int main(void){
	int times;
	scanf(" %d",&times);
	int a,b,output,input,i;
	for (i= 0; i< times; i++)
	{
		scanf (" %d",&input);
		a=input%10;
		b=input%4;
		if(a==1||a==0||a==6||a==5||a==9)
		output=a;
		if(a==2){
			switch(b){
				case 2:output=4;break;
				case 0:output=6;break;
			}
		}
		if(a==3){
			switch(b){
				case 1:output=3;break;
				case 3:output=7;break;
			}
		}
		if(a==4){
			output=6;
		}
		if(a==7){
			switch(b){
				case 1:output=7;break;
				case 3:output=3;break;
			}
		}
		if(a==8){
			if(b==0)
			output=6;
			if(b==2)
			output=4;
		}
		
		printf("%d\n",output);
	}
	return 0;
}
