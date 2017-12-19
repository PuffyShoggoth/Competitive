#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;
vector <pair<long long int, long long int> > people;
vector <pair<long long int, long long int> >:: iterator it;
multiset<long long int, greater<long long int> > ms;
multiset<long long int> :: iterator mit;
int main() {
	long long int n, m, t, ti, fi, st=-1;
	scanf("%lli%lli%lli", &n, &m, &t);
	for(int i=0; i<n; i++){ms.insert(0);}
	for (int i=0; i<m; i++){
		scanf("%lli%lli", &ti, &fi);
		people.push_back(make_pair(ti, fi));
	}
	sort(people.begin(), people.end());
	for (it=people.begin(); it!=people.end(); ++it){
		mit=ms.end(); --mit;
		ti=(*mit);
		if ((it->first-ti) >=t){
			st=ti; break;
		}
		if (ti>=it->first){ms.erase(mit); ms.insert(ti+it->second);}
		else{
			for(mit=ms.begin(); mit!=ms.end(); ++mit){
				if ((*mit)<=it->first){
					ms.erase(mit); ms.insert(it->first+it->second); break; 
				}
			}
		}
	}
	if (st<0){st=(*ms.rbegin());}
	printf("%lli", st);
	return 0;
}
//-_-