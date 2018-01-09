#include <bits/stdc++.h>

using namespace std;
int bef[500005];
int aft[500005];
int arr[500005];
int mln[500005];
int pv[500005];
int fv[500005];
bool inp[500005];
int main() {
	int n, k;
	scanf("%i%i", &n, &k);
	aft[n]=0;
	for(int i=1; i<=n; i++){
		bef[i]=i-1;
	}
	for(int i=0; i<n; i++){
		aft[i]=i+1;
	}
	int a, b;
	for(int i=0; i<k; i++){
		getchar();
		char c=getchar();
		scanf("%i%i", &b, &a);
		if (aft[b]!=0){
			bef[aft[b]]=bef[b];
		}
		aft[bef[b]]=aft[b];
		if (c=='A'){
			aft[bef[a]]=b;
			bef[b]=bef[a];
			aft[b]=a;
			bef[a]=b;
		}
		else{
			if(aft[a]!=0){
				bef[aft[a]]=b;
			}
			aft[b]=aft[a];
			aft[a]=b;
			bef[b]=a;
		}
	}
	int st = 0;
	for(int i=1; i<=n; i++){
		st = aft[st];
		arr[i]=st;
	}
	int mns = 0;
	for(int i=1; i<=n; i++){
		int nind = upper_bound(mln, mln+mns+1, arr[i])-mln;
		if (nind>mns){
			mns+=1;
		}
		mln[nind]=arr[i];
		fv[nind]=i;
		pv[i]=fv[nind-1];
	}
	printf("%i\n", n-mns);
	st = fv[mns];
	while(st>0){
		inp[arr[st]]=1;
		st=pv[st];

	}
	for(int i=arr[fv[mns]]+1; i<=n; i++){
		printf("B %i %i\n", i, i-1);
	}
	for(int i=arr[fv[mns]]; i>0; i--){
		if(inp[i]){ continue; }
		else{
			printf("A %i %i\n", i, i+1);
		}
	}
    return 0;
}