#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int arr[1000005];
unordered_map<int, int> cn;
vector<int> nd;
int main() {
	int n;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%i", &arr[i]);
		cn[arr[i]]++;
	}
	for(int i=1; i<=n; i++){
		if(!cn.count(i)){nd.push_back(i);}
	}
	if(cn.size()==1){printf("-1"); return 0;}
	for(int i=1; i<=n; i++){
		if(cn.size()==0){
			printf("%i ", nd.back());
			nd.pop_back();
			continue;
		}
		auto it = cn.begin();
		if(it->first==arr[i]){
			it->second--;
			if(cn.size()==1){
				printf("%i ", nd.back());
				nd.pop_back();
			}
			else{
				auto it2 = it;
				++it2;
				printf("%i ", it2->first);
				cn.erase(it2);
			}
			if(it->second == 0){
				cn.erase(it);
				nd.push_back(arr[i]);
			}
			continue;
		}
		else{
			printf("%i ", it->first);
			cn.erase(it);
			it = cn.find(arr[i]);
			if(it!=cn.end()){
				it->second--;
				if(it->second==0){nd.push_back(arr[i]); cn.erase(it);}
			}
		}
	}
    return 0;
}