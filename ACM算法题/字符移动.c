#include<stdio.h>
#include<stdbool.h> 
bool rotateString(char* A, char* B) ;
int main(void){
	char a[10];
	char b[10];
	gets(a);
	gets(b);
	if(rotateString(a,b)){
		printf("true");
	}
	else
	printf("false");
	return 0;
}

bool rotateString(char* A, char* B) {
    int i,j,counter;
    char *p=A,*q=B;
    for(counter=0;*(p+counter)!='\0';counter++);
    for(i=0;i<counter;i++){
        if(*p==*(i+q)){
            for(j=i+1;j<counter+i;j++){
                if(*(p+j-i)!=*(q+j%counter))
                 break;   
            }
        }
        if(j==counter+i)
            return true;
    }
    return false;
}
