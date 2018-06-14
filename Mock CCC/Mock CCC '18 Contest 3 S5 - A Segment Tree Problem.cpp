#include <bits/stdc++.h>
using namespace std;
const long long int INF = 0x3f3f3f3f;
#define MAXP 2000005
struct node{
	long long int cost;
	long long int num, lazy;
	bool sold;
	node():cost(0),num(0),lazy(0),sold(0){};
};
node segtree[8000020];
void upl(long long int ind){
	segtree[ind].sold=1;
	segtree[ind].lazy=0;
	segtree[ind].cost=0;
	segtree[ind].num=0;
}
void upn(long long int ind, long long int l, long long int r){
	if(segtree[ind].sold){
		if(l!=r){
			upl(ind*2);
			upl(ind*2+1);
		}
	}
	segtree[ind].sold=0;
	if(l!=r){
		long long int m=(l+r)/2;
		segtree[ind*2].lazy+=segtree[ind].lazy;
		segtree[ind*2+1].lazy+=segtree[ind].lazy;
		segtree[ind].cost=segtree[ind*2].cost+segtree[ind*2+1].cost +
			segtree[ind*2].lazy*(m-l+1)*(m+l)/2 + segtree[ind*2+1].lazy*(r-m)*(r+m+1)/2;
		segtree[ind].num=segtree[ind*2].num+segtree[ind*2+1].num + 
			segtree[ind*2].lazy*(m-l+1) + segtree[ind*2+1].lazy*(r-m);
	}
	else{
		segtree[ind].cost+=segtree[ind].lazy*(r-l+1)*(r+l)/2;
		segtree[ind].num+=(r-l+1)*segtree[ind].lazy;
	}
	segtree[ind].lazy=0;
}
void update(long long int ind, long long int l, long long int r, long long int ql, long long int qr, long long int n){
	if(ql<=l && qr>=r){
		segtree[ind].lazy+=n;
		upn(ind, l, r);
		//cout<<ind<<" "<<l<<" "<<r<<" "<<segtree[ind].num<<'\n';
		return;
	}
	upn(ind, l, r);
	long long int m = (l+r)/2;
	if(ql<=m){
		update(ind*2, l, m, ql, qr, n);
	}
	if(qr>m){
		update(ind*2+1, m+1, r, ql, qr, n);
	}
	upn(ind, l, r);
	//cout<<ind<<" "<<l<<" "<<r<<" "<<segtree[ind].num<<'\n';
	return;
}
long long int queryn(long long int ind, long long int l, long long int r, long long int q){
	upn(ind, l, r);
	if(segtree[ind].cost<=q){
		long long int ans= segtree[ind].num;
		upl(ind);
		return ans;
	}
	if(l==r){
		long long int nb = floor(q/l);
		segtree[ind].num-=nb;
		segtree[ind].cost=segtree[ind].num*l;
		return nb;
	}
	else{
		long long int m = (l+r)/2;
		upn(ind*2, l, m);
		if(segtree[ind*2].cost<q){
			long long int ans = segtree[ind*2].num+queryn(ind*2+1, m+1, r, q-segtree[ind*2].cost);
			upl(ind*2);
			upn(ind, l, r);
			return ans;
		}
		else{
			long long int ans = queryn(ind*2, l, m, q);
			upn(ind, l, r);
			return ans;
		}
	}
}
long long int queryl(long long int ind, long long int l, long long int r, long long int n, bool lh){
	upn(ind, l, r);
	if(segtree[ind].num<=n){
		long long int ans = segtree[ind].cost;
		upl(ind);
		return ans;
	}
	if(l==r){segtree[ind].num-=n; segtree[ind].cost-=l*n; return l*n;}
	long long int ind1, ind2, l1, r1, l2, r2;
	if(lh){ind1=ind*2; ind2=ind*2+1; l1=l; r1=(l+r)/2; l2=r1+1; r2=r;}
	else{ind1=ind*2+1; ind2=ind*2; l2=l; r2=(l+r)/2; l1=r2+1; r1=r;}
	upn(ind1, l1, r1);
	if(segtree[ind1].num<n){
		long long int ans = segtree[ind1].cost+queryl(ind2, l2, r2, n-segtree[ind1].num, lh);
		upl(ind1);
		upn(ind, l, r);
		return ans;
	}
	else{
		long long int ans = queryl(ind1, l1, r1, n, lh);
		upn(ind, l, r);
		return ans;
	}
}
long long int queryc(long long int ind, long long int l, long long int r, long long int c){
	upn(ind, l, r);
	if(segtree[ind].num<c){return -1;}
	else if(l==r){return l;}
	long long int m = (l+r)/2;
	upn(ind*2, l, m);
	if(segtree[ind*2].num<c){
		return queryc(ind*2+1, m+1, r, c-segtree[ind*2].num);
	}
	else{
		return queryc(ind*2, l, m, c);
	}
}
int main() {
	long long int n;
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	string s;
	long long int a,b;
	long long int q;
	for(long long int i=0; i<n; i++){
		cin>>s;
		if(s=="ADD"){
			cin>>a>>b;
			update(1, 1, MAXP, b, b, a);
		}
		else if(s=="ADDRANGE"){
			cin>>a>>b;
			update(1, 1, MAXP, a, b, 1);
		}
		else if(s=="BUYAMT"){
			cin>>q;
			cout<<queryn(1, 1, MAXP, q)<<'\n';
		}
		else if(s=="BUYLOW"){
			cin>>a;
			cout<<queryl(1, 1, MAXP, a, 1)<<'\n';
		}
		else if(s=="BUYHIGH"){
			cin>>a;
			cout<<queryl(1, 1, MAXP, a, 0)<<'\n';
		}
		else if(s=="COST"){
			cin>>q;
			cout<<queryc(1, 1, MAXP, q)<<'\n';
		}
		else if(s=="NUMCONES"){
			upn(1, 1, MAXP);
			cout<<segtree[1].num<<'\n';
		}
		else if(s=="TOTALCOST"){
			upn(1,1,MAXP);
			cout<<segtree[1].cost<<'\n';
		}
		//cout<<s<<' '<<a<<' '<<b<<' '<<q<<'\n';
		//cout<<"num"<<segtree[1].num<<'\n';
	}
    return 0;
}