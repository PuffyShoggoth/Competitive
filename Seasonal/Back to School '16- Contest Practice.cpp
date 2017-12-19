#include <bits/stdc++.h>
using namespace std;

int psa[200005];

int pw[25];
int main(){
	int p, q, n;
	scanf("%i%i%i", &p, &q, &n);
	pw[0]=1;
	for(int i=1; i<=p; i++){
		pw[i]=pw[i-1]*q;
	}
	int x;
	for(int i=0; i<n; i++){
		int tts = 0;
		for(int j=0; j<p; j++){
			scanf("%i", &x);
			tts+=x*pw[j];
		}
		psa[tts]+=1;
	}
	for(int i=0; i<p; i++){
		for(int j=pw[p]-1; j>=0; j--){
			if((j+pw[i])/pw[i+1] == j/pw[i+1]){
				psa[j]+=psa[j+pw[i]];
			}
		}
	}
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		int tts = 0;
		for(int j=0; j<p; j++){
			scanf("%i", &x);
			tts+=x*pw[j];
		}
		printf("%i\n", psa[tts]);
	}
	return 0;
}