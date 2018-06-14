#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> edges[1005]; 

int mxdpth = 0;
int lnd =0;
int gdpth(int cn, int par, int cd){
	if(cd>mxdpth){
		lnd = cn;
		mxdpth = cd;
	}
	for(int i: edges[cn]){
		if(i!=par){ gdpth(i, cn, cd+1); }
	}
}
int main() {
	for(int dnr = 0; dnr<5; dnr++){
		string s;
		getline(cin, s);
		int currn = 0;
		int ind = 0;
		stack<int> cvl;
		int tt = 0;
		for(int i=0; i<1005; i++){edges[i].clear();}
		while(ind<s.length()){
			//cout<<s[ind];
			if(s[ind]=='('){
				if(!cvl.empty()){
					edges[cvl.top()].push_back(currn);
					edges[currn].push_back(cvl.top());
				}
				cvl.push(currn);
				currn++;
				ind++;
			}
			else if(s[ind]==')'){
				cvl.pop();
				ind++;
			}
			else if(s[ind]>='0' && s[ind]<='9'){
				int stv = 0;
				while(ind<s.length() && s[ind]>='0' && s[ind]<='9'){
					stv = stv*10 + s[ind]-'0';
					ind++;
				}
				if(!cvl.empty()){
					edges[cvl.top()].push_back(currn);
					edges[currn].push_back(cvl.top());
				}
				tt+=stv;
				currn++;
			}
			else{
				ind++;
			}

		}
		//cout<<'\n';
		mxdpth = 0;
		gdpth(0, -1, 0);
		//cout<<currn<<" "<<mxdpth<<" "<<'\n';
		cout<<(currn-1)*2-mxdpth<<" "<<tt<<"\n";

	}
    return 0;
}