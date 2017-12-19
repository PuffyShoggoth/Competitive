#include <bits/stdc++.h>
using namespace std;
vector<int> ch[100005];
bool an[100005], tv[100005];
vector<int> r, c;
int dfs(int cn, int par){
	tv[cn] = !(an[cn]^tv[par]);
	int w = tv[cn]?0:1;
	for(int i: ch[cn]){
		w+= dfs(i, cn);
	}
	return w;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >>n;
    string s, id;
    int vl;
    tv[0]=1;
    for(int i=1; i<=n; i++){
    	cin>>id;
    	if (id=="C"){
    		cin>>s;
    		if (s=="?"){
    			r.push_back(i);
    		}
    		else{
	    		c.push_back(i);
	    		an[i] = (s=="AC");
	    	}
    	}
    	else{
    		cin>>vl>>s;
    		if (s=="?"){
    			r.push_back(i);
    		}
    		else{
    			ch[vl].push_back(i);
    			an[i] = (s=="AC");
    		}
    	}
    }
    int mn=0, mx=0, tt=0, tpa, tpb;
    for(int i: c){
    	tt+= dfs(i, 0);
    }
    for(int i: r){
    	tpa = dfs(i, 0);
    	an[i] = 1;
    	tpb = dfs(i, 0);
    	mn += min(tpa, tpb);
    	mx += max(tpa, tpb);
    }
    cout<<mn+tt<<" "<<mx+tt;
    return 0;
}