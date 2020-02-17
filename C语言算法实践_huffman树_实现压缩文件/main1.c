#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define N 26
#define MSIZE 1000
int n=0;

typedef struct {
    char data;
    double weight;
    int parent;
    int lchild;
    int rchild;
}HTNode;

typedef struct{
    char cd[N*2];
    int start;
}Hcode;

void Check(HTNode ht[], Hcode hc[], char str[]);
void Outputweight(HTNode ht[]);
void CreatHT(HTNode ht[]);
void CreateHcode(HTNode ht[],Hcode hcd[]);
void OutputHcode(Hcode hc[], HTNode ht[]);
void Decode(HTNode ht[], char str0[]);
void info(char str[]);
void Read(char str[]);
void Readl(char str0[]);
void Txt( Hcode hc[],char str[]);
int main()
{
    HTNode symbol[N*4];
    Hcode code[N*2];
    char str[999],str0[999];
    
    Read(str);
    int i=0;
    for(i=0;str[i]!='\0';i++)
        printf("%c",str[i]);
    Check(symbol,code,str);
    for(i=0;i<2*N;i++){
        if(symbol[i].weight!=0)
            n++;
    }
    Outputweight(symbol);
    CreatHT(symbol);
    CreateHcode(symbol,code);
    OutputHcode(code,symbol);
    Txt(code,str);
    Readl(str0);
    Decode(symbol,str0);
    
    return 0;
}
void Readl(char str0[])
{
	FILE*fp;
	if ((fp=fopen("out.txt","r"))==NULL)
	{
		perror("");
	}
	else
	{
		char ch;int i=0;
		while (fscanf(fp,"%c",&ch)!=EOF)
		{
			str0[i++]=ch;
		}
	}
	fclose(fp);
}
void Txt( Hcode hc[],char str[])
{
	FILE*fp;
	if ((fp=fopen("out.txt","w"))==NULL)
	{
		perror("");
	}
	else
	{
		int i=0,j;
		char ch;
		for (i=0;i<2*N;i++)
		{
			ch=str[i];
			if (ch<='z'&&ch>='a')
			{
				for (j=hc[ch-'a'].start;j<2*N;j++)
				fprintf(fp,"%c",hc[ch-'a'].cd[j]);
			}
			else if(ch<='Z'&&ch>='A')
			{
				for (j=hc[ch-'A'+N].start;j<2*N;j++)
				fprintf(fp,"%c",hc[ch-'A'+N].cd[j]);
			}
		}
	}
	fclose(fp);
}
void Check(HTNode ht[], Hcode hc[], char str[]){
    int i,j;
    for(i=0;i<4*N-1;i++){
        ht[i].data='\0';
        ht[i].lchild=ht[i].parent=ht[i].rchild=-1;
        ht[i].weight=0;
    }
    for(i=0;i<2*N;i++){
        hc[i].start=0;
        for(j=0;j<2*N;j++)
            hc[i].cd[j]=0;
    }
    for(i=0;i<N;i++){
        ht[i].data='a'+i;
        ht[i+N].data='A'+i;
    }
    for(i=0;str[i]!='\0';i++){
        if(str[i]>='a'&&str[i]<='z')
            ht[str[i]-'a'].weight++;
        else if(str[i]>='A'&&str[i]<='Z')
            ht[str[i]-'A'+N].weight++;
    }
}

void Outputweight(HTNode ht[]){
    int sum=0;
    int i;
    for(i=0;i<2*N;i++){
        if(ht[i].weight>0)
            sum+=ht[i].weight;
    }
    for(i=0;i<2*N;i++){
        if(ht[i].weight>0)
            printf("%c:%g  ",ht[i].data,ht[i].weight/sum);
    }
    printf("\n");
}

void CreatHT(HTNode ht[]){
    int i=0,k,lnode,rnode;
    double min1,min2;
    for(i=0;i<4*N-1;i++)
        ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
    for(i=2*N;i<2*N+n-1;i++){
        min1=min2=999;
        lnode=rnode=-1;
        for(k=0;k<=i-1;k++)
            if(ht[k].parent==-1&&ht[k].weight){
                if(ht[k].weight<min1){
                    min2=min1;
                    rnode=lnode;
                    min1=ht[k].weight;
                    lnode=k;
                }
                else if(ht[k].weight<min2){
                    min2=ht[k].weight;
                    rnode=k;
                }
                
            }
        ht[i].weight=ht[lnode].weight+ht[rnode].weight;
        ht[i].lchild=lnode;
        ht[i].rchild=rnode;
        ht[lnode].parent=i;
        ht[rnode].parent=i;
    }
}

void CreateHcode(HTNode ht[], Hcode hcd[]){
    int i,f,c;
    Hcode hc;
    for(i=0;i<2*N;i++){
        hc.start=2*N;
        c=i;
        f=ht[i].parent;
        while(f!=-1){
            if(ht[f].lchild==c)
                hc.cd[--hc.start]='0';
            else
                hc.cd[--hc.start]='1';
            c=f;
            f=ht[f].parent;
        }
        hcd[i]=hc;
    }
}

void OutputHcode(Hcode hc[], HTNode ht[]){
	int i,j;
    for(i=0;i<2*N;i++){
        if(ht[i].weight>0){
            printf("%c:",ht[i].data);
            for(j=hc[i].start;j<2*N;j++)
                printf("%c",hc[i].cd[j]);
            printf("\n");
        }
    }
}

void Decode(HTNode ht[], char str0[]){
    int p=N*2+n-2,sym,i;
    printf("After deciphering: \n");
    for (i=0;i<strlen(str0);i++)
    {
        if (str0[i]=='0')
            sym=ht[p].lchild;
        else
            sym=ht[p].rchild;
        if (ht[sym].lchild==-1&&ht[sym].rchild==-1)
        {
            printf("%c",ht[sym].data);
            p=N*2+n-2;
        }
        else
            p=sym;
    }
    printf("\n");
}

void Read(char str[]){
    FILE *fp=fopen("symbol.txt","r");
    if (fp==NULL)
    {
    	perror("");
	}
	else
	{
		int i=0;
    char ch;
    while(fscanf(fp,"%c",&ch)!=EOF){
        str[i]=ch;
        i++;
    }
    str[i]='\0';	
	}
	fclose(fp);
}
