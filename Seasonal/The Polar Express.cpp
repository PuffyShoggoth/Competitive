#include <bits/stdc++.h>
using namespace std;
bool pob[180];
int tt = 0;
bool dp[20][180][3];
int l[20], r[20];
void mrk(int ind, int sm, int id){
	if(ind<0){
		if(pob[sm]){return;}
		tt++;
		pob[sm]=1;
		return;
	}
	if(dp[ind][sm][id]){ return; }
	dp[ind][sm][id]=1;
	if(id==1){
		mrk(ind-1, sm+l[ind], 1);
		for(int i=l[ind]+1; i<10; i++){
			mrk(ind-1, sm+i, 0);
		}
	}
	else if (id==2){
		mrk(ind-1, sm+r[ind], 2);
		for(int i=0; i<r[ind]; i++){
			mrk(ind-1, sm+i, 0);
		}
	}
	else{
		for(int i=0; i<10; i++){
			mrk(ind-1, sm+i, 0);
		}
	}
}
int main(){
	unsigned long long int tl, tr;
	scanf("%llu%llu", &tl, &tr);
	if (tl==tr){
		printf("1");
		return 0;
	}
	for(int i=0; i<20; i++){
		if (tl>0){
			l[i]=tl%10;
			tl = tl/10;
		}
		if(tr>0){
			r[i]=tr%10;
			tr = tr/10;
		}
	}
	for(int i=19; i>=0; i--){
		if (l[i]!=r[i]){
			mrk(i-1, l[i], 1);
			mrk(i-1, r[i], 2);
			for(int j=l[i]+1; j<r[i]; j++){
				mrk(i-1, j, 0);
			}
			break;
		}
	}
	printf("%i", tt);
}