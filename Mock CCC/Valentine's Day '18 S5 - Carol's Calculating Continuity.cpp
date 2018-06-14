#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int sieve[100005];
int nk[100005];
int spt[1000005][20];
int mlg[1000005];
int gcdr(int a, int b){if(b){return gcdr(b, a%b);}else{return a;}}
int gcd(int a, int b){return gcdr(max(a,b), min(a,b));}
int main() {
	int n, k;
	scanf("%i%i", &n, &k);
	int mxa=0;
	for(int i=0; i<n; i++){
		scanf("%i", &spt[i][0]);
		mxa = max(mxa, spt[i][0]);
	}
	int lg = log2(n)+1;
	for(int i=1; i<=lg; i++){
		for(int j=0; j+(1<<i)<=n; j++){
			mlg[j]=i;
			spt[j][i]=gcd(spt[j][i-1], spt[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=2; i<320; i++){
		if(sieve[i]){continue;}
		for(int j=i*i; j<=mxa; j+=i){
			sieve[j]=i;
		}
	}
	for(int i=2; i<=mxa; i++){
		if(sieve[i]){nk[i]=nk[i/sieve[i]]+1;}
		else{nk[i]=1;}
	}
	long long int tt=0;
	for(int i=0; i<n; i++){
		for(int j=mlg[i]; j>=0; j--){
			if(nk[spt[i][j]]>=k){
				int nind = i+(1<<j);
				int cgc = spt[i][j];
				int cn=j-1;
				int tp;
				while(cn>=0 && nind<n){
				    cn = min(cn, mlg[nind]);
					tp=gcd(cgc, spt[nind][cn]);
					if(nk[tp]>=k){
						nind+=(1<<cn);
						if(nind==n){break;}
						cgc=tp;
						cn--;
					}
					else if(nk[tp]<k){
						cn--;
					}
				}
				int lind = i;
				cn = j;
				while(cn>=0 && nk[spt[i][cn]]==k){
					cn--;
				}
				if(cn<0){tt+=nind-i; break;}
				cgc = spt[i][cn];
				while(cn>=0){
				    cn = min(cn, mlg[lind]);
					tp=gcd(cgc, spt[lind][cn]);
					if(nk[tp]>k){
						lind+=(1<<cn);
						if(lind==n){break;}
						cgc=tp;
						cn--;
					}
					else if(nk[tp]<=k){
						cn--;
					}
				}
				tt+=nind-lind;
				break;
			}
		}
	}
	printf("%lli", tt);
    return 0;
}