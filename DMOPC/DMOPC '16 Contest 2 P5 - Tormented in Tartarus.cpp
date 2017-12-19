#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;
pair<char, short int> inst[100005];
int spt[100005];
int n, m;
vector<int> nxt[100005];
bitset<5005> sis;

void instf(int ci, bool on, short int done){
	bool ss=0;
	if (inst[ci].first=='F'){
		if (on){
			if (sis[inst[ci].second]){
				sis[inst[ci].second]=0;
				done++; ss=1;
			}
		}
		else{
			if (!sis[inst[ci].second]){
				sis[inst[ci].second]=1;
				done++; ss=1;
			}
		}
	}
	else if (inst[ci].first=='D'){
		if (on){
			if (!sis[inst[ci].second]){
				sis[inst[ci].second]=1;
				done--; ss=1;
			}
		}
		else{
			if (sis[inst[ci].second]){
				sis[inst[ci].second]=0;
				done--; ss=1;
			}
		}
	}
	else if (inst[ci].first=='X'){
		if (on) {on=0;} else{on=1;} done=n-done; 
	}
	spt[ci]=done;
	for(int i=0; i<nxt[ci].size(); i++){
		instf(nxt[ci][i], on, done);
	}
	if (ss){
		if (inst[ci].first=='F'){
			sis[inst[ci].second]=on;
		}
		else if (inst[ci].first=='D'){
			sis[inst[ci].second]=!on;
		}
	}
	if (inst[ci].first=='X'){
		on = !on; done=n-done;
	}
	inst[ci].second=spt[ci];
	nxt[ci].clear();
	return;
}
int main() {
	int q, k; char tp;
	scanf("%i%i%i", &n, &m, &k);
	inst[0]=make_pair(-1, 0);
	for (int i=1; i<=m; i++){
		do{tp=getchar();} while(tp<'A' || tp>'Z');
		if (tp=='R') {scanf("%i", &q); inst[i]=make_pair(tp, q); nxt[q].push_back(i);}
		else{ 
			if (tp=='F') {scanf("%i", &q); inst[i]=make_pair(tp, q);}
			else if (tp=='D'){scanf("%i", &q); inst[i]=make_pair(tp, q);}
			else if (tp=='X') {inst[i]=make_pair(tp, -1);}
			nxt[i-1].push_back(i);
		}
	}
	instf(0, 0, 0);
	int tpi = floor(log2(k));
	spt[0]=0;
	for(int i=0; i<tpi; i++){
		for(int j=m; j>=(1<<i); j--){
			spt[j]=max(spt[j], spt[j-(1<<i)]);
		}
	}
	tpi= k-(1<<tpi);
	for(int i=1; i<=m; i++){
		printf("%i ", inst[i].second);
		if (i<tpi){
			printf("%i\n", spt[i]);
		}
		else{
			printf("%i\n", max(spt[i-tpi], spt[i]));
		}
		
	}
	return 0;
}