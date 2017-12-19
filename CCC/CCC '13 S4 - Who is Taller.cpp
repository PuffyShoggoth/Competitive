#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> h[1000008];
int p[1000008];
queue <int> f;
queue <int> ww;
int tl(int y, queue <int> g){
    int k;
    while (g.size()>0){
        k=g.front();
        if (k==y){return 1;}
        g.pop();
        for (int i=0; i<h[k].size(); i++){
            if (p[h[k][i]]==0){
                g.push(h[k][i]);
                p[h[k][i]]=1;}}
    }
    return 0;}
int main(){
 int n, m, t, s, fp, sp, q=0, qs=0;
 cin>>n>>m;
 for (int i=0; i<m; i++){
     scanf("%i", &t);
     scanf("%i", &s);
     h[t].push_back(s);}
 scanf("%i", &fp);
 scanf("%i", &sp);
 f.push(fp);
 ww.push(sp);
 q=tl(sp, f);
 if (q==1){cout<<"yes";}
 else{ qs=tl(fp, ww);
 if (qs==1){cout<<"no";}
 else{cout<<"unknown";}}
 return 0;
 
 
 
}