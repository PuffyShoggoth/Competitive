#include <bits/stdc++.h>
using namespace std;

long long int bit[1000005];
int n;
stack<pair<int, long long int> > mns;
void update(int ind, long long int val){
	for(int i=ind; i<=1000000; i+=i&-i){
		bit[i]+=val;
	}
	return;
}
long long int sum(int ind){
	long long int tsm=0;
	for(int i=ind; i>0; i-=i&-i){
		tsm+=bit[i];
	}
	return tsm;
}
int main() {
	int q, x, y, p;
	pair<int, long long int> tp;
	scanf("%i%i", &n, &q);
	for(long long int i=1; i<=n; i++){
		scanf("%i", &p);
		while(!mns.empty() && mns.top().first>=p){
			tp=mns.top(); mns.pop();
			if (!mns.empty()){ update(tp.first, (tp.second-mns.top().second)*(i-tp.second)); }
			else{ update(tp.first, tp.second*(i-tp.second)); }
		}
		mns.push(make_pair(p, i));
	}
	int pv=n+1;
	while(!mns.empty()){
			tp=mns.top(); mns.pop();
			if (!mns.empty()){ update(tp.first, (tp.second-mns.top().second)*(pv-tp.second)); }
			else{ update(tp.first, tp.second*(pv-tp.second)); }
	}
	for(int i=0; i<q; i++){
		scanf("%i%i", &x, &y);
		printf("%lli\n", sum(y)-sum(x-1));
	}
	return 0;
}