#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

int roll_dice(void)/*生成随机数n*/ 
{
	int a,b;
	int i;
	a=(rand()%6+1);
	b=(rand()%6+1);
	return (a+b);
} 
bool play_game(void)//满足用户需求，判断游戏是否进行 
	{
	  char ch;
	printf("Play again?");
	scanf(" %c",&ch);//把用户的选择存储到ch地址中，用于下一步判断 
	 
	 /*用于吸收回车键这个字符，防止程序一个指令运行两次*//*！！！这一步超级重要，* 
	           *我一直因为缺少这个困惑了好几天 ，看官可以把getchar（）注释掉试一下，你输入一个Y* 
	           *这个游戏会运行两遍，为解决这个问题花费大量时间，百思不得其解，* 
	           *一个偶然的灵感才让我发现这个问题，也不知到其他语言有这个问题吗？
	           *用scanf("空格%c",&ch);解决这个问题*/ 
	if(ch=='y'||ch=='Y')
	return false;
	if(ch=='n'||ch=='N')
	return true;
	
}
int main(void)
{
	srand((unsigned)time(NULL));
	int time1=0,time2=0;//记录lose win 的次数，而且是main函数中的全局变量，保持其储存空间一直存在 
	int n1,n2,i=1;//main函数中的”全局变量“ 

 do{
 	i=1;//每次游戏开始让i初始为1，用户选择决定 i的值，i的值决定最后一个while循环
	    // 是否进行，也就是游戏是否继续 
	n1=roll_dice();
	printf("You rolled: %d\n",n1);
	if(n1==7||n1==11)
	{
		printf("You win!\n");
		time2++;//win的次数 
     if(play_game())
       break;                               //退出do while循环，游戏结束 
     else 
       continue;                           //下一次游戏	
	}
	 else if(n1==2||n1==3||n1==12)
	{
		printf("You lose!\n");
		time1++;                          //lose 次数 
	if(play_game())
	  break;                             // 退出do while循环，游戏结束 
	else 
	  continue;                         //下一次游戏 
	}
	else 
	{
		printf("Your point is %d\n",n1);//输出”目标数 “ 
	}
	
	
	do{                              //内层while循环，控制 后续的投掷 
	n2=roll_dice();
	printf("You rolled: %d\n",n2);
	if(n2==7)                        //按照规则输出7则lose 
	{
		printf("You lose!\n");
		time1++;                   // 记录lose次数 
		if(play_game())           //用户输入y对应false  n对应true 
		{
			i=0;                 //控制外层while不进行下一次循环 
			break;               //跳出内层while 
		}
	
		else{
			i=1;              //控制外层循环进行下一次游戏    
			break;            //跳出内层while 
		}	
	}
	
	else if(n2==n1)
	{
		printf("You win!\n");
		time2++;                    // 记录win次数 
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
		}while(1);                //用break跳出while循环，减小代码空间复杂度，但是容易搞混跳出那个while 
 }while(i);                      // 由i的值控制while循环，利用到用户输入的字符 
	printf("Wins: %d Losses: %d",time2,time1);//输出记录的lose win 次数 
	
	return 0;                   //结束 
	
}
