#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int besthub(int R, int L, int X[], long long int B){
	long long int tc = 0;
	long long int find = 0, bind = 0;
	long long int bvl=0;
	long long int mbvl = 0;
	while(find<R && tc+(X[find]-X[0])<=B){
		tc+=X[find]-X[0];
		bvl++;
		find++;
	}
	mbvl = bvl;
	for(long long int i = 1; i<R; i++){
		tc-=(find-i)*(X[i]-X[i-1]);
		tc+=(i-bind)*(X[i]-X[i-1]);
		while(bind<i && (i-bind > find-i) && tc>B){
			tc -= X[i]-X[bind];
			bind++;
		}
		while(find<R && tc+X[find]-X[i]<=B){
			tc+=X[find]-X[i];
			find++;
		}
		//if(bvl>mbvl){printf("%lli %lli %lli\n", i, bvl, tc);}
		mbvl = max(bvl, mbvl);
		while(bind<i && (i-bind> find-i) && find<R && (X[find]-X[i]<X[i]-X[bind])){
			tc-=X[i]-X[bind]; tc+=X[find]-X[i]; bind++; find++;
			while(find<R && tc+X[find]-X[i]<=B){
				tc+=X[find]-X[i];
				find++;
			}
		}
		bvl = find-bind;
		mbvl = max(bvl, mbvl);
	}
	return mbvl;
}