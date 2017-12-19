#include <cstdio>
#include <vector>
using namespace std;
int dsj[100005];
int rnk[100005];
int root(int cn){
	while(dsj[cn]!=cn){
		cn=dsj[cn];
	}
	return cn;
}
void merge(int pa, int pb){
	dsj[pb]=pa;
	if (rnk[pb]==rnk[pa]){
		rnk[pa]++;
	}
}
int cls[100005];
vector<int> ptinf;
int main() {
	int n, m, k, tp, mnd, tprk;
	scanf("%i%i", &n, &m);
	for(int i=1; i<=n; i++){
		dsj[i]=i; 
	}
	for(int i=0; i<m; i++){
		scanf("%i", &k); tprk=-1;
		for(int j=0; j<k; j++){
			scanf("%i", &tp);
			cls[j]=root(tp);
			if (rnk[cls[j]]>=tprk){
				tprk=rnk[cls[j]]; mnd=cls[j];
			} 
		}
		for(int j=0; j<k; j++){
			if (cls[j]!=mnd) merge(mnd, cls[j]);
		}
	}
	int infct=root(1);
	for(int i=1; i<=n; i++){
		if (root(i)==infct){
			ptinf.push_back(i);
		}
	}
	printf("%i\n", ptinf.size());
	for(int i=0; i<ptinf.size(); i++){
		printf("%i ", ptinf[i]);
	}
	return 0;
}