#include <bits/stdc++.h>
using namespace std;

int tried[13000000][2];
int vals[13000000];
int triedx[13000000][2];
int indy[13000000];
int cnt=0, cntx=0;

int main(){
	int n, q, k, curr;
	scanf("%i%i", &n, &q);
	long long int x, y, tmp;
	int v;
	for(int i=0; i<n; i++){
		scanf("%lli%lli%i", &x, &y, &v);
		k=log2(x);
		curr=0;
		for(int i=0; i<k; i++){
			bool kek = x&1LL;
			if (triedx[curr][kek]){
				curr = triedx[curr][kek];
			}
			else{
				cntx++;
				triedx[curr][kek]=cntx;
				curr = cntx;
			}
			x>>=1;
		}
		if (indy[curr]){
			curr = indy[curr];
		}
		else{
			cnt++;
			indy[curr]=cnt;
			curr = cnt;
		}
		k=log2(y);
		for(int i=0; i<k; i++){
			bool kek = y&1LL;
			if (tried[curr][kek]){
				curr = tried[curr][kek];
			}
			else{
				cnt++;
				tried[curr][kek]=cnt;
				curr = cnt;
			}
			y>>=1;
		}
		vals[curr]+=v;
	}
	int kx, currx;
	for(int i=0; i<q; i++){
		scanf("%lli%lli", &x, &y);
		k=log2(y); kx=log2(x);
		int tot=0; currx=0;
		for(int j=0; j<=kx; j++){
			bool kekx=x&(1LL<<j);
			if (indy[currx]){
				curr = indy[currx];
				for(int i=0; i<=k; i++){
					bool kek = y&(1LL<<i);
					tot+=vals[curr];
					if (tried[curr][kek]){
						curr=tried[curr][kek];
					}
					else{
						break;
					}
				}
			}
			if (triedx[currx][kekx]){
				currx=triedx[currx][kekx];
			}
			else{
				break;
			}
		}
		printf("%i\n", tot);
	}
}