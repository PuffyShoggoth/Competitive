#include <iostream>
#include <vector>
using namespace std;
int seq[100009];
vector<int>pos[2009];
int bsrch(int ss, int se, int tn){
	int m, s=0, e=pos[tn].size()-1;
	while (s<=e){
		m=(s+e)/2;
		if (pos[tn][m]<ss){
			s=m+1;
			}
		else if (pos[tn][m]>se){
			e=m-1;
		}
		else{return 1;}	
		}
	
	return 0;
}
	

int main() {
	int N, K, Q, x, y, qa, qb, a, b;
	cin>>N>>K>>Q;
	for (int i=1; i<=N; i++){
		scanf("%i", &seq[i]);
		pos[1000+seq[i]].push_back(i);
		seq[i]+=seq[i-1];
	}
	
	 for (int i=0; i<Q; i++){
		scanf("%i%i%i%i", &qa, &qb, &x, &y);
		qa+=1000; qb+=1000;
		if (seq[y]-seq[x-1]>K){
			if (bsrch(x, y, qa)>0 && bsrch(x, y, qb)>0){
				printf("%s", "Yes\n");
			}
			else{printf("%s", "No\n");}
		}
		else{printf("%s", "No\n");}
	}
	return 0;
}