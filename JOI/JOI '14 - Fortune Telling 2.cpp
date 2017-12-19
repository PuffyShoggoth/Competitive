#include <bits/stdc++.h>
using namespace std;

long long int aval[200005];
long long int bval[200005];
vector<long long int> segtree[800005];
long long int inar[200005];
pair<long long int, int> inar2[200005];
void build(int ind, int l, int r){
	if (l==r){
		segtree[ind].push_back(inar[l]);
	}
	else{
		build(ind*2, l, (l+r)/2);
		build(ind*2+1, (l+r)/2+1, r);
		for (auto it = segtree[ind*2].begin(); it!=segtree[ind*2].end(); ++it){
			segtree[ind].push_back(*it);
		}
		for (auto it = segtree[ind*2+1].begin(); it!=segtree[ind*2+1].end(); ++it){
			segtree[ind].push_back(*it);
		}
		sort(segtree[ind].begin(), segtree[ind].end());
	}
	return;
}
long long int segtree2[800005];
long long int svals[800005][3];
map<long long int, int> mxvls;
void build2(int ind, int l, int r){
	if (l==r){
		svals[ind][0]=svals[ind][1]=svals[ind][2]=inar2[l].first;
		segtree2[ind]=inar2[l].second;
	}
	else{
		build2(ind*2, l, (l+r)/2);
		svals[ind][0]=svals[ind*2][0];
		svals[ind][1]=svals[ind*2][2];
		build2(ind*2+1, (l+r)/2+1, r);
		svals[ind][2]=svals[ind*2+1][2];
		segtree2[ind]=max(segtree2[ind*2], segtree2[ind*2+1]);
	}
}
int q2(int ind, long long int l, long long int r){
	if (l>svals[ind][2] || r<svals[ind][0]){
		return -1;
	}
	if (l<=svals[ind][0] && r>=svals[ind][2]){
		return segtree2[ind];
	}
	else if (l>svals[ind][1]){
		return q2(ind*2+1, l, r);
	}
	else if (r<=svals[ind][1]){
		return q2(ind*2, l, r);
	}
	else{
		return max(q2(ind*2+1, l, r), q2(ind*2, l, r));
	}
}
int query(int ind, int l, int r, int tl, int tr, long long int mval){
	if (tl>r || tr<l) return 0;
	else if (tl<=l && tr>=r){
		//printf("%i %i %i %i\n",segtree[ind].size(), segtree[ind].lower_bound(mval)->second, l, r);
		return segtree[ind].end()-lower_bound(segtree[ind].begin(), segtree[ind].end(), mval);
	}
	else if(tr<=(l+r)/2){
		return query(ind*2, l, (l+r)/2, tl, tr, mval);
	}
	else if (tl>(l+r)/2){
		return query(ind*2+1, (l+r)/2+1, r, tl, tr, mval);
	}
	else{
		return query(ind*2, l, (l+r)/2, tl, tr, mval)+query(ind*2+1, (l+r)/2+1, r,tl, tr, mval);
	}
}
int main(){
	int n, k, a, b;
	scanf("%i%i", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%lli%lli", &aval[i], &bval[i]);
	}
	int t;
	for(int i=0; i<k; i++){
		scanf("%lli", &inar[i]);
		mxvls[inar[i]]=i;	
	}
	int ind = 0;
	for (auto it = mxvls.begin(); it!=mxvls.end(); ++it){
		inar2[ind]=*it;
		ind++;
	}
	build(1, 0, k-1);
	build2(1, 0, mxvls.size()-1);
	mxvls.clear();
	long long int ttvl = 0;
	for(int i=0; i<n; i++){
		long long int fv = q2(1, min(aval[i], bval[i]), max(aval[i], bval[i])-1);
		long long int tt = query(1, 0, k-1, fv+1, k-1, max(aval[i], bval[i]));
		if (fv==-1){
			if(tt%2){
				ttvl+=bval[i]; //printf("%lli %lli %lli\n", fv, tt, bval[i]);
			}
			else{
				ttvl+=aval[i]; //printf("%lli %lli %lli\n", fv, tt, aval[i]);
			}
		}
		else{
			if(tt%2){
				ttvl+=min(aval[i], bval[i]); //printf("%lli %lli %lli\n", fv, tt, min(aval[i], bval[i]));
			}
			else{
				ttvl+=max(aval[i], bval[i]); //printf("%lli %lli %lli\n", fv, tt, max(aval[i], bval[i]));
			}
		}
	}
	printf("%lli\n", ttvl);
}