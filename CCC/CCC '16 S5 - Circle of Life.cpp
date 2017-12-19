#include <cstdio>
#include <cstring>
using namespace std;
bool cells[2][100005];

int main() {
	int n;
	long long int t;
	scanf("%i%lli", &n, &t);
	getchar();
	for(int i=0; i<n; i++){
		cells[0][i]=(getchar()=='1');
	}
	int crr=0, nxt, i=0;
	while(t>0){
		if (t&1){
			nxt=(crr+1)%2;
			memset(cells[nxt], 0, sizeof(cells[nxt]));
			for(int j=0; j<n; j++){
				if (!cells[crr][j]) continue;
				cells[nxt][(((j-(1LL<<i))%n)+n)%n]^=1;
				cells[nxt][(j+(1LL<<i))%n]^=1;
			}
			crr=nxt;
		}
		t>>=1;
		i++;
	}
	for(int i=0; i<n; i++){
		if (cells[crr][i]) putchar('1');
		else putchar('0');
	}
	return 0;
}