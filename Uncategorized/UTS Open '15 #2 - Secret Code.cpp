#include <iostream>
#include <cstring>
using namespace std;
int edges[30][2];
int mp[30], mc[30], m[30];
bool dn[30];
inline int ti(char tpc){ return tpc-'a'+1; }
bool hung(int cn){
	if (dn[cn]) return 0;
	dn[cn]=1;
	for(int i=0; i<2; i++){
		if ((!mp[edges[cn][i]]) && (!m[edges[cn][i]] || hung(m[edges[cn][i]]))){ 
			m[edges[cn][i]]=cn; return 1;
		}
	}
	return 0;
}
int main() {
	int a, n, tpa, tpb;
	char ai, bi;
	string x, y;
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>a;
	for(int i=1; i<=a; i++){
		cin>>ai>>bi;
		edges[i][0] = ti(ai); edges[i][1] = ti(bi);
	}
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x>>y;
		bool valid = 1;
		memset(mc, 0, sizeof(mc)); memset(mp, 0, sizeof(mp)); 
		for(int j=0; j<x.length(); j++){
			tpa = ti(x[j]); tpb = ti(y[j]);
			if (edges[tpa][0]!=tpb && edges[tpa][1]!=tpb){ valid = 0; break; }
			else if (mc[tpa]==tpb){ continue; }
			else if (mc[tpa] || mp[tpb]){ valid=0; break; }
			else { mc[tpa]=tpb; mp[tpb]=tpa; }
		}
		if (valid){
			memset(m, 0, sizeof(m));
			for(int j=1; j<=a; j++){
				if (!mc[j]){ 
					memset(dn, 0, sizeof(dn));
					if (!hung(j)){valid = 0; break;}
				}
			}
		}
		if (valid){ cout<<"YES\n"; }
		else{ cout<<"NO\n"; }
	}
	return 0;
}