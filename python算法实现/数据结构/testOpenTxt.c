#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE*fp = fopen("./text.txt","r+");
    if (fp == NULL){
        perror("Error");
    }
    char ch;
    
    while ( fscanf(fp,"%c",&ch)!=EOF){
        printf("%c",ch);
    }
    return 0;
}