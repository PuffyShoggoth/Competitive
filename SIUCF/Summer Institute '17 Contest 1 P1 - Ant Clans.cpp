#include <bits/stdc++.h>
using namespace std;
int mst[1<<20], dp[1<<20];
int n, k;
int vtd;
vector<pair<int, int> > edges[25];
inline int fb(unsigned int mask){
	return 31-__builtin_clz(mask);
}
int gmin(int mask){
	if(mst[mask]) return mst[mask]; 
	else if (__builtin_popcount(mask)==k){ return -1; }
	else if (dp[mask]) return dp[mask];
	int lwb = (1<<fb(mask));
	int tp, cmn=-1;
	for(int i=mask; i>lwb; i=(i-1)&mask){
		if(!mst[i]) continue;
		tp = gmin(mask&(~i));
		if(tp>=0){
			if(cmn>=0){ cmn = min(cmn, mst[i]+tp);}
			else{cmn = mst[i]+tp; }
		}
	}
	dp[mask]=cmn;
	return cmn;
}
inline bool vst(int ind){
	return vtd&(1<<ind);
}
void gmst(int mask){
	priority_queue<pair<int, int> > pq;
	int tt = 0, ttn=0; pq.push({0, fb(mask)});
	vtd = 0;
	while(pq.size()){
		pair<int, int> tpp = pq.top();
		pq.pop();
		if((vst(tpp.second)) || (!(mask&(1<<tpp.second)))) continue;
		vtd = vtd|(1<<tpp.second);
		ttn++; tt+= tpp.first;
		if(ttn==k) break;
		for(auto i: edges[tpp.second]){
			if((!vst(i.second)) && (mask&(1<<i.second))){
				pq.push(i);
			}
		}
	}
	if (ttn==k){
		mst[mask]=-tt;
	}
}
int main(){
	int m, a, b, c;
	scanf("%i%i%i", &n, &m, &k);
	if(n%k){
		printf("-1");
		return 0;
	}
	if(n==k){
		printf("0");
		return 0;
	}
	k = n/k;
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &c);
		edges[a-1].push_back({-c, b-1});
		edges[b-1].push_back({-c, a-1});
	}
	c = (1<<k)-1;
	for(int i=(1<<n)-1; i>=c; i--){
		if(__builtin_popcount(i)==k){
			gmst(i);
		}
	}
	printf("%i", gmin((1<<n)-1));
	return 0;
}