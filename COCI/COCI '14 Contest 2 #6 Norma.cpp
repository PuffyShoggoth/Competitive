#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
const int INF = 0x3f3f3f3f;
int segmxs[1500000];
int segmns[1500000];
int segmxt[1500000];
int segmnt[1500000];
int segnx[1500000];
int segts[1500000];
int segtt[1500000];
int lazymn[1500000];
int lazymx[1500000];
void updmn(int ind, int l, int r, long long int mn){
	long long int tn=(r-l+1);
	segmnt[ind]=(mn*(tn+1)*tn/2)%MOD;
	segmns[ind] = (mn*tn)%MOD;
	segnx[ind] = (segmxs[ind]*mn)%MOD;
	segts[ind] = (segmxt[ind]*mn)%MOD;
}
void updmx(int ind, int l, int r, long long int mn){
	long long int tn = (r-l+1);
	segmxt[ind]=(mn*(tn+1)*tn/2)%MOD;
	segmxs[ind] = (mn*tn)%MOD;
	segnx[ind] = (segmns[ind]*mn)%MOD;
	segts[ind] = (segmnt[ind]*mn)%MOD;
}
void updlazy(int ind, int l, int r){
	if(lazymn[ind]){
		updmn(ind, l, r, lazymn[ind]);
		if(l!=r){
			lazymn[ind*2]=lazymn[ind*2+1]=lazymn[ind];
		}
		lazymn[ind]=0;
	}
	if(lazymx[ind]){
		updmx(ind, l, r, lazymx[ind]);
		if(l!=r){
			lazymx[ind*2]=lazymx[ind*2+1]=lazymx[ind];
		}
		lazymx[ind]=0;
	}
}
void update(int ind, int l, int r, int cl, int cr, long long int mn, bool vl){
	if(r<cl){
		updlazy(ind, l, r);
		long long int cd = cr-r;
		segtt[ind]=(segts[ind]+segnx[ind]*cd)%MOD;
		return;
	}
	if(l>cr){
		return;
	}
	if(cl<=l && cr>=r){
		if(vl){
			lazymx[ind] = mn;
		}
		else{
			lazymn[ind] = mn;
		}
		updlazy(ind, l, r);
		long long int cd = cr-r;
		segtt[ind] = (segts[ind]+segnx[ind]*cd)%MOD;
		return;
	}
	int m = (l+r)/2;
	long long int td = r-m;
	updlazy(ind, l, r);
	update(ind*2+1, m+1, r, cl, cr, mn, vl);
	update(ind*2, l, m, cl, cr, mn, vl);
	segmnt[ind] = (segmnt[ind*2]+segmns[ind*2]*td+segmnt[ind*2+1])%MOD;
	segmns[ind] = (segmns[ind*2]+segmns[ind*2+1])%MOD;
	segmxt[ind] = (segmxt[ind*2]+ segmxs[ind*2]*td+segmxt[ind*2+1])%MOD;
	segmxs[ind] = (segmxs[ind*2]+segmxs[ind*2+1])%MOD;
	segts[ind] = (segts[ind*2] + segnx[ind*2]*td + segts[ind*2+1])%MOD;
	segnx[ind] = (segnx[ind*2] + segnx[ind*2+1])%MOD;
	segtt[ind] = (segtt[ind*2]+segtt[ind*2+1])%MOD;
}

int main() {
	int n;
	vector<pair<int, int> > mxs;
	vector<pair<int, int> > mns;
	mxs.push_back({MOD-1, 0});
	mns.push_back({0, 0});
	int tp;
	scanf("%i", &n);
	long long int tt = 0;
	for(int i=1; i<=n; i++){
		scanf("%i", &tp);
		while(mxs.back().first<=tp){
			mxs.pop_back();
		}
		
		update(1, 1, n, mxs.back().second+1, i, tp, 1);
		mxs.push_back({tp, i});
		while(mns.back().first>=tp){
			mns.pop_back();
		}
		
		update(1, 1, n, mns.back().second+1, i, tp, 0);
		mns.push_back({tp, i});
		tt = (tt+segtt[1])%MOD;
	}
	printf("%lli", tt);
    return 0;
}