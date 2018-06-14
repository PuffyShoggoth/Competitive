#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dsj[100005], rnk[100005];
//finally de-salted enough to write this
int root(int a){
	while(dsj[a]){
		a=dsj[a];
	}
	return a;
}
void join(int a, int b){
	if(rnk[a]==rnk[b]){
		dsj[b]=a;
		rnk[a]++;
	}
	else if(rnk[a]>rnk[b]){
		dsj[b]=a;
	}
	else{
		dsj[a]=b;
	}
}
vector<pair<long long int, pair<int, int> > > edges;
vector<long long int> weights;
long long int pfx[100005];
int main() {
	int p, q;
	long long int n, m;
	scanf("%lli%lli%i%i", &n, &m, &p, &q);
	int a, b;
	long long int w;
	long long int ott=0;
	for(int i=0; i<p; i++){
		scanf("%i%i%lli", &a, &b, &w);
		edges.push_back({w, {a,b}});
		ott+=w*n;
	}
	sort(edges.begin(), edges.end());
	long long int tt = 0;
	for(int i=0; i<p; i++){
		a = root(edges[i].second.first);
		b = root(edges[i].second.second);
		if(a==b) continue;
		join(a,b);
		weights.push_back(edges[i].first);
		tt+=edges[i].first;
		pfx[weights.size()-1]=tt;
	}
	edges.clear();
	memset(dsj, 0, sizeof(dsj));
	memset(rnk, 0, sizeof(rnk));
	for(int i=0; i<q; i++){
		scanf("%i%i%lli", &a, &b, &w);
		edges.push_back({w, {a,b}});
		ott+=w*m;
	}
	sort(edges.begin(), edges.end());
	long long int ft=tt*n;
	for(int i=0; i<q; i++){
		a = root(edges[i].second.first);
		b = root(edges[i].second.second);
		if(a==b) continue;
		w=edges[i].first;
		if(w<=weights[0]){
			ft-=tt;
			ft+=w*m;
		}
		else if(w>=weights[m-2]){
			ft+=w;
		}
		else{
			ft+=w;
			int ind = upper_bound(weights.begin(), weights.end(), w)-weights.begin()-1;
			ft-=tt-pfx[ind];
			ft+=w*(m-2-ind);
		}
		join(a,b);
	}
	printf("%lli", ott-ft);
    return 0;
}