#include<stdio.h>
#include "experiment5.h"
#include "find_part.h"

int find_part(int num){
	int j;
	for(j=0;j<counter;j++){
		if(num==Good[j].number)
		return j;
	}
	return -1;
}



