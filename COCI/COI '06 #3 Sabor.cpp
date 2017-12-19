#include <bits/stdc++.h>
#define OFFSET 1002
#define mp(a,b) make_pair(a,b)
using namespace std;
int ns[2005][2005];
pair<int, int> dir[4]={make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};
struct node{
	int x, y, stp;
	node(int _x, int _y, int _stp){
		x=_x; y=_y; stp=_stp;
	}
};
int mxx, mnx, mxy, mny, s;
inline bool nok(int x, int y, int stp){
	return ((ns[x][y]!=-1 && ns[x][y]<=stp) || (ns[x][y]==-2) || x>mxx+1 || x<mnx-1 || y<mny-1 || y>mxy+1 || stp>s);
}
int main() {
	memset(ns, -1, sizeof(ns));
	int b, x, y, tpi, tppi; mxx=OFFSET; mnx=OFFSET; mxy=OFFSET; mny=OFFSET; 
	scanf("%i%i", &b, &s);
	for(int i=0; i<b; i++){
		scanf("%i%i", &x, &y);
		mxx=max(x+OFFSET, mxx); mnx=min(x+OFFSET, mnx); mxy=max(mxy, y+OFFSET); mny=min(y+OFFSET, mny);
		ns[x+OFFSET][y+OFFSET]=-2;
	}
	queue<node> q;
	q.push(node(OFFSET, OFFSET, 0));
	while(!q.empty()){
		node tp = q.front(); q.pop();
		if (nok(tp.x, tp.y, tp.stp)) {continue;}
		ns[tp.x][tp.y]=tp.stp;
		for(pair<int, int> p: dir){
			if (nok(tp.x+p.first, tp.y+p.second, tp.stp+1)){ continue; }
			q.push(node(tp.x+p.first, tp.y+p.second, tp.stp+1));
		}
	}
	long long int cp=0, op=0;
	for(int i=mnx; i<=mxx; i++){
		for(int j=mny; j<=mxy; j++){
			if (ns[i][j]<0 || ns[i][j]>s) continue;
			if (ns[i][j]%2) op++;
			else cp++;
		}
	}
	mnx--; mny--; mxx++; mxy++;
	pair<int, int> crn[4] = {mp(mnx, mny), mp(mxx, mny), mp(mnx, mxy), mp(mxx, mxy)};

	pair<pair<int, int>, pair<int, int> > lne[4] = {mp(mp(mnx, mxx), mp(mxy-1, mxy+1)), mp(mp(mnx, mxx), mp(mny-1, mny+1)), mp(mp(mnx-1, mnx+1), mp(mny, mxy)), mp(mp(mxx-1, mxx+1), mp(mny, mxy))};
	for(pair<pair<int, int>, pair<int, int> > nd: lne){
		for(int i=nd.first.first+1; i<nd.first.second; i++){
			for(int j=nd.second.first+1; j<nd.second.second; j++){
				if (ns[i][j]<0 || ns[i][j]>s){
					continue;
				}
				y=s-ns[i][j];
				op+=y/2; cp+=y/2;
				if (ns[i][j]%2){
					op++; cp+=y%2;
				}
				else{
					cp++; op+=y%2;
				}
			}
		}
	}
	for(pair<int, int> p: crn){
		x=p.first; y=p.second; tpi=ns[x][y];
		if (tpi<0){ continue; }
		
		while(tpi<=s){
			
			op+=((s-tpi)/2)*2;
			cp+=((s-tpi)/2)*2;
			if (tpi%2){
				op++; cp+=((s-tpi)%2)*2;
			}
			else{
				cp++; op+=((s-tpi)%2)*2;
			}
			tpi+=2;
		}
	}
	
	printf("%lli %lli", cp, op);
	return 0;
}