#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define min(a,b) ((a<b)?(a):(b))
using namespace std;
int dsj[100005];
int rnk[100005];
int nc[100005];
vector<pair<pair<int, int>, pair<int, int> > > edges;
int root(int a){
	while(dsj[a]){
		a=dsj[a];
	}
	return a;
}

void join(int a, int b){
	if (rnk[a]==rnk[b]){
		rnk[a]++;
		nc[a]+=nc[b];
		dsj[b]=a;
	}
	else if (rnk[a]<rnk[b]){
		nc[b]+=nc[a];
		dsj[a]=b;
	}
	else{
		nc[a]+=nc[b];
		dsj[b]=a;
	}
	return;
}
int main(){
	int n, m, d, a, b, c;
	scanf("%i %i %i", &n, &m, &d);
	for(int i=1; i<=n; i++){ nc[i]=1; dsj[i]=0; rnk[i]=1;}
	for(int i=0; i<n-1; i++){
		scanf("%i %i %i", &a, &b, &c);
		edges.push_back({{c, 0}, {a, b}});
	}
	for(int i=n-1; i<m; i++){
		scanf("%i %i %i", &a, &b, &c);
		edges.push_back({{c, 1}, {a, b}});
	}
	sort(edges.begin(), edges.end());
	int st=0, lv=0, dn=0;
	while(st<edges.size()){
		a=root(edges[st].second.first); b=root(edges[st].second.second);
		if (a==b){ st++; continue; }
		join(a, b);
		if (!edges[st].first.second){ lv++; }
		dn = st;
		st++;
	}
	int mcost = edges[dn].first.first;
	if (lv<n-1){
	memset(dsj, 0, sizeof(dsj));
	memset(rnk, 0, sizeof(rnk));
	st = 0;
	while(st<edges.size()){
		a=root(edges[st].second.first); b=root(edges[st].second.second);
		if (a==b){ st++; continue; }
		if(edges[st].first.first<mcost || (!edges[st].first.second && edges[st].first.first==mcost)){
		    join(a, b);
		}
		else if (!edges[st].first.second && edges[st].first.first<=d){ lv++; break; }
		dn = st;
		st++;
	}
	}
	printf("%i", (n-1-lv));

}