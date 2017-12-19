#include <bits/stdc++.h>
using namespace std;
int bit[100005];
int n;
int sum(int ind){
	int sm=0;
	for(int i=ind; i>0;i-=(i&-i)){
		sm+=bit[i];
	}
	return sm;
}
void update(int ind){
	for(int i=ind; i<=n; i+=(i&-i)){
		bit[i]++;
	}
}
bool func(pair<long long int, long long int> a, pair<long long int, long long int> b){
	return (a.second-a.first)<(b.second-b.first);
}
bool nb[100005], ne[100005];
vector<pair<long long int, long long int> > st;
int main(){
	int m;
	long long int a, b, ct=0;
	scanf("%i%i%lli%lli", &n, &m, &a, &b);
	for(int i=0; i<m; i++){
		getchar();
		long long int rw=0;
		char tp=getchar();
		do{rw=rw*10+tp-'0'; tp=getchar(); }while(tp>='0' && tp<='9');
	//	printf("%i %c\n", rw, tp);
		if (tp=='C' || tp == 'D'){
			update(rw);
		}
		else if (tp=='A'){
			ct+=a*(1-nb[rw]);
		}
		else if (tp=='F'){
			ct+=a*(1-ne[rw]);
		}
		else if (tp=='B'){
			nb[rw]=1;
		}
		else if (tp=='E'){
			ne[rw]=1;
		}
		long long int f=rw*2-sum(rw), ba=(n+1-rw)*2-(sum(n)-sum(rw-1));
		st.push_back({f, ba});
	}
//	printf("%i %i", a, b);
	sort(st.begin(), st.end(), func);
	long long int mn=0;
	for(int i=0; i<st.size(); i++){
//		printf("%i %i\n", st[i].first, st[i].second);
		mn+=b*i+a*st[i].second;
	}
//	printf("%lli", mn+ct);
	long long int fmn=mn;
	//long long int itp;
	for(long long int i=st.size()-1; i>=0; i--){
		long long int itp = mn-b*(2*i-st.size()+1)-a*(st[i].second-st[i].first);
		if (itp<fmn){ fmn=itp; }
		mn = itp;
	}
	printf("%lli", fmn+ct);
}