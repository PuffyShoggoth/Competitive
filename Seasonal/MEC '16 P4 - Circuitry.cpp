#include <vector>
#include <utility>
#include <cstdio>
#include <map>
using namespace std;
int sets[509];
int rnk[509];
int q[125000];
bool cc[509][509];
vector<int> edges[509];
int dfsl[509], dfsu[509];
int cnt;
map<int, vector<pair<pair<int, int>, int> > >wires;
map<pair<int, int>, int> vld;
void fb(int cn, int par){
	cnt++; dfsu[cn]=cnt; dfsl[cn]=cnt;
	for(auto it=edges[cn].begin(); it!=edges[cn].end(); ++it){
		if (*it==par){continue;}
		if (!dfsu[*it]){
			fb(*it, cn);
		}
		if (dfsl[*it]>dfsu[cn]){
			cc[cn][*it]=1; cc[*it][cn]=1;
		}
		else{
			dfsl[cn]=dfsl[*it];
		}
	}
	return;
}
int root(int a){
	while (sets[a]!=0){a=sets[a];}
	return a;
}
void join(int a, int b){
	if (rnk[a]==rnk[b]){
		rnk[a]++; sets[b]=a;
	}
	else if (rnk[a]>rnk[b]){
		sets[b]=a;
	}
	else{
		sets[a]=b;
	}
	return;
}
int main(){
	int n, m, a, b, l, ti, ra, rb;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &l);
		wires[l].push_back(make_pair(make_pair(a,b), i));
	}
	for(auto wit=wires.begin(); wit!=wires.end(); ++wit){
		for(auto it=wit->second.begin(); it!=wit->second.end(); ++it){
			ra=root(it->first.first); rb=root(it->first.second);
			if (ra!=rb){
				if (vld.insert(make_pair(make_pair(min(ra, rb), max(ra, rb)), 1)).second){
					edges[ra].push_back(rb); edges[rb].push_back(ra);
				}
				else{
					vld[make_pair(min(ra, rb), max(ra, rb))]++;
				}
			}
		}
		for(auto it=wit->second.begin(); it!=wit->second.end(); ++it){
			ra=root(it->first.first); rb=root(it->first.second);
			if (ra!=rb){
				if (!dfsu[ra]){
					cnt=0; fb(ra, 0);
				}
				if (cc[ra][rb] && vld[make_pair(min(ra, rb), max(ra, rb))]==1){
					q[it->second]=2;
				}
				else{
					q[it->second]=1;
				}
			}
		}
		for(auto it=wit->second.begin(); it!=wit->second.end(); ++it){
			ra=root(it->first.first); rb=root(it->first.second);
			if (ra!=rb){
				edges[ra].clear(); edges[rb].clear(); dfsu[rb]=0; dfsu[ra]=0;
				join(ra, rb);
			}
		}
	}
	for(int i=0; i<m; i++){
		if (q[i]==0){printf("not useful\n");}
		else if(q[i]==1){printf("so so\n");}
		else{printf("useful\n");}
	}
	return 0;
}