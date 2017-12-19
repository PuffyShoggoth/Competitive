#include<bits/stdc++.h>
using namespace std;
int chc[100005][2];
int chid[100005], chpos[100005], posch[100005], chpr[100005], dpth[100005], sz[100005], nl[100005], chhead[100005];
multiset<int> chval[100005];
set<int> blc[100005];
int segtree[400005];
long long int dist[100005], del[100005];
vector<pair<int, int> > ch[100005];
int build(int cn, long long int tdst, int npar){
	dist[cn]=tdst;
	dpth[cn]=npar;
	sz[cn]=1;
	chval[cn].insert(dpth[cn]);
	for(pair<int, int> tp: ch[cn]){
		sz[cn]+=build(tp.first, tdst+tp.second, npar+1);
	}
	return sz[cn];
}
int chcn =0, chcind=0;
int chdist[100005];
int hldbuild(int cn){
	chid[cn]=chcn;
	chpos[cn]=chcind;
	posch[chcind]=cn;
	chdist[chcind]=dist[cn];
	bool hch = 0;
	int tpres=0;
	for(pair<int, int> tp: ch[cn]){
		if(sz[tp.first]>sz[cn]/2){
			chcind++;
			tpres = hldbuild(tp.first);
			hch=1;
			break;
		}
	}
	if(!hch){chc[chcn][1]=chcind; }
	for(pair<int, int> tp:ch[cn]){
		if(sz[tp.first]>sz[cn]/2){ continue; }
		chcn++; chcind++;
		chc[chcn][0]=chcind; 
		chpr[chcn]=cn;
		chhead[chcn]=tp.first;
		chval[cn].insert(hldbuild(tp.first));
	}
	/*for(auto it=chval[cn].begin(); it!=chval[cn].end(); ++it){
		printf("%i ", *it);
	}
	printf("%ihld\n", cn);*/
	return max(*chval[cn].rbegin(), tpres);
}
int query(int ind, int st, int ed, int l, int r){
	//printf("sgtree ind%i vl%i st%i ed%i l%i r%i\n", ind, segtree[ind], st, ed, l, r);
	if(l>ed || r<st){ return 0; }
	else if(l<=st && r>=ed){ return segtree[ind]; }
	else{
		return max(query(ind<<1, st, (st+ed)>>1, l, r), query((ind<<1)+1, ((st+ed)>>1)+1, ed, l, r));
	}
}
void upval(int ind, int val){
	segtree[ind] = val;
	while(ind>>1 > 0){
		ind = ind>>1;
		segtree[ind] = max(segtree[ind<<1], segtree[(ind<<1)+1]);
	}
}
int gval(int id){
	//printf("%i", id);
	if (blc[id].empty()){
		//printf("empt\n");
		return query(1, 0, chcind, chc[id][0], chc[id][1]);
	}
	else if(*blc[id].begin() == chc[id][0]){ /*printf("nr%i\n", chc[id][0]);*/ return 0; }
	else{ /*printf("hvl%i\n", *blc[id].begin()); */return query(1, 0, chcind, chc[id][0], *blc[id].begin()-1); }
}
int possg[100005];
void upadd(int cn, int vl, int pv){
	//if(chid[cn]==0){ return; }
	//printf("%i %i %i\n", cn, vl, pv);
	if (vl==pv){ return; }
	if(pv>0) { chval[cn].erase(chval[cn].find(pv)); }
	if(vl>0) { chval[cn].insert(vl); }
	int npv = gval(chid[cn]);
	upval(possg[chpos[cn]], *chval[cn].rbegin());
	//for(auto it=chval[cn].begin(); it!=chval[cn].end(); ++it){printf("%i ", *it);}
	//	printf("dn\n");
	if(chid[cn]>0){ upadd(chpr[chid[cn]], gval(chid[cn]), npv); }
}
int pvp[100005], chost[100005];
void sgbuild(int ind, int l, int r){
	if(l==r){
		segtree[ind]= *chval[posch[l]].rbegin(); 
		possg[l]=ind;
	}
	else{
		sgbuild(ind<<1, l, (l+r)>>1);
		sgbuild((ind<<1)+1, ((l+r)>>1)+1, r);
		segtree[ind] = max(segtree[ind<<1], segtree[(ind<<1)+1]);
	}
}
int fhit(int cn, int nval){
	if (nval==0){ return 0; }
	int pv = cn;
	while(dist[chhead[chid[cn]]]>=nval){
		pv = chhead[chid[cn]]; cn = chpr[chid[cn]];
	}
	if(dist[cn]<nval){ return pv; }
	else{
		return posch[lower_bound(chdist+chc[chid[cn]][0], chdist+chc[chid[cn]][1]+1, nval)-chdist];
	}
}
int main() {
	int n;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%lli", &del[i]);
	}
	int p, td;
	for(int i=1; i<=n; i++){
		scanf("%i%i", &p, &td);
		ch[p].push_back({i, td});
	}
	build(0, 0, 0);
	hldbuild(0);
	sgbuild(1, 0, n);
	for(int i=1; i<=n; i++){
		if (del[i] > dist[i]) {pvp[i] = -1; continue; }
		else{td = fhit(i, del[i]); }
		if (chost[td] == 0){ 
			
			if(chid[td]!=0){
				int nvl = gval(chid[td]);
				blc[chid[td]].insert(chpos[td]);
				upadd(chpr[chid[td]], gval(chid[td]), nvl);
			}
			else{
				blc[chid[td]].insert(chpos[td]);
			}
		}
		pvp[i] = td; 
		chost[td]++;
	}
	//printf("st\n");
	int c, cn, tp;
	scanf("%i", &c);
	for(int i=0; i<c; i++){
		scanf("%i%i", &cn, &td);
		if(td > dist[cn]){ tp = -1; }
		else{ tp = fhit(cn, td); }
		//printf("tp%i pvp%i\n", tp, pvp[cn]);
		if (tp!=pvp[cn]) {
			if(pvp[cn]!=-1){
				chost[pvp[cn]]--;
				if(!chost[pvp[cn]]){
					//printf("pvvvp\n");
					
					if(chid[pvp[cn]]!=0){
						int nvl = gval(chid[pvp[cn]]);
						blc[chid[pvp[cn]]].erase(chpos[pvp[cn]]);
						upadd(chpr[chid[pvp[cn]]], gval(chid[pvp[cn]]), nvl);
					}
					else{
						blc[chid[pvp[cn]]].erase(chpos[pvp[cn]]);
					}
				}
			}
			if(tp!=-1){
				if(chost[tp] == 0){ 
					//printf("ttttttttp\n");
					
					if (chid[tp]!=0){
						int nvl = gval(chid[tp]);
						blc[chid[tp]].insert(chpos[tp]);
						upadd(chpr[chid[tp]], gval(chid[tp]), nvl); 
					}
					else{
						blc[chid[tp]].insert(chpos[tp]);
					}
				}
				chost[tp]++;
			}
			pvp[cn]=tp;
		}
		//printf("\n", )
		printf("%i\n", gval(0));
	}
}