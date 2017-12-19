#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int> >pln;


int main(){
	int n, p, a, b, f, nv=1;
	scanf("%i%i", &n, &p);
	for(int i=1; i<=n; i++){
		scanf("%i%i", &a, &b);
		if (i==p){
			f=a; continue;
		}
		else if (b>a){ continue; }
		else{
			pln.push_back({b, a});
		}
	}
	sort(pln.begin(), pln.end());
	for(pair<int, int> tp: pln){
		if (f<tp.first){break; }
		f+=tp.second-tp.first;
		nv++;
	}
	printf("%i\n%i\n", f, nv);

}