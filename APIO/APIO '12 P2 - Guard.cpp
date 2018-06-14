#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<pair<int, int> > empty;
vector<pair<int, int> > ninjas;
vector<int> st, ed;
int stempt[100005], edempt[100005];
int pfx[100005];
bool ans[100005];
bool hf[100005], hb[100005];
int slv(){
	if(!ed.size()){return 0;}
	/*for(int i=0; i<st.size(); i++){
		printf("%i %i\n", st[i], ed[i]);
	}*/
	if(ed.size()==1 && pfx[ed.back()-1]-pfx[st.back()-1]==1){
		ans[st.back()]=1;
		//printf("%i\n", 1);
		return 1;
	}
	else{
		int tsm=0;
		int ind = 0;
		while(ind < st.size()){
			tsm++;
			
			int nind;
			if(ed[ind]>st.back()){nind = st.size()-1;}
			else{ nind = lower_bound(st.begin(), st.end(), ed[ind])-st.begin()-1;}
			if(pfx[ed[ind]-1]-pfx[st[nind]-1] == 1){
				hf[ed[ind]]=1; hf[st[nind]]=1;
				//printf("hf%i %i\n", ed[ind], st[nind]);
			}
			if(ed[ind]>st.back()){break;}
			ind = nind+1;
		}
		ind = ed.size()-1;
		while(ind >=0){
			int nind = upper_bound(ed.begin(), ed.end(), st[ind])-ed.begin();
			if(pfx[ed[nind]-1]-pfx[st[ind]-1] == 1){
				hb[ed[nind]]=1; hb[st[ind]]=1;
				//printf("hb%i %i\n", ed[nind], st[ind]);
			}
			if(st[ind]<ed[0]){break;}
			ind = nind-1;
		}
		//printf("%i\n", tsm);
		return tsm;
	}
}
int main() {
	int n, k, m;
	scanf("%i%i%i", &n, &k, &m);
	int a, b, c;
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &c);
		if(c){
			ninjas.push_back({a, b+1});
		}
		else{
			empty.push_back({a, b+1});
		}
	}
	int ttempty=0;
	if(empty.size()){
		sort(empty.begin(), empty.end());
		int cst = empty[0].first, ced = empty[0].second;
		for(int i=1; i<empty.size(); i++){
			if(empty[i].first>ced){
				for(int j=cst; j<ced; j++){
					stempt[j]=cst; edempt[j]=ced;
				}
				stempt[ced]=cst;
				cst = empty[i].first; ced=empty[i].second;
			}
			else if(empty[i].second>ced){
				ced = empty[i].second;
			}
		}
		for(int j=cst; j<ced; j++){
			stempt[j]=cst; edempt[j]=ced;
		}
		stempt[ced]=cst;
		
	}
	for(int i=1; i<=n; i++){
		pfx[i] = pfx[i-1]+(edempt[i]?0:1);
	}
	if(pfx[n]==k){
		for(int i=1; i<=n; i++){
			if(!edempt[i]){printf("%i\n", i);}
		}
		return 0;
	}

	for(int i=0; i<ninjas.size(); i++){
		if(edempt[ninjas[i].first]){
			ninjas[i].first = edempt[ninjas[i].first];
		}
		if(stempt[ninjas[i].second]){
			ninjas[i].second = stempt[ninjas[i].second];
		}
	}
	sort(ninjas.begin(), ninjas.end());
	int mtt = 0;
	for(int i=0; i<ninjas.size(); i++){
		//printf("%i %i\n", ninjas[i].first, ninjas[i].second);
		if(ninjas[i].first>=ninjas[i].second){continue;}
		//printf("%i %i\n", ninjas[i].first, ninjas[i].second);
		if(!st.size()){
			st.push_back(ninjas[i].first);
			ed.push_back(ninjas[i].second);
		}
		else{
			while(ed.size() && ninjas[i].second<=ed.back()){
				ed.pop_back(); st.pop_back();
			}
			if(ed.size() && ninjas[i].first>=ed.back()){
				mtt+=slv();
				ed.clear(); st.clear();
			}
			if(!ed.size() || (ed.size() && !(ninjas[i].first==st.back() && ninjas[i].second>=ed.back()))){
				ed.push_back(ninjas[i].second); st.push_back(ninjas[i].first);
			}
		}
	}

	if(ed.size()){mtt+=slv();}
	bool dn = 0;
	if(mtt<k){
		for(int i=1; i<=n; i++){
			if(ans[i]){dn=1; printf("%i\n", i);}
		}
	}
	else{
		bool fv=0, bv=0;
		for(int i=1; i<=n; i++){
			fv^=hf[i]; bv^=hb[i];
			if(ans[i] || (fv&&bv&&(edempt[i]==0))){
				dn=1; printf("%i\n", i);
			}
		}

	}
	if(!dn){printf("-1\n");}
    return 0;
}