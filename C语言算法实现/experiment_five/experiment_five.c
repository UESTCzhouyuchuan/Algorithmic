//finished by zhouyuchuan --2017.12.27
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "experiment5.h"
#include "read_file.h"
#include "find_part.h"

#define MAX_GOODS 100

struct part Good[MAX_GOODS];
int counter=0; 

void goods_update(void);
void goods_delete(void);
void goods_search(void);
void goods_insert(void);
void goods_print(void);
void save(int num); 
int main(void){
    read_file();
	char operate;
	fprintf(stdout,"Item management database:\n"
	  "The following operations are supported:\n"
	"u: update\nd: delete\ns: search\ni: insert\nq: quit and save\np: print\n\n");
	for(;;){
		printf("Enter the operation code: ");
		scanf(" %c",&operate);
		while((getchar())!='\n');
	switch(operate){
		case 'U':case 'u':goods_update();break;
		case 'P':case 'p':goods_print();break;
		case 'D':case 'd':goods_delete();break;
		case 'S':case 's':goods_search();break;
		case 'I':case 'i':goods_insert();break;
		case 'Q':case 'q':save(counter);exit(EXIT_SUCCESS);break;
		default:          printf("Error!\nPlease enter agagin following the message\n");
                          break;
	             }
	}
	return 0;
}
void goods_update(void){
	int num,change;
	int i;
	printf("Enter part number: ");
	fscanf(stdin," %d",&num);
	i = find_part(num);
		if(i>=0){
			printf("Enter its new name: ");
			scanf(" %s",Good[i].name);
			printf("Enter change in quantity on hand: ");
			scanf(" %d",&change);
			Good[i].on_hand+=change;
			printf("Change successfully\n");
		}
	    else
			printf("Not found!\n");
			return;
} 
void goods_print(void){
	int i;
    printf("Number		Name	On_hand\n");
	for(i=0;i<counter;i++){
		printf("%5d	%11s     %d\n",Good[i].number,Good[i].name,Good[i].on_hand);
	}
	return;
}
void goods_delete(void){
	int num;
	printf("Enter part number: ");
	scanf(" %d",&num);
	int i,j;
    j=find_part(num);
    if(j>=0){
		for(i=j;i<counter-1;i++)
		Good[i]=Good[i+1];
		counter--;
	}
	else printf("Part not find!\n");
	return;
}
void goods_search(void){
	int num;
	int i;
	printf("Enter the number of the goods to search: ");
	scanf(" %d",&num);
	i = find_part(num);
		if(i>=0){
			printf("\nNumber	Name	On_hand\n");
			printf("%d	%s	%d\n",Good[i].number,Good[i].name,Good[i].on_hand);
			return ;
		}
	else
	printf("Not found\n");
	return;
}
void goods_insert(void){
	struct part*meno_p;
	int i,j;
		meno_p=(struct part*)malloc(sizeof(struct part));
		if(meno_p==NULL)
		goods_insert();
		if(counter>MAX_GOODS){
			printf("NO--space-left");
			return;
		}
		printf("Enter its number: ");
		scanf(" %d",&meno_p->number);
		if(find_part(meno_p->number)>=0){
			printf("Part already exist.\n");
			free(meno_p);
			return;
		}
	    printf("Enter its name: ");
	    scanf(" %s",meno_p->name);
	    printf("Enter its quantity on hand: ");
	    scanf(" %d",&meno_p->on_hand);
		for( i=0;i < counter;i++){
		 if(Good[i].number>=meno_p->number)
	 	 break;}
			for(j = counter;j>i;j--){
				Good[j]=Good[j-1];
			}
			Good[i]=*meno_p;
			counter++;
			return;
}
void save(int num){
	int i;
	FILE*fp=fopen("goods_information.txt","w+");
	if(fp==NULL){
		perror("error!");
		return;
	}
	fprintf(fp,"%d\n",counter);
	for(i =0 ;i<counter;i++){
		fprintf(fp,"%d\n%s\n%d\n",Good[i].number+1314,Good[i].name,Good[i].on_hand+520);
	}
	return;	
}
/* �� C ����ʵ��һ��С�͵ĳ�����Ʒ����ϵͳ����ϵͳ��Ҫ�߱���Ʒ��Ϣ¼�롢��Ʒ��Ϣ�޸ġ�
��Ʒ��Ϣɾ������Ʒ��Ϣ���ҡ���Ʒ��Ϣ�Ĳ����⼸�����ܡ�����ʵ�ֲ������£�
1) ���������ƣ�ʵ��һ������ѡ��ʽ���������棬���а�������Ʒ��Ϣ�޸�
����Ʒ��Ϣɾ������Ʒ��Ϣ���ҡ��˳�ϵͳ������ 5��ѡ�������Щ���ܿ�
��ѭ�����á�
2) ��Ʒ��Ϣ�ĳ�ʼ��������һ����Ʒ��Ϣ�Ľṹ�壬��������һ��ָ����
�飬�����е�����Ϊָ��ṹ���ָ�롣ʵ��һ�������������е���Ʒ��Ϣ��
�ж�����Ʒ��Ϣ�����ҷ����ڴ汣����ָ�������С�
3) ��Ʒ��Ϣ���޸ģ�ʵ��һ�����������Ʒ��Ϣ���޸Ĺ��ܣ�ʵ�ֿ��Ը�����Ʒ������

�޸���Ʒ��Ϣ���������ַ����Ƚϵķ�ʽ�����Ҵ��޸���Ʒ��
4) ��Ʒ��Ϣ��ɾ����ʵ��һ��������ʵ�ָ�����Ʒ��������ɾ����Ӧ����Ʒ
��Ϣ�Ĺ��ܣ���Ʒ����ͨ���ַ����Ƚϵķ�ʽ�����ҵ����ͷŶ�Ӧָ��ָ���
�ڴ��������ɾ����
5) ��Ʒ��Ϣ�Ĳ��ң�ʵ��һ�������������Ĺ����Ǹ����������Ʒ��������
�Ҷ�Ӧ����Ʒ��Ϣ����Ʒ���Ƶ��ж����ַ����Ƚϵķ�ʽ��ʵ�֣�Ȼ����ø�
ʽ������Ӻ�����ʾ���ҵ�����Ʒ��Ϣ��
6) �˳�ϵͳ�������棺ʵ��һ���ļ�д�뺯����������Ϣ�ĸĶ�д�뵽��Ʒ
��Ϣ�ļ���Ȼ������ϵͳ���й������ѷ�����ڴ档*/

