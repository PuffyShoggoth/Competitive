#include <bits/stdc++.h> 

using namespace std;

vector<int> ch[30];
int mbm[30];
bool dn[30], hv[30];
int fch(int ind){
	if (dn[ind]){ return mbm[ind];}
	dn[ind] = 1;
	for(int i: ch[ind]){
		mbm[ind]|=fch(i);
	}
	return mbm[ind];
}
int main(){
	int n;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		getchar();
		int pr = getchar()-'A';
		hv[pr]=1;
		for(int i=0; i<10; i++){getchar();}
		char tp = getchar();
		if (tp<'a'){ch[pr].push_back(tp-'A'); hv[tp-'A'] = 1;}
		else{mbm[pr]|=(1<<(tp-'a'));}
	}
	for(int i=0; i<26; i++){
		if (!hv[i]){ continue; }
		putchar(i+'A'); putchar(' '); putchar('='); putchar(' ');
		memset(dn, 0, sizeof(dn));
		fch(i);
		bool pv=0;
		putchar('{');
		for(int j=0; j<26; j++){
			if (mbm[i]&(1<<j)){
				if (pv){putchar(',');}
				pv = 1;
				putchar(j+'a');
			}
		}
		putchar('}'); putchar('\n');
	}
	return 0;

}