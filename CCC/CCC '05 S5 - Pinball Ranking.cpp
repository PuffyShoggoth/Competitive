#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int bit[100009];
int t;
vector<int> scores;
vector<pair<int, int> > srtscores;
double sm(int i){
	i-=1; double tp=0;
	for(int j=i; j>0; j-=(j&(-j))){
		tp+=bit[j];
	}
	return tp;
}
void update(int i){
	for(int j=i; j<=t; j+=(j&(-j))){
		bit[j]+=1;
	}
	return;
}
	
int main() {
	int s;
	double tt=0;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		scanf("%i", &s);
		srtscores.push_back(make_pair(s, i));
		scores.push_back(s);
	}
	if (t==0){printf("0.00");}
	else{
		sort(srtscores.begin(), srtscores.end());
		int r=1;
		scores[srtscores[srtscores.size()-1].second]=1;
		for(int i=scores.size()-2; i>=0; i--){
			if (srtscores[i].first<srtscores[i+1].first){
				r+=1;
			}
			scores[srtscores[i].second]=r;
		}
		for(int i=0; i<scores.size(); i++){
			tt+=((sm(scores[i])+1)/t);
			update(scores[i]);
		}
		printf("%.2f", tt);
	}
	return 0;
}