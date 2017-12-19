#include <vector>
#include <cstdio>
using namespace std;
vector<int> options;
vector<int> val;
vector<int> tmp;
vector<int> rev;


int main() {
	int r, c, m, u, v, sm=0;
	scanf("%i%i", &r, &c);
	rev.push_back((1<<c)-1);
	c-=1;
	options.push_back(0);
	val.push_back(1);
	for(int i=1; i<c; i++){
		m=(1<<i);
		u=(~m);
		u&=(~(m>>1));
		u&=(~(m<<1));
		v=options.size();
		for(int i=0; i<v; i++){
			if ((rev[i]|(~u))==rev[i]){
				options.push_back(m+options[i]);
				val.push_back(1);
				rev.push_back(rev[i]&u);
			}
		}
	}
	for(int i=2; i<r; i++){
		tmp.assign(val.size(), 0);
		for(int j=0; j<options.size(); j++){
			for(int k=0; k<options.size(); k++){
				if ((rev[j]&options[k])==options[k]){
					tmp[k]=(val[j]+tmp[k])%1000000007;
				}
			}
		}
		val.swap(tmp);
	}
	for(int i=0; i<val.size(); i++){
		sm= (sm+val[i])%1000000007;
	}
	sm-=1;
	printf("%i", sm);
	
	
	return 0;
}