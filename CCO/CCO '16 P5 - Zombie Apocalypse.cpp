#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <utility>
using namespace std;
int m, n, k, q;
map<int, vector<pair<int, bool> > >  zomb;
map<int, vector<pair<int, bool> > >  smzb;
multiset<pair<int, bool> > curr;
int inline wbc(int a){
	if (a<1) return 1;
	return (a>(m+1))?(m+1):a;
}
int inline wbr(int a){
	if (a<1) return 1;
	return (a>(n+1))?(n+1):a;
}
long long int sm(){
	long long int on=0, ar=0, pvr;
	for(auto itc=curr.begin(); itc!=curr.end(); ++itc){
		if (itc->second){
			if (!on) pvr=itc->first;
			on++;
		}
		else{
			if (on==1) ar+=(itc->first-pvr);
			on--;
		}
	}
	return ar;
}
void updt(vector<pair<int, bool> > vals, int d){
	for(auto itb=vals.begin(); itb!=vals.end(); ++itb){
		if (itb->second){
			curr.insert(make_pair(wbr(itb->first-d), 1));
			curr.insert(make_pair(wbr(itb->first+d+1), 0));
		}
		else{
			curr.erase(curr.find(make_pair(wbr(itb->first-d), 1)));
			curr.erase(curr.find(make_pair(wbr(itb->first+d+1), 0)));
		}
	}
	return;
}
vector<int> tmpc;
vector<int> tmpr;
int main() {
	int r, c, nz;
	long long int ar=0, pv=1, sml=0, sms=0;
	scanf("%i%i%i", &n, &m, &nz);
	for(int i=0; i<nz; i++){
		scanf("%i%i", &r, &c);
		tmpc.push_back(c);
		tmpr.push_back(r);
	}
	scanf("%i", &k);
	if (k==0){printf("%i", nz);}
	else{
	for(int i=0; i<nz; i++){
		zomb[wbc(tmpc[i]-k)].push_back(make_pair(tmpr[i], 1));
		smzb[wbc(tmpc[i]-k+1)].push_back(make_pair(tmpr[i], 1));
		zomb[wbc(tmpc[i]+k+1)].push_back(make_pair(tmpr[i], 0));
		smzb[wbc(tmpc[i]+k)].push_back(make_pair(tmpr[i], 0));
	}
	pv=zomb.begin()->first;
	for(auto it=zomb.begin(); it!=zomb.end(); ++it){
		sml+= (it->first-pv)*ar;
		ar=0; pv=it->first;
		updt(it->second, k);
		ar=sm();
	}
	ar=0;
	for(auto it=smzb.begin(); it!=smzb.end(); ++it){
		sms+= (it->first-pv)*ar;
		ar=0; pv=it->first;
		updt(it->second, k-1);
		ar=sm();
	}
	printf("%lli", sml-sms);
	}
	return 0;
}