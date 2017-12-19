#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define f first
#define s second
#define mp make_pair
//Brute force of ignorance
using namespace std;
int dist(int xa, int ya, int xb, int yb){
	return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}
int taken[401][401];
pair<int, int> homes[101];
vector<pair<int, int> >dst;
void prbal(){
	memset(taken, 0, 643204);
	memset(homes, 0, 808);
	int ast, rx, ry, tx, ty, cnt;
	double democ=0, repub=0;
	char tmp, usl;
	scanf("%i%i", &rx, &ry);
	rx+=200; ry+=200;
	for(int i=0; i<100; i++){
		scanf("%i%i%c%c", &tx, &ty, &usl, &tmp);
		if (tmp=='R'){
			taken[200+tx][200+ty]=-1;
		}
		else{taken[200+tx][200+ty]=1;}
		homes[i]=mp(200+tx, 200+ty);
	}
	for(int i=0; i<=400; i++){
		for(int j=0; j<=400; j++){
		  if (taken[i][j]!=0){continue;}
		  if (dist(i, j, rx, ry)>2500){continue;}
		  dst.clear();
		  cnt=2;
		  for(int k=0; k<100; k++){
		    dst.push_back(mp(dist(i, j, homes[k].f, homes[k].s), taken[homes[k].f][homes[k].s]));
		  }
		  sort(dst.begin(), dst.end());
		  ast=dst[0].s+dst[1].s;
		  while(dst[cnt].f==dst[2].f && cnt<100){
		  	ast+=dst[cnt].s;
		  	cnt+=1;
		  }
		  if (ast>=0){democ+=1;}
		  else{repub+=1;}
		}
	}
	float ttmp=(democ*100)/(repub+democ);
	printf("%.1f\n", ttmp);
	return;
}
int main() {
	for(int dntrs=0; dntrs<10; dntrs++){
		prbal();
	}
	return 0;
}