#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
int diff[2505][2505];
int psa[2505][2505];
int bit[100005];
int m, k;
map<int, bool> dn[2505];
void update(int ind, int vl){
	for(int i=ind+1; i<=m+1; i+=i&-i){
		bit[i]+=vl;
	}
	return;
}
int sum(int ind){
	if (ind>m){ ind = m; }
	int tt=0;
	for(int i=ind+1; i>0; i-=i&-i){
		tt+=bit[i];
	}
	return tt;
}
void updrange(int st, int ed, int i){
	
	for(int j=max(st, k); j<ed; j++){
		if (diff[i][j]==-1) continue;
		update(diff[i][j], -1);
		diff[i][j]=-1;
	}
}
int main(){
	int n, s, x, y;
	scanf("%i%i", &n, &k);
	scanf("%i", &m);
	for(int donotfckingreuse=0; donotfckingreuse<m; donotfckingreuse++){
		scanf("%i", &s);
		vector<pair<pair<int, int>, pair<int, int> > >vp[4][4];
		for(int q=0; q<s; q++){
			scanf("%i%i", &x, &y);
			pair<pair<int, int> , pair<int, int> > rp = {{x,y},{min(n+1,x+k),min(n+1,y+k)}};
			vp[q][0].push_back(rp);
			for(int j=0; j<q; j++){
				for(int k=1; k<s; k++){
					for(pair<pair<int, int>, pair<int, int> > tpp: vp[j][k-1]){
						if(tpp.f.f<rp.s.f && tpp.f.f>=rp.f.f){
							if(tpp.f.s<rp.s.s && tpp.f.s>=rp.f.s){
								vp[q][k].push_back({{tpp.f.f, tpp.f.s}, {min(tpp.s.f, rp.s.f), min(tpp.s.s, rp.s.s)}});
							}
							else if(rp.f.s<tpp.s.s && rp.f.s>=tpp.f.s){
								vp[q][k].push_back({{tpp.f.f, rp.f.s}, {min(tpp.s.f, rp.s.f), min(tpp.s.s, rp.s.s)}});
							}
						}
						else if(rp.f.f<tpp.s.f && rp.f.f>=tpp.f.f){
							if(tpp.f.s<rp.s.s && tpp.f.s>=rp.f.s){
								vp[q][k].push_back({{rp.f.f, tpp.f.s}, {min(tpp.s.f, rp.s.f), min(tpp.s.s, rp.s.s)}});
							}
							else if(rp.f.s<tpp.s.s && rp.f.s>=tpp.f.s){
								vp[q][k].push_back({{rp.f.f, rp.f.s}, {min(tpp.s.f, rp.s.f), min(tpp.s.s, rp.s.s)}});
							}
						}
					}
				}
			}
			for(int k=0; k<s; k++){
				int vl = (k%2)?-1:1;
				for(pair<pair<int, int>, pair<int, int> > tpp: vp[q][k]){
					diff[tpp.f.f][tpp.f.s] +=vl;
					diff[tpp.f.f][tpp.s.s] -=vl;
					diff[tpp.s.f][tpp.f.s] -=vl;
					diff[tpp.s.f][tpp.s.s] +=vl;
				}
			}
		}
		
	}

	double tgk=(n-k+1)*(n-k+1);
	for(int i=1; i<=n; i++){
		int curr = 0;
		for(int j=1; j<=n; j++){
			curr+=diff[i][j];
			diff[i][j]=curr+diff[i-1][j];
			if(i>=k && j>=k){
				update(diff[i][j], 1);
			}
		}
	}
	/*for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			printf("%i ", diff[i][j]);
		}
		printf("\n");
	}*/
	int t;
	scanf("%i", &t);
	while(t--){
		scanf("%i", &x);
		if (x==1){
			scanf("%i%i", &x, &y);
			int yk = min(n+1, y+k);
			for(int i=max(x, k); i<min(n+1,x+k); i++){
				auto ita = dn[i].lower_bound(y), itb = dn[i].lower_bound(yk);
				auto itc=ita, itd=itb;
				if(ita==dn[i].end()){
					dn[i].insert({y, 1});
					dn[i].insert({yk, 0});
					updrange(y, yk, i);
				}
				else if(ita==itb){
					if(!itb->second) continue;
					else{
						if(itb->first == yk){
							dn[i].erase(itb);
							dn[i].insert({y, 1});
							updrange(y, yk, i);
						}
						else{
							dn[i].insert({y, 1});
							dn[i].insert({yk, 0});
							updrange(y, yk, i);
						}
					}
				}
				else if(ita->second){
					if(ita->first == y) continue;
					updrange(y, ita->first, i);
					dn[i].erase(ita);
					dn[i].insert({y, 1});

				}
				else{
					if(itb == dn[i].end()){
						updrange(ita->first, yk, i);
						dn[i].erase(ita);
						dn[i].insert({yk, 0});
					}
					else if(itb->second==0){
						itd--;
						updrange(ita->first, itd->first, i);
						dn[i].erase(itd);
						dn[i].erase(ita);
					}
					else{
						updrange(ita->first, yk, i);
						if (itb->first==yk){ dn[i].erase(itb); }
						else{ dn[i].insert({yk, 0}); }

						dn[i].erase(ita);
					}
				}

			}
		}
		else{
			scanf("%i", &y);
			printf("%.6f\n", (sum(m)-sum(y-1))/tgk);
		}
	}
}