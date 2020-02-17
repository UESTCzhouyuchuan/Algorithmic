#pragma once

#define MaxSize 100

typedef struct
{
	int length;
	char data[MaxSize];
}SqString;
typedef struct snode{
	char data;
	struct snode*next;
}LinkStrNode;

void GetNext(SqString t,int next[]);
int  KMPIndex(SqString s,SqString t);
void GetNextval(SqString t,int nextval[]);
int  KMPIndexl(SqString s,SqString t);
