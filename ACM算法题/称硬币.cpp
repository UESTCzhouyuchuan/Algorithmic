 #include <bits/stdc++.h>
using namespace std;

char Right[3][8];
char Lift[3][8];
char Result[3][4];
bool isFit(char c, bool light);
int main(void){
	int n;
	int j;
	cin>>n;
	while(n--){
		for ( j = 0 ; j < 3 ; j++)
		scanf("%s %s %s",Lift[j],Right[j],Result[j]);
		for (char c = 'A'; c<='L' ; c++){
			if (isFit(c,true)){
				printf("%c:Light\n",c);break;
			}
			else if(isFit(c,false)){
				printf("%c: Heavy");
				break;
			}
		}
	}
	return 0; 
}
bool isFit(char c,bool light){
	char*L,*R;
	int i;
	for (i = 0; i< 3 ;i++){
		if (light){
			L=Lift[i];
			R=Right[i];
	}
	else{
		L=Right[i];
		R=Lift[i];
	}
	switch(Result[i][0]){
		case 'u':if (strchr(R,c)==NULL)return false;break;
		case 'e':if (strchr(R,c)||strchr(L,c))return false;break;
		case 'd':if (strchr(L,c)==NULL)return false;break;
	}
	}
	return true;
	
}
