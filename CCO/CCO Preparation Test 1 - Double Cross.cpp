#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
const int INF = 0x3f3f3f3f;
map<int, int> rs[10005];
map<int, int> cs[10005];
void remove(int trnum, map<int, int> & tmap){
	auto it = tmap.lower_bound(trnum);
	if(it==tmap.end() || it->second>trnum){
		return;
	}
	else if(it->first == trnum){
		int tp = it->second;
		if (tp==trnum){
			tmap.erase(it);
		}
		else{
			tmap.erase(it);
			tmap[trnum-1] = tp;
		}
	}
	else if(it->second==trnum){
		it->second = trnum+1;
	}
	else{
		tmap[trnum-1]=it->second;
		it->second = trnum+1;
	}
}
int r, c;
//need number of greater + sum of less + distances of greater

vector<long long int> bits[10005], bitd[10005], bitst[10005], bitdt[10005];
void bitupd(int ind, long long int num, vector<long long int> & bit, vector<long long int> & bitt){
	for(int i=ind; i<=c/2; i+=i&-i){
		bit[i]=(bit[i]+num)%MOD;
		bitt[i] = (bitt[i]+num*(i-ind))%MOD;
	}
}
void update(long long int ind, long long int val, long long int v){
	long long int ns = ((ind-1)*v)%MOD; 
	for(int i=ind; i<=r; i+=i&-i){
		bitupd(val, ns, bitd[i], bitdt[i]);
		bitupd(val, v, bits[i], bitst[i]);
	}
}
long long int sum(int inda, int indb, vector<long long int> bit[10005], vector<long long int> bitt[10005]){
	long long int tpsum = 0;
	for(int i=inda; i>0; i-=i&-i){
		for(int j=indb; j>0; j-=j&-j){
			tpsum = (tpsum+bitt[i][j]+(indb-j)*bit[i][j])%MOD;
		}
		
	}
	return tpsum;
}
int cml[10005];
int main() {
	int n;
	scanf("%i%i", &r, &c);
	for(int i=1; i<=r; i++){
		rs[i][c]=1;
		bits[i] = vector<long long int> (c/2+1, 0);
		bitd[i] =vector<long long int> (c/2+1, 0);
		bitst[i] = vector<long long int> (c/2+1, 0);
		bitdt[i] = vector<long long int> (c/2+1, 0);
	}
	for(int i=1; i<=c; i++){
		cs[i][r]=1;
	}
	scanf("%i", &n);
	int tr, tc;
	for(int i=0; i<n; i++){
		scanf("%i%i", &tr, &tc);
		remove(tc, rs[tr]);
		remove(tr, cs[tc]);
	}
	long long int tt = 0;
	for(int i=1; i<=c; i++){
		for(int j=1; j<=r; j++){
			int csz;
			auto ita = rs[j].upper_bound(i);
			if(ita==rs[j].end() || ita->second >= i){ csz = 0;}
			else{ csz = min(i-ita->second, ita->first-i); }
			if(cml[j]<csz){
				cml[j]=csz;
				update(j, csz, 1);
			}
			else if(cml[j]>csz){
				update(j, cml[j], -1);
				cml[j]=csz;
			}
		}
		for(auto it=cs[i].begin(); it!=cs[i].end(); ++it){
			//printf("%i %i %i\n", i, it->second, it->first);
			for(int j=it->second+2; j<it->first; j++){
				int csz = cml[j];
				long long int ng = sum(j-2, csz, bits, bitst)-sum(it->second, csz, bits, bitst);
				long long int td = sum(j-2, csz, bitd, bitdt)-sum(it->second, csz, bitd, bitdt);
				//printf("%lli %lli\n", ng, td);
				tt = (tt+(td-ng*(it->second-1)%MOD)*(it->first-j)%MOD)%MOD;
				

			}
			//printf("%lli\n", tt);

		}
	}
	printf("%lli", (tt+MOD)%MOD);

    return 0;
}