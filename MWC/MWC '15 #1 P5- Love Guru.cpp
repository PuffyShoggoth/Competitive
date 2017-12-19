#include <iostream>
#include <cstring>
using namespace std;
char na[1000009];
char nb[1000009];
int po[10][4];
int main() {
	int ta=0, tb=0, sc;
	scanf("%s", &na);
	scanf("%s", &nb);
	for(int i=0; i<10; i++){
		po[i][0]=(i*i*i*i)%10;
		po[i][1]=i;
		for(int k=2; k<=3; k++){
			po[i][k]=(po[i][k-1]*i)%10;
		}
	}
	for(int i=0; i<strlen(na); i++){
		if((na[i]-'a')<0){ta+=po[(na[i]-'A'+1)%10][(i+1)%4];}
		else{ta+=po[(na[i]-'a'+1)%10][(i+1)%4];}
	}
	for(int i=0; i<strlen(nb); i++){
		if((nb[i]-'a')<0){tb+=po[(nb[i]-'A'+1)%10][(i+1)%4];}
		else{tb+=po[(nb[i]-'a'+1)%10][(i+1)%4];}
	}
	if (ta%10==0){sc=10;}
	else{sc=ta%10;}
	sc+=tb%10;
	if (tb%10==0){sc+=10;}
	printf("%i", sc);
	return 0;
}