#include <bits/stdc++.h>
using namespace std;

vector<int> edges[5005];
int dpth[5005], rem[5005], unc[5005];
int init(int cn, int par){
	for(int i:edges[cn]){
		if (i==par){ continue; }
		dpth[cn] = max(dpth[cn], init(i, cn)+1);
	}
	return dpth[cn];
}
int d, s, tt;
void dfs(int cn, int par){
	if (dpth[cn]==d){
		rem[cn]=d;
		unc[cn]=-1;
		tt++;
		return;
	}
	for(int i:edges[cn]){
	    if (i==par){ continue; }
		if (dpth[i]<d){
			unc[cn]=max(unc[cn], dpth[i]+1);
		}
		else{
			dfs(i, cn);
			if (tt>s){ return; }
			rem[cn] = max(rem[cn], rem[i]-1);
			unc[cn] = max(unc[cn], unc[i]+1);
		}
	}
	if (rem[cn]>=unc[cn]){
		unc[cn]=-1;
	}
	else if (unc[cn]==d){
		rem[cn]=d;
		unc[cn]=-1;
		tt++;
	}
	return;
}

int main(){
	int n, a, b;
	scanf("%i%i", &n, &s);
	for(int i=1; i<n; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	init(1, 0);
	int st, ed;
	st = 0; ed = ceil(n/s);
	while(st<ed){
		d = (st+ed)/2;
		tt=0;
		memset(rem, -1, sizeof(rem));
		memset(unc, 0, sizeof(unc));
		dfs(1, 0);
		if (unc[1]>rem[1]){ tt++; }
		if (tt<=s){
			ed = d;
		}
		else {
			st = d+1;
		}
	}
	printf("%i", ed);
	return 0;
}