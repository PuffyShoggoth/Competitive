#include <bits/stdc++.h>
using namespace std;

bool btk[200005];
vector<int> edges[200005];
bool dn[200005];
int sz[200005];
int mxch[200005];
vector<int> subt[200005], fullt[200005];
long long int ttvl, sng;
int frc;
int bit[200005];

void fch(int st, int tpar, int tnc, int tnk){
	sz[st]=1;
	mxch[st]=0;
	tnk+=btk[st];
	tnc+=(!btk[st]);
	subt[tnk].push_back(tnc);
	fullt[tnk].push_back(tnc);
	for(int i: edges[st]){
		if (dn[i] || i==tpar) continue;
		fch(i, st, tnc, tnk);
		if (sz[i]>sz[mxch[st]]){ mxch[st] = i; }
		sz[st]+=sz[i];
	}
}
int gcenter(int cn, int n){
	if (n-sz[cn]>n/2) return 0;
	else if(sz[mxch[cn]]<=n/2) return cn;
	else return gcenter(mxch[cn], n);
}
void update(int ind, int val){
	for(int i = ind+1; i<=frc+1; i+=i&-i){
		bit[i]+=val;
	}
}
int sum(int ind){
	int tsm = 0;
	for(int i = ind+1; i>0; i-=i&-i){
		tsm += bit[i];
	}
	return tsm;
}
int query(int a, int b){
	if (b<0) return 0;
	a--;
	if (a<0) return sum(b);
	else return sum(b)-sum(a);
}
long long int gsum(vector<int> kvls[200005], int lk, int rk, int lc, int rc){
	int tlk = max(0, lk), trk = rk;
	if (rk<lk) return 0;
	lc = max(0, lc);
	if (rc<lc) return 0;
	for(int i=tlk; i<=trk; i++){
		if (i&&(!kvls[i].size())) break;
		for(int j: kvls[i]){
			update(j, 1);
		}
	}

	long long int gtt = 0;
	for(int j=0; j<=rk; j++){
		if (j&&(!kvls[j].size())) break;
		for(int i: kvls[j]){
			gtt+=query(lc-i, rc-i);
		}
		for(int i: kvls[trk]){
			update(i, -1);
		}
		trk--; tlk--;
		if (tlk>=0){
			for(int i: kvls[tlk]){
				update(i, 1);
			}
		}

	}
	tlk = max(0, tlk);
	for(int i=tlk; i<=trk; i++){
		if (i&&(!kvls[i].size())) break;
		for(int j: kvls[i]) update(j, -1);
	}
	return gtt;
}
void dcomp(int cn, int lk, int rk, int lc, int rc){
	dn[cn]=1;
	fullt[0].clear();
	for(int i=1; i<=rk; i++){
		if (!fullt[i].size()) break;
		fullt[i].clear();
	}
	int tlk = lk-btk[cn], trk = rk-btk[cn], tlc = lc-(!btk[cn]), trc = rc-(!btk[cn]);
	for(int i: edges[cn]){
		if (dn[i]) continue;
		subt[0].clear();
		for(int i=1; i<=rk; i++){
			if(!subt[i].size()) break;
			subt[i].clear();
		}
		fch(i, 0, 0, 0);
		ttvl-=gsum(subt, tlk, trk, tlc, trc);
	}
	ttvl+=gsum(fullt, tlk, trk, tlc, trc);
	for(int i=0; i<=trk; i++){
		if (i&&(!fullt[i].size())) break;
		if(i<tlk) continue;
		for(int j: fullt[i]){
			if(j<=trc && j>=tlc) sng++;
		}
	}
	for(int i: edges[cn]){
		if (dn[i]) continue;
		int tp = gcenter(i, sz[i]);
		dcomp(tp, lk, rk, lc, rc);
	}
}
int main(){
	int n, lk, rk, lc, rc;
	scanf("%i%i%i%i%i", &n, &lk, &rk, &lc, &rc);
	frc = rc;
	getchar();
	for(int i=1; i<=n; i++){
		char tp = getchar();
		btk[i]=(tp=='K');
		sng += (btk[i]>=lk && btk[i]<=rk && (!btk[i])>=lc && (!btk[i])<=rc);
	}
	int a, b;
	for(int i=1; i<n; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	fch(1, 0, 0, 0);
	int root = gcenter(1, sz[1]);
	dcomp(root, lk, rk, lc, rc);
	printf("%lli", ttvl/2+sng);
	return 0;
}