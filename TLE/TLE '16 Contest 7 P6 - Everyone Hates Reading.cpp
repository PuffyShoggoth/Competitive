#include <bits/stdc++.h>

using namespace std;

int nxt=1;
int trie[100005][30];
vector<int> flwrd[100005], pfx[100005];

int main(){
	string tp;
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, m, l, r, curr;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>tp; curr=0;
		for(int j=0; j<tp.length(); j++){
			pfx[curr].push_back(i);
			if (trie[curr][tp[j]-'a']){ curr = trie[curr][tp[j]-'a']; }
			else{trie[curr][tp[j]-'a']=nxt; curr = nxt; nxt++; }
		}
		flwrd[curr].push_back(i);
	}
	int tt;
	for(int i=0; i<m; i++){
		cin>>tp; cin>>l>>r; curr=0; tt=0;
		for(int j=0; j<tp.length(); j++){
			curr = trie[curr][tp[j]-'a'];
			if (curr==0){ break; }
			tt+= (upper_bound(flwrd[curr].begin(), flwrd[curr].end(), r) - lower_bound(flwrd[curr].begin(), flwrd[curr].end(), l));
		}
		if (curr!=0){
			tt+= (upper_bound(pfx[curr].begin(), pfx[curr].end(), r) - lower_bound(pfx[curr].begin(), pfx[curr].end(), l));
		}
		cout<<tt<<"\n";
	}
	return 0;
}