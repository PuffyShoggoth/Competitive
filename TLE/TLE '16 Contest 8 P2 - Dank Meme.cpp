#include <bits/stdc++.h>
using namespace std;
vector<bool> bits;
int main(){
	int t, n;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		scanf("%i", &n);
		if (n==0){printf("meme");}
		while(n>0){
			bits.push_back(n&1);
			n>>=1;
		}
		while(!bits.empty()){
			if (bits.back()){
				printf("dank ");
			}
			else{printf("meme ");}
			bits.pop_back();
		}
		putchar('\n');
	}
}