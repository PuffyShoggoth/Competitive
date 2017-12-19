#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int fl[2005];
vector <int> adl[2005];
queue <int> s;
int main()
{
    int n, m, a, b, x, y, l=0, f;
    cin>>n>>m>>a>>b;
    for (int i=0; i<m; i++){
        cin>>x>>y;
        adl[x].push_back(y);
        adl[y].push_back(x);
    }
    s.push(a);
    while (s.size()>0){
        f=s.front();
        s.pop();
        if (f==b){
            l+=1;
            break;}
        for (int i=0; i<adl[f].size(); i++){
            if (fl[adl[f][i]]!=1){
                fl[adl[f][i]]=1;
                s.push(adl[f][i]);}
        }
    }
    if (l==1){ cout<<"GO SHAHIR!";}
    else{cout<<"NO SHAHIR!";}
    return 0; 
}