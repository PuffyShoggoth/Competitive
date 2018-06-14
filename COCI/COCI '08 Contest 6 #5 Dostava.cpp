#include <bits/stdc++.h>
#define min(a, b) (a<b?a:b)
using namespace std;
const int INF = 0x3f3f3f3f;
int vls[2050][250];
int pfx[2050][250];
int dp[2050][2][2];
int sp[2050];
int sf[2050];
vector<pair<int, pair<int, int> > > rqst[2050];
vector<pair<int, int> > smr[2050];
int main() {
	int r, c;
	scanf("%i%i", &r, &c);
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			scanf("%i", &vls[i][j]);
		}
	}
	int d;
	scanf("%i", &d);
	int tr, tc, pr=1, pc=1;
	long long int tt = vls[1][1];
	for(int i=0; i<d; i++){
		scanf("%i%i", &tr, &tc);
		if(tr<pr){
			rqst[tr].push_back({tc, {pr, pc}});
		}
		else if(tr==pr){
			smr[tr].push_back({min(tc, pc), max(tc, pc)});
		}
		else{
			rqst[pr].push_back({pc, {tr, tc}});
		}
		tt+=vls[tr][tc];
		pr = tr; pc = tc;
	}
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			pfx[i][j] = pfx[i][j-1]+vls[i][j];
		}
	}
	//printf("%lli\n", pfx[182][c]);
	sp[1] = pfx[1][c];
	for(int i=2; i<=r; i++){
		sp[i] = min(sp[i-1]+vls[i][1]+vls[i][c], pfx[i][c]);
		//printf("%i\n", sp[i]);

	}
	sf[r] = pfx[r][c];
	for(int i=r-1; i>0; i--){
		sf[i] = min(sf[i+1]+vls[i][1]+vls[i][c], pfx[i][c]);
	}
	//int ptt = tt;
	//printf("%i\n", tt);
	if(r==1){
		for(pair<int, int> tpp: smr[r]){
			tt+=pfx[r][tpp.second-1]-pfx[r][tpp.first];//:min(pfx[r][tpp.second-1]-pfx[r][tpp.first], pfx[r][tpp.first-1]+pfx[r][c]-pfx[r][tpp.second]+sp[r-1]));
		}
		printf("%lli", tt); 
		return 0;
	}

	for(int i=r; i>0; i--){
		dp[i+1][0][0]=vls[i+1][1]; dp[i+1][1][1]=vls[i+1][c];
		dp[i+1][0][1]=dp[i+1][1][0]=pfx[i+1][c];
		for(int j=i+2; j<=r; j++){
			dp[j][0][0]=min(dp[j-1][0][0]+vls[j][1], pfx[j][c]+dp[j-1][0][1]);
			dp[j][1][1]=min(dp[j-1][1][1]+vls[j][c], pfx[j][c]+dp[j-1][1][0]);
			dp[j][0][1]=min(dp[j-1][0][1]+vls[j][c], pfx[j][c]+dp[j-1][0][0]);
			dp[j][1][0]=min(dp[j-1][1][0]+vls[j][1], pfx[j][c]+dp[j-1][1][1]);
		}
		for(pair<int, int> tpp: smr[i]){
			tt+=min(pfx[i][tpp.second-1]-pfx[i][tpp.first], pfx[i][tpp.first-1]+pfx[i][c]-pfx[i][tpp.second]+(i==1?(sf[i+1]):((i==r)?(sp[i-1]):min(sp[i-1], sf[i+1]))));
			//if(tt-ptt==-20784){printf("%i %i %i %i\n", i, tpp.first, tpp.second, tt-ptt);}
			//ptt = tt;
		}
		for(pair<int, pair<int, int> > tpp: rqst[i]){
			int s1 = pfx[i][tpp.first-1], s2 = pfx[i][c]-pfx[i][tpp.first];
			if(i!=1){
				int ts2 = min(s2, s1+sp[i-1]+vls[i][c]), ts1 = min(s1, s2+sp[i-1]+vls[i][1]);
				s1 = ts1; s2 = ts2;
			}
			int d1 = pfx[tpp.second.first][tpp.second.second-1], d2 = pfx[tpp.second.first][c]-pfx[tpp.second.first][tpp.second.second];
			if(tpp.second.first!=r){
				int tsf = tpp.second.first;
				int td2 = min(d2, d1+sf[tsf+1]+vls[tsf][c]), td1 = min(d1, d2+sf[tsf+1]+vls[tsf][1]);
				d1 = td1; d2 = td2;
			}
			if(tpp.second.first==i+1){
				tt+=min(d1+s1, d2+s2);
			}
			else{
				int tsf = tpp.second.first;
				tt+=min(min(s1+d1+dp[tsf-1][0][0], s1+d2+dp[tsf-1][0][1]), min(s2+d2+dp[tsf-1][1][1], s2+d1+dp[tsf-1][1][0]));
			}
			
			/*if(tt-ptt==-20784){
				printf("%i %i %i %i %lli %lli %lli %lli %lli\n", i, tpp.first, tpp.second.first, tpp.second.second, s1, s2, d1, d2, tt-ptt);
				printf("%lli %lli\n", pfx[i][c], pfx[tpp.second.first][c]);
				printf("%lli %lli %lli %lli\n", dp[i+1][tpp.second.first][0][0], dp[i+1][tpp.second.first][0][1], dp[i+1][tpp.second.first][1][1], dp[i+1][tpp.second.first][1][0]);
			}

			ptt = tt;*/
		}

	}
	//printf("%lli\n", pfx[182][c]);
	printf("%lli", tt);
    return 0;
}