 #include<stdio.h>
 #include<math.h>
 #define N 100
 #define eps (1e-5)
 double f(double x); 
 
 int main(void)
 {
 	double x1=1.5,x2;
 	int i;
 	double y,z;
 	for(i= 0;i<N;i++)
 	{
 		y=f(x1);
 		z=f(y);
 		x2=z-((z-y)*(z-y)/(z-2*y+x1));
 		if(fabs(x2-x1)<eps){
 			printf("Result: %f",x2);
 			return 0;
 		}
 		x1=x2;
 		
 	}
 	printf("After %d times repeat,no soloved.",N);
 	return 0;
 } 
 double f(double x)
 {
 	return (x*x-6);
 }
