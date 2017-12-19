#include <cstdio>
#include <vector>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a<b)?b:a)
using namespace std;
vector<int> below[200];
vector<int> cur;
int leaves[200], t, mwt[200][2509], tmp[200][2509];
void tree(int cn){
	if (below[cn].size()<1){
		for(int i=0; i<=t; i++){
			for(int j=0; j<=i; j++){
				mwt[cn][i]=max(mwt[cn][i], min((j+1)*(j+1), leaves[cn]+i-j));
			}
		}
		tmp[cn][t]=leaves[cn]+t;
		return;
	}
	else{
		int ch1=below[cn][0], ch2=below[cn][1];
		tree(ch1); tree(ch2);
		for(int i=0; i<=t; i++){
			for(int j=0; j<=i; j++){
				tmp[cn][i]=max(tmp[cn][i], mwt[ch1][i-j]+mwt[ch2][j]);
			}
			for(int j=0; j<=i; j++){
				mwt[cn][i]=max(mwt[cn][i], min((j+1)*(j+1), tmp[cn][i-j]));
			}
		}
		
	}
	return;
}
int main() {
	int next=1, open=0, intmp;
	char g=' ';
	cur.push_back(0);
	do{
		while(g==' '){g=getchar();}
		if (g>'0' && g<='9'){
			intmp=0;
			while(g>='0' && g<='9'){
				intmp=(intmp<<3)+(intmp<<1)+(g-'0');
				g=getchar();
			}
			below[cur.back()].push_back(next);
			leaves[next]=intmp;
			next+=1;
		}
		else if (g=='('){
			below[cur.back()].push_back(next);
			cur.push_back(next); next+=1; open+=1;
			g=getchar();
		}
		else{
			cur.pop_back(); open-=1;
			g=getchar();
		}
	}while (open>0);
	scanf("%i", &t);
	tree(1);
	printf("%i", tmp[1][t]);
	return 0;
}