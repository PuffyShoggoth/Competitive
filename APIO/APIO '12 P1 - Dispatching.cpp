#include <bits/stdc++.h>
using namespace std;
int par[100005];
long long int ld[100005], sal[100005];
long long int sm[100005];
priority_queue<long long int> vls[100005];
long long int m, mxvl=0;
int main(){
	int n;
	scanf("%i%lli", &n, &m);
	int bi, ci, li, root;
	for(int i=1; i<=n; i++){
		scanf("%i%lli%lli", &par[i], &sal[i], &ld[i]);
		if (sal[i]<=m){
			sm[i]=sal[i]; vls[i].push(sal[i]);
		}
	}
	for(int i=n; i>=1; i--){
		mxvl = max(mxvl, ((long long int) vls[i].size())*ld[i]);
		if (vls[par[i]].size()<vls[i].size()){
			sm[par[i]]=sm[i];
			swap(vls[par[i]], vls[i]);
		}
		while(vls[i].size()){
			if (vls[i].top()+sm[par[i]]<=m){
				vls[par[i]].push(vls[i].top());
				sm[par[i]]+=vls[i].top();
				vls[i].pop();
			}
			else if (vls[i].top()<=vls[par[i]].top()){
				sm[par[i]]-=vls[par[i]].top()-vls[i].top();
				vls[par[i]].pop();
				vls[par[i]].push(vls[i].top());
				
				vls[i].pop();
			}
			else{
				vls[i].pop();
			}
		}
	}
	printf("%lli", mxvl);
	return 0;
}