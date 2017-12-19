#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int srs[100005];
int cnt[100005];
int ans[100005];
vector<pair<pair<int, int>, pair<int, int> > > queries;

int main(){
	int n, q, l, r, sqn;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%i", &srs[i]);
	}
	sqn=sqrt(n);
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i%i", &l, &r);
		queries.push_back({{l/sqn, r}, {l, i}});
	}
	int cv=0;
	sort(queries.begin(), queries.end());
	l=queries[0].second.first; r=l;
	cnt[srs[l]]=1;
	for(auto tp: queries){
		while(r<tp.first.second){
			r++;
			cnt[srs[r]]++;
			if (!(cnt[srs[r]]%2)){ cv++; }
			else if (cnt[srs[r]]>1){ cv--; }
		}
		while(l>tp.second.first){
			l--;
			cnt[srs[l]]++;
			if (!(cnt[srs[l]]%2)){ cv++; }
			else if (cnt[srs[l]]>1){ cv--; }
		}
		while(r>tp.first.second){
			cnt[srs[r]]--;
			if (cnt[srs[r]]%2){cv--; }
			else if (cnt[srs[r]]>0){ cv++; }
			r--;
		}
		while(l<tp.second.first){
			cnt[srs[l]]--;
			if(cnt[srs[l]]%2){ cv--; }
			else if (cnt[srs[l]]>0){ cv++; }
			l++;
		}
		ans[tp.second.second]=cv;
	}
	for(int i=0; i<q; i++){
		printf("%i\n", ans[i]);
	}

}