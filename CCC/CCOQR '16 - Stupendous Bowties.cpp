#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <algorithm>
#define mp(x, y) make_pair(x, y)
#define ll long long int
using namespace std;
vector<pair<ll, ll> >y;
vector<pair<ll, ll> >x;
pair<ll, ll> xoa;
pair<ll, ll> yoa;
int bsy(ll rq, int s, vector<pair<ll, ll> >& v){
	int e=v.size()-1, m;
	while (s<=e){
		m=(s+e)/2;
		if (v[m].first>rq){
			e=m-1;
		}
		else{s=m+1;}
	}
	return e;
}
int ssy(ll rq, int e, vector<pair<ll, ll> >& v){
	int s=0, m;
	while (s<=e){
		m=((s+e)/2+(s+e)%2);
		if (v[m].first<rq){
			s=m+1;
		}
		else{e=m-1;}
	}
	return s;
}
int fi(ll rq, int s, int e){
	int m; 
	while (s<=e){
		m=((s+e)/2+(s+e)%2);
		if (y[m].second<rq){
			s=m+1;
		}
		else{e=m-1;}
	}
	return s;
}
void fyoa(ll ty, ll tx){
	ll e=bsy(ty, 0, y), s, ci;
	s=ssy(ty, e, y);
	ci=fi(tx, s, e);
	yoa=mp(ci-s, e-ci);
	return;
}
void fxoa(ll tx, int i, ll ty){
	ll e=bsy(tx, i, x), s;
	s=ssy(tx, i, x);
	xoa= mp(i-s, e-i);
}

int main() {
	int n, cx, cy;
	pair<ll, ll> tx;
	pair<ll, ll> ty;
	ll sb=0;
	cin>>n;
	for(int i=0; i<n; i++){
		scanf("%i%i", &cx, &cy);
		x.push_back(mp(cx, cy));
		y.push_back(mp(cy, cx));
	}
	sort(y.begin(), y.end());
	sort(x.begin(), x.end());
	for(int i=0; i<x.size(); i++){
		fxoa(x[i].first, i, x[i].second);
		fyoa(x[i].second, x[i].first);
		sb+=(xoa.first*yoa.first)*(xoa.second*yoa.second);
		sb+=(xoa.second*yoa.first)*(xoa.first*yoa.second);
	}
	cout<<sb;
	return 0;
}