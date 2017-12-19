#include <bits/stdc++.h>


using namespace std;

double dp[505][105];
int mtch[21000];
vector<int> drums;
int d;
bool dr(int vl, int nt){
	for(int i=0; i<d; i++){
		if (vl%12 == nt){ return 1;}
		vl = vl/12;
	}
	return 0;
}
double nc(int a, int b){
	double tt=0;
	for(int i=0; i<d; i++){
		if (a%12 != b%12){tt++;}
		a=a/12; b=b/12;
	}
	return tt;
}
void allvl(int pv, int cd, int pvl){
	pvl*=12;
	if (cd==1){
		for(int i=pv-1; i>=0; i--){mtch[pvl+i]=drums.size(); drums.push_back(pvl+i);}
	}
	else{
		for(int i=pv-1; i>=0; i--){
			allvl(i, cd-1, pvl+i);
		}
	}
	return;
}
int main(){
	int n, t, p;
	scanf("%i%i", &n, &d);
	allvl(12, d, 0);
	int pv = 0;
	double dv, nv;
	for(int i=1; i<=n; i++){
		scanf("%i%i", &t, &p);
		p--;
		dv = t-pv;
		for(int j:drums){
			dp[mtch[j]][i]=-1;
			if (!dr(j, p)){ continue; }
		//(double(d-nc(j, k)))	
		//	printf("%i %i %i %f ", i, j, p, dv);
			for(int k:drums){
				if (dp[mtch[j]][i]==0){ break; }
				if (dp[mtch[k]][i-1]<0){ continue; }
				nv = nc(j, k);
				if (nv==0 && dp[mtch[k]][i-1]==0){ dp[mtch[j]][i] = 0; break; }
				else if (nv == 0){ dp[mtch[j]][i] = max(dp[mtch[j]][i], dp[mtch[k]][i-1]); continue; }
				nv = dv/nv;
				if (dp[mtch[k]][i-1] == 0){ dp[mtch[j]][i] = max(dp[mtch[j]][i], nv); continue; }
				dp[mtch[j]][i] = max(dp[mtch[j]][i], min(nv, dp[mtch[k]][i-1]));
			}
		//	printf("%f\n", dp[mtch[j]][i]);
		}
		pv = t;
	}
	double mx = 0;
	for(int i:drums){
		if (dp[mtch[i]][n]==0){ mx = 0; break; }
		mx = max(mx, dp[mtch[i]][n]);
	}
	printf("%.2f", mx);

}