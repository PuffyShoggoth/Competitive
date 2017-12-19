#include <bits/stdc++.h>
using namespace std;

int bit[1000005];
int pf[1000005];
int cvl[1000005];
int nv;
int update(int ind, int val){
	for(int i=ind; i<=nv; i+=i&-i){
		bit[i]+=val;
	}
}
int sum(int ind){
	int sm=0;
	for(int i=ind; i>0; i-=i&-i){
		sm+=bit[i];
	}
	return sm;
}
int bs(int k){
	int st=1, ed = nv-1;
	while(st<ed){
		int m=(st+ed)>>1;
		if(sum(m)<k){
			st = m+1;
		}
		else{
			ed = m;
		}
	}
	return ed;
}
vector<pair<char, pair<int, int> > > qrs;
vector<int> frnd; 

map<int, int> pos;
int main(){
	int n, x, r;
	char tpc;
	scanf("%i", &n);
	frnd.push_back(0);
	for(int i=0; i<n; i++){
		getchar();
		tpc = getchar();
		if (tpc=='Q'){
			scanf("%i", &x);
			qrs.push_back({tpc, {x, 0}});
		}
		else{
			scanf("%i%i", &x, &r);
			qrs.push_back({tpc, {x, r}});
			frnd.push_back(r);
		}
	}
	sort(frnd.begin(), frnd.end());
	nv = frnd.size();
	for(int i=0; i<nv; i++){
		pos[frnd[i]]=i;
	}
	for(int i=0; i<qrs.size(); i++){
		if (qrs[i].first == 'Q'){
			printf("%i\n", pf[bs(sum(nv)+1-qrs[i].second.first)]);
		}
		else if (qrs[i].first == 'N'){
			int tpv = pos[qrs[i].second.second];
			pf[tpv]=qrs[i].second.first;
			cvl[qrs[i].second.first]=tpv;
			update(tpv, 1);
		}
		else{
			int tpv = pos[qrs[i].second.second];
			update(cvl[qrs[i].second.first], -1);
			pf[tpv] = qrs[i].second.first;
			cvl[qrs[i].second.first] = tpv;
			update(tpv, 1);
		}
	}
	return 0;
}