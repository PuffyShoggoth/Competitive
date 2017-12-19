#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int flag[10009];
vector<int>cnct[10009];
pair <int, int> tree(int nd){
	pair <int, int> t;
	int m=0, cl=0;
	for (int i=0; i<cnct[nd].size(); i++){
		if (flag[cnct[nd][i]]==0){
			flag[cnct[nd][i]]=1;
			t=tree(cnct[nd][i]);
			cl=max(cl, max(m+t.first+1, t.second));
			m=max(m, t.first+1);
		}
	}
	t=make_pair(m, cl);
	return t;
}

int main() {
	int n, x, y;
	pair <int, int> t;
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>x>>y;
		cnct[x].push_back(y);
		cnct[y].push_back(x);
	}
	if (n==1){cout<<0;}
	else{flag[1]=1;
	t=tree(1);
	cout<<max(t.first, t.second);}
	return 0;
}