#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int vls[10005];
int segmn[26385], segmx[26385];
void upd(int ind, int vl){
	int cind = 16384+ind;
	segmn[cind]=vl; segmx[cind]=vl;
	cind>>=1;
	while(cind>0){
	    if(segmn[cind*2+1]==-1){segmn[cind] = segmn[cind*2];}
	    else if(segmn[cind*2]==-1){segmn[cind]=segmn[cind*2+1];}
		else{segmn[cind] = min(segmn[cind*2], segmn[cind*2+1]);}
		segmx[cind] = max(segmx[cind*2], segmx[cind*2+1]);
		cind>>=1;
	}
}
int main() {
	int n, m, c;
	scanf("%i%i%i", &n, &m, &c);

	int ed = 0;
	memset(segmn, -1, sizeof(segmn)); memset(segmx, -1, sizeof(segmx));
	for(int j = 1; j<=m; j++){
		scanf("%i", &vls[ed]);
		upd(ed, vls[ed]);
		ed = (ed+1)%m;
	}

	bool dn = 0;
	if(segmx[1]-segmn[1]<=c){dn = 1; printf("%i\n", 1);}
	for(int j = 2; j<=n-m+1; j++){
		scanf("%i", &vls[ed]);
		upd(ed, vls[ed]); ed = (ed+1)%m;
		if(segmx[1]-segmn[1]<=c){dn = 1; printf("%i\n", j);}
	}
	if(!dn){ printf("NONE\n"); }
	
    return 0;
}