#include <bits/stdc++.h>
using namespace std;
int rnk[150005], dsj[150005];
vector<int> edges[150005];
int root(int cn){
	while(dsj[cn]!=cn){ cn = dsj[cn]; }
	return cn;
}
void join(int a, int b){
	if(rnk[a]==rnk[b]){dsj[b]=a; rnk[a]++; }
	else if (rnk[a]>rnk[b]){dsj[b]=a;}
	else{ dsj[a]=b; }
}
int par[150005], edind[150005], dind[150005], numchld[150005];
int cntr=1, ind[150005];
int treeid[150005], ans[150005];
int q;
set<int> qrs[150005];
vector<pair<pair<int, int>, int> > unused;
int build(int cn, int tpar, int tlvl, int ctid){
	par[cn]=tpar; 
	//printf("%i %i %i\n", cn, tpar, ctid);
	numchld[cn]=1; treeid[cn]=ctid; ind[cn]=cntr; cntr++;
	for(int i: edges[cn]){
		if (i!=tpar){ numchld[cn]+=build(i, cn, tlvl+1, ctid);}
	}
	edind[cn]=cntr-1;
	return numchld[cn];
}
vector<int > cr;
int slv(int cn, int dst){
	int tpr = root(cn); cn = dind[tpr];
	if(ind[cn] <= dst && edind[cn] >= dst){ return tpr;}
	else{
		cr.push_back(tpr);
		return slv(par[cn], dst);
	}
}
int main(){
	int n, d;
	scanf("%i%i%i", &n, &d, &q);
	int a, b, ta, tb;
	for(int i=0; i<n; i++){dsj[i]=i;}
	for(int i=0; i<d; i++){
		scanf("%i%i", &a, &b);
		if (a==b) continue;
		ta = root(a); tb = root(b);
		if (ta==tb){ unused.push_back({{a, b}, i}); }
		else{ edges[a].push_back(b); edges[b].push_back(a); join(ta, tb);} 
	}
	for(int i=0; i<n; i++){dsj[i]=i; dind[i]=i;}
	int ctid=1;
	for(int i=0; i<n; i++){
		if(treeid[i]) continue;
		build(i, -1, 0, ctid);
		ctid++;
	}
	memset(ans, -1, sizeof(ans));
	for(int i=0; i<q; i++){
		scanf("%i%i", &a, &b);
		if(treeid[a]!=treeid[b]) continue;
		else if (a==b){
			ans[i]=0; continue;
		}
		if(!treeid[a]){ continue; }
		qrs[a].insert(i);
		qrs[b].insert(i);
	}
	for(auto tpp:unused){
		a = tpp.first.first; b = tpp.first.second;
		if(treeid[a]!=treeid[b] || treeid[a]==0) continue;
		cr.clear();
		slv(b, ind[a]);
		a=slv(a, ind[b]);
		b = dind[a];
		for(int i: cr){
			ta = dind[i];
			if(qrs[ta].size()>qrs[b].size()){
				qrs[ta].swap(qrs[b]);
			}
			for(auto it=qrs[ta].begin(); it!=qrs[ta].end(); ++it){
				auto ita = qrs[b].find(*it);
				if(ita!=qrs[b].end()){
					ans[*it]=tpp.second;
					qrs[b].erase(ita);
				}
				else{
					qrs[b].insert(*it);
				}
			}
			if(rnk[i]<rnk[a]){
				dsj[i]=a;
			}
			else if (rnk[i]==rnk[a]){
				dsj[i]=a; rnk[a]++;
			}
			else{
				dsj[a]=i; a = i; dind[a] = b;
			}
		}
	}
	for(int i=0; i<q; i++){
		printf("%i\n", ans[i]);
	}
	return 0;
}