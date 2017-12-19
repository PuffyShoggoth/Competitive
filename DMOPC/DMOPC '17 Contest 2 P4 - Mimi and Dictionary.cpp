#include <bits/stdc++.h>
using namespace std;
char ar[200005];
int pvl[200005];
int ind = 1;
int fm[200005];
int gl(int a, int b){
	int tt = 0;
	while(a>=0 && b<ind && ar[a]==ar[b]){
		tt++;
		a--; b++;
	}
	return tt;
}
int main(){
	ar[0]='$';
	char tp = getchar();
	while(tp>='a' && tp<='z'){
		ar[ind]=tp;
		ar[ind+1]='$';
		ind +=2;
		tp = getchar();
	}
	int lng = 0;
	for(int i=0; i<ind; i++){
		if (i>lng+pvl[lng]){
			pvl[i]=gl(i-1, i+1);
		}
		else{
			int op = lng*2 - i;
			if (pvl[op]+i > lng+pvl[lng]){
				pvl[i] = lng+pvl[lng]-i;
			}
			else if (pvl[op]+i < lng+pvl[lng]){
				pvl[i] = pvl[op];
			}
			else{
				pvl[i] = pvl[op] + gl(i-pvl[op]-1, i+pvl[op]+1);
			}
		}
		if(pvl[i]+i>pvl[lng]+lng){
			lng = i;
		}
	}
	int a = -1, b=0;
	int tmx = 0;
	fm[0]=-1;
	while(b<ind){
		while(a>=0 && ar[a]!=ar[b]){ a = fm[a]; }
		if (a>=0){
			if (a%2==0){
				if (pvl[a/2]==a/2){
					if (ar[a/2]=='$'){
						tmx = max(tmx, pvl[a/2]);
					}
					else{
						int tp = pvl[a/2]/2;
						tmx = max(tmx, tp*2+1);
					}
					
				}
			}
		}
		a++; b++;
		fm[b] = a;
	}
	printf("%i", tmx);
	return 0;
}