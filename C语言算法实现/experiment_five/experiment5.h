#ifndef EXPERIMENT5_H
#define EXPERIMENT5_H

#define NAME_LEN 10

struct part{
	int number;
	char name[NAME_LEN+1];
	int on_hand;
};
extern struct part Good[];

extern int counter; 

#endif

