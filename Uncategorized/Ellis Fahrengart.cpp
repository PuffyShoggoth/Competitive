#include <bits/stdc++.h>
using namespace std;

int a[100005];
long long int ans[100005];
vector<pair<pair<int, int>, pair<int, int> > >qrs;
long long int bit[100005];
int n, mv;
long long int sm(int a){
	int tp = 0;
	for(int i=a; i>0; i-=(i&(-i))){
		tp+=bit[i];
	}
	return tp;
}
void update(int ind, int val){
	for(int i=ind; i<=mv; i+=(i&(-i))){
		bit[i]+=val;
	}
	return;
}
map<int, int> frnk;
int main(){
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%i", &a[i]);
		frnk[a[i]] = 0;
	}
	int sqn = sqrt(n);
	int q;
	scanf("%i", &q);
	int ta, b;
	for(int i=0; i<q; i++){
		scanf("%i%i", &ta, &b);
		qrs.push_back({{ta/sqn, b}, {ta, i}});
	}
	sort(qrs.begin(), qrs.end());
	int cnt=0;
	for(auto it = frnk.begin(); it!=frnk.end(); ++it){
	    cnt++; it->second = cnt;
	}
	mv = cnt;
	for(int i=1; i<=n; i++){
		a[i] = frnk[a[i]];
	}
	int l = qrs[0].second.first, r = qrs[0].second.first;
	long long int ts = 0, tpi;
	for(auto it = qrs.begin(); it!=qrs.end(); ++it){
		int tr = it->first.second, tl = it->second.first;
		while(r>tr+1){ 
			r--; 
			ts-= (sm(mv) - sm(a[r]));
			update(a[r], -1);
		}
	//	printf("%ia\n", ts);
		while(l> tl){
			l--;
			ts+= sm(a[l]-1);
			update(a[l], 1);
		}
	//	printf("%ib\n", ts);
		while(l<tl){
			ts-=sm(a[l]-1);
			update(a[l], -1);
			l++;
		}
	//	printf("%i %ic\n", ts, tpi);
		while(r<=tr){
			ts+=(sm(mv)-sm(a[r]));
			update(a[r], 1);
			r++;
		}
	//	printf("%i %id\n", ts, tpi);
		ans[it->second.second] = ts;
	}
	for(int i=0; i<q; i++){
		printf("%lli\n", ans[i]);
	}
	return 0;
}