#include <bits/stdc++.h>
using namespace std;
bool vld[51];
bitset<25000> pos;
vector<int> pil;
int main(){
	int n, h;
	scanf("%i", &n);
	int mx=0;
	for(int i=0; i<n; i++){
		scanf("%i", &h);
		if (h>mx){
			vld[mx]=1;
			mx=h;
		}
		else{
			vld[h]=1;
		}
		pil.push_back(h);
	}
	vld[0]=0;
	sort(pil.begin(), pil.end());
	pos[0]=1;
	for(int i=0; i<pil.size()-1; i++){
		for(int j=mx*n; j>=0; j--){
			for(int k=pil[i]; k<=50; k++){
				if (k-pil[i]>j){ break; }
				if (vld[k]){
					if (pos[j-k+pil[i]]){
						pos[j]=1; break;
					}
				}
			}
		}
	}
	for(int i=0; i<=50*n; i++){
		if(pos[i]){printf("%i ", i);}
	}
	return 0;
}