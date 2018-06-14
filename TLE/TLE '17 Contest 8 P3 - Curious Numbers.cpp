#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<long long int> vld;
vector<pair<long long int, long long int> > svals[2];

int main() {
	int q;
	long long int k;
	scanf("%i%lli", &q, &k);
	vld.push_back(0);
	for(int i=1; i<10; i++){
		svals[0].push_back({i, i*10});
		if(i%k==0){vld.push_back(i);}
		if((i+i*10)%k==0){vld.push_back(i+i*10);}
	}
	int curr = 1, pv = 0;
	long long int cm = 1;
	for(int i=0; i<=5; i++){
		svals[curr].clear();
		cm = cm*10;
		bool br = 0;
		for(pair<long long int, long long int> tp: svals[pv]){
			for(int j=0; j<10; j++){
				if((tp.first+tp.second*10+cm*j)%k==0){
					vld.push_back(tp.first+tp.second*10+cm*j);
					if(tp.first+tp.second*10+cm*j > 1e10){ br = 1; break;}
				}
				long long int tpa = tp.first+j*cm, tpb = tp.second*100+cm*j*10;
				if((tpa+tpb)%k==0){vld.push_back(tpa+tpb);}
				if(i!=5){svals[curr].push_back({tpa, tpb});}
			}
			if(br){ break;}
		}

		curr = pv; pv = (curr+1)%2;
	}
	//printf("%i\n", vld.size());

	sort(vld.begin(), vld.end());
	/*for(int i=0; i<50; i++){
		printf("%lli ", vld[i]);
	}*/
	for(int i=0; i<q; i++){
		long long int n, m;
		scanf("%lli%lli", &m, &n);
		int a = upper_bound(vld.begin(), vld.end(), n)-vld.begin();
		int b = lower_bound(vld.begin(), vld.end(), m)-vld.begin();
		printf("%i\n", a-b);
	}
    return 0;
}