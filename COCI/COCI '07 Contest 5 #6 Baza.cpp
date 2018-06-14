#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > srtd;
unordered_map<long long int,int> MLE_REEE;
vector<pair<string, int> > wrds;
vector<string> qrs;
int bit[30005];
int ans[30005];
int sind[30005];
int n;
void update(int ind){
	for(int i=ind+1; i<=n; i+=(i&-i)){
		bit[i]++;
	}
}
int sum(int ind){
	int sm = 0;
	for(int i=ind+1; i>0; i-=(i&-i)){
		sm+=bit[i];
	}
	return sm;
}
int main(){
	int q;
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	string s;
	long long int seed = 57;
	for(int i=0; i<n; i++){
		cin>>s;
		long long int cr = 0;
		for(int j=0; j<s.size(); j++){
			cr*=seed; cr+=(s[j]-'a')+1;
			if(j==s.size()-1 && !MLE_REEE.count(cr)){
				MLE_REEE[cr]=i;
			}
		}
		wrds.push_back({s, i});
	}
	sort(wrds.begin(), wrds.end());
	for(int i=0; i<wrds.size(); i++){
		sind[wrds[i].second]=i;
	}
	cin>>q;
	for(int i=0; i<q; i++){
		cin>>s;
		int fnv = n-1;
		long long int cr = 0;
		for(int j=0; j<s.size(); j++){
			cr*=seed; cr+=(s[j]-'a')+1;
		}
		if(MLE_REEE.count(cr)){
			fnv = MLE_REEE[cr];
		}
		qrs.push_back(s);
		srtd.push_back({fnv, i});
	}
	sort(srtd.begin(), srtd.end());
	int cvd=0;
	
	for(auto tpp: srtd){
		for(int i=cvd; i<=tpp.first; i++){
			update(sind[i]);
		}
		cvd=tpp.first+1;
		int st = 0, ed = n-1;
		ans[tpp.second]=tpp.first+1;
		for(int i=0; i<qrs[tpp.second].size(); i++){
			
			int st1=st, ed1=ed;
			int st2=st, ed2=ed+1;
			while(st1<ed1){
				int m = (st1+ed1)/2;
				if(wrds[m].first.size()>i && wrds[m].first[i]>=qrs[tpp.second][i]){
					ed1 = m;
				}
				else{
					st1 = m+1;
				}
			}
			while(st2<ed2){
				int m = (st2+ed2)/2;
				if(wrds[m].first.size()<=i || wrds[m].first[i]<=qrs[tpp.second][i]){
					st2=m+1;
				}
				else{
					ed2 = m;
				}
			}
			if(ed1==ed2 || wrds[ed1].first[i]!=qrs[tpp.second][i] || wrds[ed2-1].first[i]!=qrs[tpp.second][i]){st = ed1; ed = ed2; break;}
			else{st = ed1; ed = ed2-1;}
			ans[tpp.second]+=sum(ed)-sum(st-1);
		}

	}
	for(int i=0; i<q; i++){printf("%i\n", ans[i]);}
}