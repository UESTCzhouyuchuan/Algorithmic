#include<stdio.h>
int N,L,V;
char dir,sex;
int main(void){
	
	float time,hlen;
	float len;
	while (scanf("%d %d %d",&N,&L,&V)==3){
		if (N==0&&L==0&&V==0)break;
		time=0.0,hlen=0.0;
		int i;
		for (i= 0; i< N; i++){
			scanf ("%f %s %s",&len,&sex,&dir);
			if(dir=='E')
			len= L-len;
			if(time<(len/V))
			time=(len/V);
			hlen+=len;
		}
		printf("%.2f %.2f\n",time,hlen);
	}
	return 0;
	
}
