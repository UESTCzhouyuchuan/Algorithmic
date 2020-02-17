#include<stdio.h>
#include<stdbool.h>
#define UNKNOWN qian*1000+bai*100+12

bool seven_nine_eight(int); 
int main(void)
{
	int qian,bai;
	for(qian=1;qian<10;qian++){
		for(bai=0;bai<10;bai++)
		{
			if(seven_nine_eight(UNKNOWN))
			{
				printf("The number we want to acquire: %d\n",UNKNOWN);
			}
		}
	}
	return 0;
}

bool seven_nine_eight(int x){
	
	return (x%9||x%8||x%7)?false:true;
}
