#include <bits/stdc++.h>
using namespace std;

int sv[15];
int sv2[15];
map<int, pair<int, int> > pvls;
int main(){
	int n;
	scanf("%i", &n);
	int ts = 0;
	int h1 = n/2;
	int h2 = n-n/2;
	for (int i=0; i<h1; i++){
		scanf("%i", &sv[i]);
		ts+=sv[i];
	}
	
	for(int i=0; i<h2; i++){
		scanf("%i", &sv2[i]);
	}
	int mx = ts;
	int vl1 = 0;
	int vl2 = 0;
	int tt2 = 0;
	int tt3 = 0;
	for(int i=0; i<(1<<h1); i++){
		tt2 = 0;
		for(int j=0; j<h1; j++){
			if (!(i&(1<<j))){
				tt2+=sv[j];
			}
		}
		tt3 = 0;
		if (tt2>tt3){
			pvls[abs(tt2-tt3)]={((1<<h1)-1)^i,0};
		}
		else{
			pvls[abs(tt2-tt3)]={0, ((1<<h1)-1)^i};
		}
		for(int j=i; j>0; j=(j-1)&i){
			tt3 = 0;
			for(int k=0; k<h1; k++){
				if (j&(1<<k)){
					tt3+=sv[k];
				}
			}
			if (abs(tt2-tt3)<mx){
				mx = abs(tt2-tt3);
				vl1=((1<<h1)-1)^i;
				vl2=j;
			}
			if (tt2>tt3){
				pvls[abs(tt2-tt3)]={((1<<h1)-1)^i,j};
			}
			else{
				pvls[abs(tt2-tt3)]={j, ((1<<h1)-1)^i};
			}
		}
	}
	for(int i=0; i<(1<<h2); i++){
		tt2 = 0;
		for(int j=0; j<h2; j++){
			if (!(i&(1<<j))){
				tt2+=sv2[j];
			}
		}
		tt3 = 0;
		auto it = pvls.lower_bound(abs(tt2-tt3));
		if (it!=pvls.end() && abs(it->first-abs(tt2-tt3))<mx && (it->second.second) && (it->second.first|(((1<<h2)-1)^i))){
			mx = abs(it->first-abs(tt2-tt3));
			vl1 = it->second.first|(0<<h1);
			vl2 = it->second.second|((((1<<h2)-1)^i)<<h1);
		}
		if (it!=pvls.begin()){
			--it;
			if(abs(it->first-abs(tt2-tt3))<mx && (it->second.second) && (it->second.first|(((1<<h2)-1)^i))){
				mx = abs(it->first-abs(tt2-tt3));
				vl1 =(it->second.first)|(0<<h1);
				vl2 = (it->second.second)|((((1<<h2)-1)^i)<<h1);
			}
		}
		for(int j=i; j>0; j=(j-1)&i){
			tt3 = 0;
			for(int k=0; k<h2; k++){
				if (j&(1<<k)){
					tt3+=sv2[k];
				}
			}
			auto it = pvls.lower_bound(abs(tt2-tt3));
			int ti=i, tj=j;
			if (tt2>tt3){
				// WHAT THE HELL tie(i,j)=tie(j,i);
				ti=((1<<h2)-1)^j; tj=((1<<h2)-1)^i;
			}
			if (it!=pvls.end() && abs(it->first-abs(tt2-tt3))<mx && (it->second.second|tj) && (it->second.first|(((1<<h2)-1)^ti))){
				mx = abs(it->first-abs(tt2-tt3));
				vl1 = it->second.second|(tj<<h1);
				vl2 = it->second.first|((((1<<h2)-1)^ti)<<h1);
				//printf("ff%i %i %i %i %i %i %i %i %i\n", it->first, tt2, tt3, it->second.first, it->second.second, i, j, vl1, vl2);
			}
			if (it!=pvls.begin()){
				--it;
				if(abs(it->first-abs(tt2-tt3))<mx && (it->second.second|tj) && (it->second.first|(((1<<h2)-1)^ti))){
					mx = abs(it->first-abs(tt2-tt3));
					vl1 =(it->second.second)|(tj<<h1);
					vl2 = (it->second.first)|((((1<<h2)-1)^ti)<<h1);

				}
			}

		}
	}
	//wa, I would expect, but why does this tle? Oh, because I'm an idiot...
	//printf("%i %i %i\n", vl1, vl2, mx);
	for(int i=0; i<n; i++){
		if ((vl1&(1<<i))){
			printf("%i ", i+1);
		}
	}
	putchar('\n');
	for(int i=0; i<n; i++){
		if(vl2&(1<<i)){
			printf("%i ", i+1);
		}
	}
}