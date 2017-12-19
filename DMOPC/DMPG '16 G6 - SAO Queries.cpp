#include <bits/stdc++.h>
#define MOD (1LL<<18)
using namespace std;
int pfx[262150][530];
int nvl[262150];
long long int cans[530][530];
int mp[262150];
int main() {
	int n, q;
	scanf("%i%i", &n, &q);
	int sqt = sqrt(n), msq=(n-1)/sqt;
	for(int i=0; i<n; i++){
		scanf("%i", &nvl[i]);
	}
	for(int i=0; i<=msq; i++){
		long long int cttl = 0;
		for(int j=i; j<=msq; j++){
			int tp = min((j+1)*sqt, n);
			for(int k=j*sqt; k<tp; k++){
				pfx[nvl[k]][i]++;
				cttl+=pfx[nvl[k]][i];
			}
			cans[i][j]=cttl;
		}
	}
	long long int l, r;
	int sl, sr;
	long long int ans=0;
	for(int i=0; i<q; i++){
		scanf("%lli%lli", &l, &r);
		l=l^ans; r=r^ans;
		sl = l/sqt; sr = r/sqt;
		long long int tt;
		if (sl==sr){
			tt = 0;
			for(int j=l; j<=r; j++){
				mp[nvl[j]]++;
				tt = (tt+mp[nvl[j]])%MOD;
			}
			for(int j=l; j<=r; j++){
				mp[nvl[j]]=0;
			}
		}
		else{
			if (l%sqt>sqt/2){ sl++;}
			if (r%sqt>sqt/2){ sr++;}
			tt=cans[sl][sr-1];
			if (l%sqt>sqt/2){
				for(int j=l; j<sl*sqt; j++){
					mp[nvl[j]]++;
					tt=(tt+pfx[nvl[j]][sl]-pfx[nvl[j]][sr]+mp[nvl[j]])%MOD;
				}
			}
			else{
				for(int j=sl*sqt; j<l; j++){
					tt=(tt-(pfx[nvl[j]][sl]-pfx[nvl[j]][sr]+mp[nvl[j]]))%MOD;
					mp[nvl[j]]--;
				}
			}
			if(r%sqt>sqt/2){
				for(int j=r+1; j<sr*sqt; j++){
					tt=(tt-(pfx[nvl[j]][sl]-pfx[nvl[j]][sr]+mp[nvl[j]]))%MOD;
					mp[nvl[j]]--;
				}
				for(int j=r+1; j<sr*sqt; j++){
					mp[nvl[j]]=0;
				}
			}
			else{
				for(int j=sr*sqt; j<=r; j++){
					mp[nvl[j]]++;
					tt=(tt+pfx[nvl[j]][sl]-pfx[nvl[j]][sr]+mp[nvl[j]])%MOD;
				}
				for(int j=sr*sqt; j<=r; j++){
					mp[nvl[j]]=0;
				}
			}
			if (l%sqt>sqt/2){
				for(int j=l; j<sl*sqt; j++){
					mp[nvl[j]]=0;
				}
			}
			else{
				for(int j=sl*sqt; j<l; j++){
					mp[nvl[j]]=0;
				}
			}
		}
		ans=((tt*2-r+l-1)%MOD+MOD)%MOD;
		printf("%lli\n",ans);
	}
	return 0;
}