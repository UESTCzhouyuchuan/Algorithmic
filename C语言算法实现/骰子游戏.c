#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

int roll_dice(void)/*���������n*/ 
{
	int a,b;
	int i;
	a=(rand()%6+1);
	b=(rand()%6+1);
	return (a+b);
} 
bool play_game(void)//�����û������ж���Ϸ�Ƿ���� 
	{
	  char ch;
	printf("Play again?");
	scanf(" %c",&ch);//���û���ѡ��洢��ch��ַ�У�������һ���ж� 
	 
	 /*�������ջس�������ַ�����ֹ����һ��ָ����������*//*��������һ��������Ҫ��* 
	           *��һֱ��Ϊȱ����������˺ü��� �����ٿ��԰�getchar����ע�͵���һ�£�������һ��Y* 
	           *�����Ϸ���������飬Ϊ���������⻨�Ѵ���ʱ�䣬��˼������⣬* 
	           *һ��żȻ����в����ҷ���������⣬Ҳ��֪���������������������
	           *��scanf("�ո�%c",&ch);����������*/ 
	if(ch=='y'||ch=='Y')
	return false;
	if(ch=='n'||ch=='N')
	return true;
	
}
int main(void)
{
	srand((unsigned)time(NULL));
	int time1=0,time2=0;//��¼lose win �Ĵ�����������main�����е�ȫ�ֱ����������䴢��ռ�һֱ���� 
	int n1,n2,i=1;//main�����еġ�ȫ�ֱ����� 

 do{
 	i=1;//ÿ����Ϸ��ʼ��i��ʼΪ1���û�ѡ����� i��ֵ��i��ֵ�������һ��whileѭ��
	    // �Ƿ���У�Ҳ������Ϸ�Ƿ���� 
	n1=roll_dice();
	printf("You rolled: %d\n",n1);
	if(n1==7||n1==11)
	{
		printf("You win!\n");
		time2++;//win�Ĵ��� 
     if(play_game())
       break;                               //�˳�do whileѭ������Ϸ���� 
     else 
       continue;                           //��һ����Ϸ	
	}
	 else if(n1==2||n1==3||n1==12)
	{
		printf("You lose!\n");
		time1++;                          //lose ���� 
	if(play_game())
	  break;                             // �˳�do whileѭ������Ϸ���� 
	else 
	  continue;                         //��һ����Ϸ 
	}
	else 
	{
		printf("Your point is %d\n",n1);//�����Ŀ���� �� 
	}
	
	
	do{                              //�ڲ�whileѭ�������� ������Ͷ�� 
	n2=roll_dice();
	printf("You rolled: %d\n",n2);
	if(n2==7)                        //���չ������7��lose 
	{
		printf("You lose!\n");
		time1++;                   // ��¼lose���� 
		if(play_game())           //�û�����y��Ӧfalse  n��Ӧtrue 
		{
			i=0;                 //�������while��������һ��ѭ�� 
			break;               //�����ڲ�while 
		}
	
		else{
			i=1;              //�������ѭ��������һ����Ϸ    
			break;            //�����ڲ�while 
		}	
	}
	
	else if(n2==n1)
	{
		printf("You win!\n");
		time2++;                    // ��¼win���� 
		if(play_game())
		{
			i=0;                   // 
			break;                 // 
		}
		else
		{
			i=1;                  // 
			break;                // 
		} 
	}
		}while(1);                //��break����whileѭ������С����ռ临�Ӷȣ��������׸�������Ǹ�while 
 }while(i);                      // ��i��ֵ����whileѭ�������õ��û�������ַ� 
	printf("Wins: %d Losses: %d",time2,time1);//�����¼��lose win ���� 
	
	return 0;                   //���� 
	
}
