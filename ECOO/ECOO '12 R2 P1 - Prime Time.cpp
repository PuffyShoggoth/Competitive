#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

bool seive[500005];
vector<int> pvls;
vector<int> prms;
pair<char, char> vls[10005];
bool vld[10005];
vector<char> l;
int main() {
	seive[0]=1; seive[1]=1;
	for(int i=2; i<800; i++){
		if(seive[i]){continue;}
		for(int j=i*i; j<500001; j+=i){
			seive[i]=1;
		}
	}
	for(int i=100000; i<500000; i++){
		if(!seive[i]) prms.push_back(i);
	}
	l.push_back(' ');
	for(char i = 'A'; i<='Z'; i++){
		l.push_back(i);
	}
	l.push_back('.');
	l.push_back(',');
	l.push_back('!');
	l.push_back('?');
	for(int i=0; i<31; i++){
		for(int j=0; j<31; j++){
			vld[i*100+j]=1;
			vls[i*100+j]={l[i],l[j]};
		}
	}
	for(int dnr=0; dnr<5; dnr++){
		int n;
		cin>>n;
		long long int tmp;
		vector<long long int> fvls;
		int vind=0;
		for(int i=0; i<n; i++){
			cin>>tmp;
			fvls.push_back(tmp);
			
		}
		while(vind<prms.size()){
			bool dn=1;
			for(long long int i:fvls){
				if(i%prms[vind] || !vld[i/prms[vind]]){
					dn=0;
					break;
				}
			}
			if(dn) break;
			else vind++;
		}
		for(long long int i:fvls){
			cout<<vls[i/prms[vind]].first<<vls[i/prms[vind]].second;
		}
		cout<<'\n';
	}
    return 0;
}