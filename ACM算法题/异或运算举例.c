//异或运算 对二进制数的异或运算 ->& 
/*1）使特定位翻转
　　假设有01111010，想使其低4位翻转，即1变为0，0变为1。可以将它与00001111进行∧运算，即
　　
结果值的低4位正好是原数低4位的翻转。要使哪几位翻转就将与其∧运算的该几位置为1即可。这是因为原数中值为1的位与1进行∧运算得0，原数中的位值0与1进行∧运算的结果得1。
　　（2）与0相∧，保留原值
　　如012∧00＝012
　　
因为原数中的1与0进行∧运算得1，0∧0得0，故保留原数。
　　（3）交换两个值，不用临时变量
　　假如a＝3，b＝4。想将a和b的值互换，可以用以下赋值语句实现：
　　a＝a∧b;
　　b＝b∧a;
　　a=a∧b;*/
#include<stdio.h>
int main()
{
int a=5,b=1;
a=a^b;
b=a^b;
a=a^b;
printf("a=%d\nb=%d\n",a,b);
return 0;
}
