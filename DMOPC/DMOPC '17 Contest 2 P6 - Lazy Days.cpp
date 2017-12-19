#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
priority_queue<pair<int, pair<int, bool> >, vector<pair<int, pair<int, bool> > >, greater<pair<int, pair<int, bool> > > > vls;
map<int, bool> itvl;
int main(){
	int n;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i", &a[i]);
		vls.push({a[i], {i, 0}});
	}
	for(int i=0; i<n; i++){
		scanf("%i", &b[i]);
		vls.push({b[i], {i,1}});
	}
	itvl[n]=1;
	itvl[-1]=1;
	int ext = 0;
	for(int i=0; i<=n; i++){
		while(vls.size()){
			int pos=vls.top().second.first;
			bool id = vls.top().second.second;
			auto it = itvl.lower_bound(pos);
			auto itb = it; --itb;
			if (it->first == pos){
				for(int j=i; j<=n; j++){
					printf("%i\n", vls.top().first);
				}
				return 0;
			}
			else if (it->second==id || itb->second==id){
				itvl[pos]=id;
				vls.pop();
				continue;
			}
			else {
				printf("%i\n", vls.top().first);
				if (it->first == n){
					it->second = id;
					itvl[pos]=id;
					vls.pop();
				}
				else if(ext>0){
					ext--;
					itvl[pos]=id;
					vls.pop();
				}
				else{
					ext++;
				}
				break;
			}
		}
	}
	return 0;
}