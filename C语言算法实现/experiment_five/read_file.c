#include "experiment5.h"
#include "read_file.h"

#include<stdio.h>

void read_file(void){
	FILE*fp;
	if((fp=fopen("goods_information.txt","r+"))==NULL)
	{
		perror("Error:");
		return;
	}
	/*struct part *meno_p;
	if((meno_p=(struct part*)malloc(sizeof(struct part)))==NULL)
	{
		read_file();
		return;
	}*/
	int number;
	fscanf(fp,"%1d",&number);
	while(counter<number){
		fscanf(fp," %d",&Good[counter].number);
		Good[counter].number-=1314;
		fscanf(fp," %s",Good[counter].name);
		fscanf(fp," %d",&(Good[counter].on_hand));
		Good[counter].on_hand-=520;
		counter++;
	}
	
}


