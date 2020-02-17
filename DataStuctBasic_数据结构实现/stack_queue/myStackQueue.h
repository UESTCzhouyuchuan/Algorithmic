#pragma once
#define MaxSize 100
#define ElemType int
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

typedef struct linknode{
	ElemType data;
	struct linknode*next;
}LinkStNode;
