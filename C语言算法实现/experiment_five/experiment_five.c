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
/* 用 C 语言实现一个小型的超市商品管理系统，该系统需要具备商品信息录入、商品信息修改、
商品信息删除、商品信息查找、商品信息的插入这几个功能。具体实现步骤如下：
1) 软件界面控制：实现一个数字选项式的启动界面，其中包含、商品信息修改
、商品信息删除、商品信息查找、退出系统并保存 5个选项。并且这些功能可
以循环调用。
2) 商品信息的初始化：定义一个商品信息的结构体，并且声明一个指针数
组，数组中的内容为指向结构体的指针。实现一个函数，从已有的商品信息文
中读入商品信息，并且分配内存保存至指针数组中。
3) 商品信息的修改：实现一个函数完成商品信息的修改功能，实现可以根据商品的名称

修改商品信息。其中用字符串比较的方式来查找待修改商品。
4) 商品信息的删除：实现一个函数，实现根据商品的名称来删除对应的商品
信息的功能，商品查找通过字符串比较的方式，查找到后释放对应指针指向的
内存区域，完成删除。
5) 商品信息的查找：实现一个函数，函数的功能是根据输入的商品名称来查
找对应的商品信息，商品名称的判断用字符串比较的方式来实现，然后调用格
式化输出子函数显示查找到的商品信息。
6) 退出系统，并保存：实现一个文件写入函数将所有信息的改动写入到商品
信息文件，然后清理系统运行过程中已分配的内存。*/

