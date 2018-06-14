#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int nxt[200005][26];
int par[200005];
int len[200005];
int pv = 0;
int cind = 0;
void update(int c){
		int cn = ++cind, p = pv;
		len[cn]=len[p]+1;
		while(p && !nxt[p][c]){
			nxt[p][c] = cn; p=par[p];
		}
		if(nxt[p][c]==0){par[cn]=p; nxt[p][c]=cn;}
		else{
			int q = nxt[p][c];
			if(len[q]==len[p]+1){
				par[cn] = q;
			}
			else{
				int nq = ++cind;
				len[nq] = len[p]+1;
				par[nq] = par[q];
				memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
				par[q] = nq; par[cn] = nq;
				while(nxt[p][c]==q){ nxt[p][c]=nq; p = par[p];}
			}
		}
		pv = cn;
}

string a, b;

int res[100005];
int dp[100005];
int main() {
	cin>>a>>b;
	for(int i=0; i<a.size(); i++){
		update(a[i]-'a');
	}
	int crr = 0;
	bool pob = 1;
	int dst = 0;
	for(int i = 0; i<b.size(); i++){
		while(crr && !nxt[crr][b[i]-'a']){ crr = par[crr]; dst = len[crr]; }
		if(nxt[crr][b[i]-'a']){
			dst++;
			res[i-dst+1]=dst;
			crr = nxt[crr][b[i]-'a'];
			
		}
		else{ pob = 0; break; }
	}
	if(!pob){printf("-1"); return 0;}
	for(int i = 1; i<b.size(); i++){
		res[i] = max(res[i], res[i-1]-1);
	}
	int tt =0, sind = 0;
	int gl = b.size();
	while(sind<gl){
		if(res[sind]){ tt++; sind+=res[sind]; }
		else{pob = 1; break;}
	}
	if(!pob){printf("-1");}
	else{printf("%i", tt);}
    return 0;
}