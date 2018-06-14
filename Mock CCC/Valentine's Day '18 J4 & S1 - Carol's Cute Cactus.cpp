#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int vlsx[10];
int vlsn[10];
int main() {
	int mn, mx;
	scanf("%i%i", &mn, &mx);
	int md = (mn+mx)/2;
	int md2=md;
	vector<int> vls;
	while(md2){
		vls.push_back(md2%10);
		md2=md2/10;
	}
	int mp = vls.size()-1;
	int mnp = vls.size()/2+(vls.size()%2)-1;
	int tt1 = 0, tt2=0;
	for(int i=mp, cnt=0; i>mnp; i--, cnt++){
		tt1+=round(pow(10, i))*vls[i]; tt2+=round(pow(10, cnt))*vls[i];
	}
	int mvl, fans=tt1+tt2;
	if(vls.size()%2){
		mvl = round(pow(10, mnp)); fans+=vls[mnp]*mvl;
	}
	else{
		mvl = round(pow(10, mnp));
		int mnp2 =mnp+1;
		int mvl2 = round(pow(10, mnp2));
		mvl+=mvl2;
		mnp++;
	}
	if(vls[mnp]!=9 && max(mx-fans-mvl, fans+mvl-mn)<max(mx-fans, fans-mn)){
		fans+=mvl;
	}
	if(vls[mnp]!=0 && max(mx-fans+mvl, fans-mvl-mn)<max(mx-fans, fans-mn)){
		fans-=mvl;
	}
	printf("%i", fans);
    return 0;
}