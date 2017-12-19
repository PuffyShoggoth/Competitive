#include <cstdio>
#include <utility>
#include <map>
#define max(a,b) (a<b)?b:a
using namespace std;
int tmp[200000], nxtfree=1;
struct nde{
	int next, curr;
	void nwnde(int n, int c){
		next=n; curr=c;	
	} 
};
struct room{
	int cyc=0, fvst=0, lvst=0, max=0; 
};
nde nodes[401000];
room rooms[100010];
map<pair<int, int>, pair<int, pair<int, int> > > heads, tails;
map<pair<int, int>, pair<int, pair<int, int> > > :: iterator it, itb;
void mrge(pair<int, int> head, pair<int, int> tail){
	it=heads.find(head); itb=tails.find(tail);
	if (it->second.second==itb->first){tails.erase(itb); return;}
	heads[itb->second.second].second=it->second.second;
	tails[it->second.second].second=itb->second.second;
	nodes[itb->second.first].next=it->second.first;
	heads.erase(it); tails.erase(itb);
	return;
}
void exend(pair<int, int> tail, pair<int, int> nw){
	it=tails.find(tail);
	nodes[it->second.first].next=nxtfree;
	nodes[nxtfree].nwnde(0, nw.second);
	tails[nw]=make_pair(nxtfree, it->second.second);
	heads[it->second.second].second=nw;
	tails.erase(it);
	nxtfree+=1;
	return;
}
void exstrt(pair<int, int> head, pair<int, int> nw){
	it=heads.find(head);
	nodes[nxtfree].nwnde(it->second.first, nw.second);
	heads[nw]=make_pair(nxtfree, it->second.second);
	tails[it->second.second].second=nw;
	heads.erase(it);
	nxtfree+=1;
	return;
}
void addnw(pair<int, int> head, pair<int, int> tail){
	nodes[nxtfree].nwnde(nxtfree+1, head.second);
	nodes[nxtfree+1].nwnde(0, tail.second);
	heads[head]=make_pair(nxtfree, tail);
	tails[tail]=make_pair(nxtfree+1, head);
	nxtfree+=2;
	return;
}
int main() {
	int n, k, q, itmp, currcyc=0;
	room* rmtmp;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%i", &k);
		for(int j=0; j<k; j++){
			scanf("%i", &tmp[j]);
		}
		for(int j=1; j<=k; j++){
			if (tmp[j%k]<i){
				if (tmp[j-1]<i){mrge(make_pair(i, tmp[j-1]), make_pair(tmp[j%k], i));}
				else{exend(make_pair(tmp[j%k], i), make_pair(i, tmp[j-1]));}
			}
			else{
				if (tmp[j-1]<i){exstrt(make_pair(i, tmp[j-1]), make_pair(tmp[j%k], i));}
				else{addnw(make_pair(tmp[j%k], i), make_pair(i, tmp[j-1]));}
			}
		}
	}
	tmp[0]=0;
	for(it=heads.begin(); it!=heads.end(); ++it){
		itmp=it->second.first;
		currcyc+=1;
		tmp[currcyc]=0;
		while(itmp!=0){
			tmp[currcyc]+=1;
			rmtmp=&rooms[nodes[itmp].curr];
			if (rmtmp->cyc!=currcyc){
				rmtmp->max=max(rmtmp->max, tmp[rmtmp->cyc]-rmtmp->lvst+rmtmp->fvst);
				rmtmp->cyc=currcyc;
				rmtmp->fvst=tmp[currcyc];
				rmtmp->lvst=tmp[currcyc];
			}
			else{
				rmtmp->max=max(rmtmp->max, tmp[currcyc]-rmtmp->lvst);
				rmtmp->lvst=tmp[currcyc];
			}

			itmp=nodes[itmp].next;
		}
	}
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i", &itmp);
		printf("%i\n", max(rooms[itmp].max, tmp[rooms[itmp].cyc]-rooms[itmp].lvst+rooms[itmp].fvst));
	}
	return 0;
}