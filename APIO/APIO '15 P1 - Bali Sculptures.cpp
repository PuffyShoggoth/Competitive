#include <bits/stdc++.h>
using namespace std;
int n, a, b;
long long int pfx[2005];
bool pos[105][105];
int pos2[2005];
//wa
bool vala(long long int mask){
	memset(pos2, -1, sizeof(pos2));
	pos2[0] = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<i; j++){
			if (pos2[j]>=0 && (mask|(pfx[i]-pfx[j]))==mask){
				if (pos2[i]<0) { pos2[i] = pos2[j]+1; }
				else{ pos2[i] = min(pos2[i], pos2[j]+1); }
			}
		}
	}
	return (pos2[n]>=0 && pos2[n]<=b);
}
bool valb(long long int mask){
	memset(pos, 0, sizeof(pos));
	pos[0][0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<b; j++){
			for(int k=0; k<i; k++){
				if (pos[k][j] && (mask|(pfx[i]-pfx[k]))==mask){
					pos[i][j+1] = 1;
					break;
				}
			}
		}
	}
	for(int i=a; i<=b; i++){
		if (pos[n][i]){ return 1; }
	}
	return 0;
}
int main(){
	scanf("%i%i%i", &n, &a, &b);
	for(int i=1; i<=n; i++){
		scanf("%lli",&pfx[i]);
		pfx[i]+=pfx[i-1];
	}
	long long int mnvl = (1LL<<43)-1, st = (1LL<<42);
	while(st){
		if (a==1){
			if (vala(mnvl&(~st))){
				mnvl&=(~st);
			}
		}
		else{
			if (valb(mnvl&(~st))){
				mnvl&=(~st);
			}
		}
		st>>=1;
	}
	printf("%lli", mnvl);
}