#include <bits/stdc++.h>
using namespace std;

vector<double> intrsct;
vector<long long int> val;
vector<pair<double, pair <bool, int> > > tp;
long long int spt[2005][15];
long long int pa[2005], pb[2005], pc[2005];
vector<pair<int, long long int> > qrs[2005];
long long int ans[800005];
double slope(double a, double b, double d){
	return (b-a)/d;
}
double intersect(double ba, double ma, double bb, double mb){
	return (bb-ba)/(ma-mb);
}

int main(){
	int x, k, n, q, st, ed, s, tpk;
	scanf("%i%i%i%i", &x, &k, &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%lli%lli%lli", &pa[i], &pb[i], &pc[i]);
	}
	int pieceof, sheet;
	for(int i=0; i<q; i++){
		scanf("%i%i", &pieceof, &sheet);
		qrs[pieceof].push_back({i, sheet});
	}
	for(int i=1; i<=n; i++){
		if (qrs[i].size()==0){continue;}
		tp.clear();
		intrsct.clear();
		val.clear();
		memset(spt, 0, sizeof(spt));
		tp.push_back({0, {0, 0}});
		double slp = slope(pa[i], pb[i], x);
		for(int j=1; j<=n; j++){
			if (i==j) continue;
			if (pa[j]>pa[i]){
				tp.push_back({-1, {0, j}});
				if (pb[j]<pb[i]){
					tp.push_back({intersect(pa[i], slp, pa[j], slope(pa[j], pb[j], x)), {1, j}});
				}
			}
			else if (pb[j]>pb[i]){
				tp.push_back({intersect(pa[i], slp, pa[j], slope(pa[j], pb[j], x)), {0,j}});
			}
		}
		sort(tp.begin(), tp.end());
		long long stp=0,  pv=-1;
		long long int csl = pb[i]-pa[i];
		for(pair<double, pair<bool, int> > j:tp){
			int cp = j.second.second;
			if (j.second.first && cp>=0){stp-=pc[cp];}
			else if (cp>=0){stp+=pc[cp];}
			if (j.first==-1){
				if (pv<0){
				    intrsct.push_back(0);
			            val.push_back(stp);
			        }
				else{val.back()=stp;}
			}
			else if (pv<0){
			    intrsct.push_back(j.first);
			    val.push_back(stp);
			}
			else if ((pa[pv]-pa[i])*(csl-(pb[cp]-pa[cp]))==(pa[cp]-pa[i])*(csl-(pb[pv]-pa[pv]))){
				val.back()=stp;
			}
			else{
			    intrsct.push_back(j.first);
			    val.push_back(stp);
			}
			pv = cp;
		}
		tpk = log2(val.size());
		for(int j=0; j<val.size(); j++){
			spt[j][0] =val[j];
		}
		for(int j=1; j<=tpk; j++){
			for(int l=0; l<val.size()-(1<<(j-1)); l++){
				spt[l][j] = max(spt[l][j-1], spt[l+(1<<(j-1))][j-1]);
			}
		}

		for(pair<int, int> tpp:qrs[i]){
			s = tpp.second;
			st = upper_bound(intrsct.begin(), intrsct.end(), s)-intrsct.begin()-1; 
			ed = lower_bound(intrsct.begin(), intrsct.end(), s+k)-intrsct.begin()-1;
			tpk = log2(1+ed-st);
			ans[tpp.first]=max(spt[st][tpk], spt[ed-(1<<tpk)+1][tpk]);
		}
	}
	for(int i=0; i<q; i++){
		printf("%lli\n", ans[i]);
	}
	return 0;
}