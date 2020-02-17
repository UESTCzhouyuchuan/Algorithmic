#include<stdio.h>
#include<stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);


int main(void){
	struct ListNode*L1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode*L2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode*l1=L1,*l2=L2;
	l1->val=1,l2->val=9,l1->next=NULL,l2->next=NULL;
	int i;
	for(i=0;i<1;i++){
		struct ListNode *temp1=(struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode *temp2=(struct ListNode*)malloc(sizeof(struct ListNode));
		temp1->val=0,temp2->val=9;
		temp1->next=NULL,temp2->next=NULL;
		l1->next=temp1,l2->next=temp2;
		l1=l1->next,l2=l2->next;
	}	struct ListNode *l=L1,*L=L2;
		for(;;){
		printf(" %d  %d\n",l->val,L->val);
		if(!l->next)
		break;
		l=l->next,L=L->next;
	}
	l1=addTwoNumbers(L1, L2);
	for(;;){
		printf(" %d\n",l1->val);
		if(!l1->next)
		break;
		l1=l1->next;
	}
}	
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode*q=(struct ListNode*)malloc(sizeof(struct ListNode)),*p=q;
    q->next=NULL;
    q->val=0;
    for(;;){
    	q->val+=(l1->val+l2->val);
        if(q->val>=10){
            
            struct ListNode*temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->next=NULL;
            temp->val=q->val/10;
			q->val=q->val%10;
            q->next=temp;} 
        if(!l1->next)
            break;
        if(!q->next){
            struct ListNode*temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->next=NULL;
			temp->val=0;
            q->next=temp;}
        q=q->next;
        l1=l1->next;
        l2=l2->next;
    }
    return p;
}
