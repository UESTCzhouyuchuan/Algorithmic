#include <stdlib.h>
#include<stdio.h>

int main(void){
    int alphaCount = 0,digitCount = 0,otherCount = 0,i;
    printf("Please input the string: ");
    char str[128],alpha[128],digit[128],other[128],ch;
    gets(str);
    for ( i =0 ; str[i]!= '\0';i++){
        ch = str[i];
        if (ch <='9' && ch >='0'){
            digit[digitCount] = ch;
            digitCount++;
        }
        else if( (ch <= 'z' && ch >= 'a') || (ch <='Z' && ch >='A')){
            alpha[alphaCount]=ch;
            alphaCount++;
        }
        else{
            other[otherCount]=ch;
            otherCount++;
        }
    }
    digit[digitCount]='\0';
    alpha[alphaCount]='\0';
    other[otherCount]='\0';
    printf("\nDigistal string lenrth = %d, Digitals: %s\n",digitCount,digit);
    printf("Letter string length = %d, Letters: %s\n",alphaCount,alpha);
    printf("Symbol string length = %d, Symbols: %s\n",otherCount,other);
    return 0;
}