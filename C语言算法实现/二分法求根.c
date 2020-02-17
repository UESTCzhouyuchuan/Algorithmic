 #include<stdio.h>
 #include<math.h>
 #define eps (1e-5)
 //¶þ·Ö·¨ 2017.12.17 
 double f(double);
 int main(void)
 {
 	double a=1.0,b=2.0;
 	double middle =(a+b)/2;
 	do{
 		if(f(middle)*f(a)<0)
 		{
 			b=middle;
 		}
 		else
 		{
 			a=middle;
 		}
 		middle=(a+b)/2;
 	}while(((middle-a)>eps)&&((b-middle)>eps));
 	printf("Result: %f",middle);
 	return 0;
 } 
 
 double f(double x){
 	return (pow(x,3)+10*x-20) ;//f=x^3+10x-20
 }
