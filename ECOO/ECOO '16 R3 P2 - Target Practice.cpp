#include <bits/stdc++.h>
using namespace std;
double trgt[5][4];
int main(){
	int aw, ah, bx;
	double by, sx, sy, tp;
	int t=10;
	while(t--){
		cin>>aw>>ah>>bx>>by>>sx>>sy;
		for(int i=0; i<5; i++){
			cin>>trgt[i][0]>>trgt[i][1]>>trgt[i][2];
			trgt[i][3]=0;
		}
		sy = sy/sx;
		int tp=0;
		
		for(int i=bx+1; i<aw; i++){
			by += sy;
			if (!sx){ break; }
			while(by<0 || by>ah){
				if (by<0){ sy*=-1; by*=-1; }
				else{ by = 2*ah - by; sy*=-1;}
			}
			if (by==0 || by == ah){
				sy*=-1;
			}
			for(int j=0; j<5; j++){
				if (i==trgt[j][1]){
					if (by<=trgt[j][2] && (trgt[j][2]-trgt[j][0])<=by){
						trgt[j][3]=1;
					}
				}
			}
		}
		for(int i=0; i<5; i++){
			if (trgt[i][3]){ cout<<"H"; }
			else{ cout<<"M"; }
		}
		cout<<"\n";

	}
	return 0;
}