#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
int spa[100009];
int spw[100009];
bool dna[100009]; 
bool dnb[100009];
vector<pair<int, int> > adjl[100009];
vector<pair<int, int> > :: iterator it;

void dijkstra(int (&ar)[100009], bool (&dn)[100009], int s){
	priority_queue <pair<int, int> > pq;
	pair <int, int> tp;
	pq.push(make_pair(0, s));
	while(pq.size()){
		tp=pq.top(); pq.pop();
		if (dn[tp.second]){continue;}
		dn[tp.second]=1;
		ar[tp.second]=-tp.first;
		for(it=adjl[tp.second].begin(); it!=adjl[tp.second].end(); ++it){
			if (!dn[it->second]){pq.push(make_pair(it->first+tp.first, it->second));}
		}
		
	}
	return;
}
int main() {
	int n, m, a, b, t, mx=0;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &t);
		adjl[a].push_back(make_pair(-t, b));
		adjl[b].push_back(make_pair(-t, a));
	}
	dijkstra(spa, dna, 0);
	dijkstra(spw, dnb, n-1);
	for(int i=0; i<n; i++){
		mx=(mx<spa[i]+spw[i])?(spa[i]+spw[i]):mx;
	}
	printf("%i", mx);
	return 0;
}