#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
bool p[109];
bool a[10090];
vector<int> an;
int main() {
	int n, t;
	bool s;
	for(int i=0; i<10; i++){
		memset(p, 0, 109);
		memset(a, 0, 10090);
		an.clear();
		scanf("%i", &n);
		for(int k=0; k<n; k++){
			scanf("%i", &t);
			p[t]=true;
		}
		for(int k=1; k<=100; k++){
			if(p[k]){an.push_back(k);}
		}
		for(int k=0; k<an.size(); k++){
			for(int j=k; j<an.size(); j++){
				a[an[j]*an[k]]=true; a[an[j]+an[k]]=true;
			}
		}
		for(int k=0; k<5; k++){
			s=0;
			scanf("%i", &t);
			for(int j=0; j<an.size(); j++){
				if (t%an[j]==0 && t/an[j]<=10000 && a[t/an[j]]){
					s=true; break;
				}
				if (t-an[j]>0 && t-an[j]<=10000 && a[t-an[j]]){
					s=true; break;
				}
			}
			if (s){printf("T");}
			else{printf("F");}
		}
		printf("\n");
	}
	return 0;
}