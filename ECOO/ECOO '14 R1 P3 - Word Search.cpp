#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
string cls[40];
bool dn[40][40];
int r, c;
string cs;
bool vld(int tr, int tc, int ind){
	return(tr>=0 && tr<r && tc>=0 && tc<c && cls[tr][tc]==cs[ind]);
}
bool svl(int ind, int tr, int tc, int dr, int dc){
	if(ind==cs.size()){return 1;}
	if(cs[ind]<'A' || cs[ind]>'Z'){return svl(ind+1, tr, tc, dr, dc);}
	if(!vld(tr, tc, ind)){return 0;}
	if(svl(ind+1, tr+dr, tc+dc, dr, dc)){
		dn[tr][tc]=1;
		return 1;
	}
	else{
		return 0;
	}
}
pair<int, int> dirs[] = {{-1, 0}, {-1, -1}, {-1,1}, {0, -1}, {0,1}, {1, -1}, {1, 0}, {1, 1}};
int main() {
	for(int dnr=0; dnr<5; dnr++){
		memset(dn, 0, sizeof(dn));
		cin>>r>>c;
		for(int i=0; i<r; i++){
			cin>>cls[i];
		}
		int m;
		cin>>m;
		char tpc;
		do{tpc=getchar();}while(tpc!='\n');
		for(int i=0; i<m; i++){
			getline(cin, cs);
			bool cdn=0;
			for(int j=0; j<r; j++){
				for(int k=0; k<c; k++){
					for(pair<int, int> tpp:dirs){
						if(svl(0, j, k, tpp.first, tpp.second)){
							cdn=1;
							break;
						}
					}
					if(cdn){break;}
				}
				if(cdn){break;}
			}
			//cout<<i<<' '<<cs<<'\n';
		}
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(!dn[i][j]){
					cout<<cls[i][j];
				}
			}
		}
		cout<<'\n';
	}
	
    return 0;
}