#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int sm[128][128];
int gr1[1000005];
int gr2[1000005];
int main() {
	int n, k, x, id;
	scanf("%i%i", &n, &k);
	int fp = k/2;
	int sp = k-fp;
	for(int i=0; i<fp; i++){
		scanf("%i", &x);
		for(int j=0; j<x; j++){
			scanf("%i", &id);
			gr1[id]|=(1<<i);
		}
	}
	for(int i=0; i<sp; i++){
		scanf("%i", &x);
		for(int j=0; j<x; j++){
			scanf("%i", &id);
			gr2[id]|=(1<<i);
		}
	}
	int ptfp = (1<<fp), ptsp = (1<<sp);
	for(int i=0; i<ptsp; i++){
		if(i&gr2[n]){ continue; }
		sm[gr1[n]][i]=1;
	}
	long long int tts=1;
	for(int i=n-1; i>0; i--){
		tts = 0;
		for(int j=0; j<ptfp; j++){
			if(j&gr1[i]){ continue; }
			tts = (tts+sm[j][gr2[i]])%MOD;
		}
		for(int k=0; k<ptsp; k++){
			if(k&gr2[i]){ continue; }
			sm[gr1[i]][k] = (sm[gr1[i]][k]+tts)%MOD;
		}
	}
	printf("%lli", tts);
	return 0;
}