#include <iostream>
#include <queue>
#include <utility>
using namespace std;
queue<pair<int, int> >c; 
int squares[9][9];
void jump(int x, int y, int i, int ox){
    if (y-i>0 && squares[x][y-i]==0){
             squares[x][y-i]=squares[ox][y]+1;
             c.push(make_pair(x, y-i));}
    if (y+i<9 && squares[x][y+i]==0){
             squares[x][y+i]=squares[ox][y]+1;
             c.push(make_pair(x, y+i));}
    return;
}         

int main(){
 int sx, sy, tx, ty;
 pair<int, int> h;
 cin>>sx>>sy>>tx>>ty;
 c.push(make_pair(sx, sy));
 squares[sx][sy]=1;
 while (c.size()>0){
     h=c.front();
     c.pop();
     if (h.first==tx && h.second==ty){
         cout<<squares[tx][ty]-1;
         break;}
     if (h.first+1<9){
         jump(h.first+1, h.second, 2, h.first);
         if (h.first+2<9){
             jump(h.first+2, h.second, 1, h.first);}}
     if (h.first-1>0){
         jump(h.first-1, h.second, 2, h.first);
         if (h.first-2>0){
             jump(h.first-2, h.second, 1, h.first);}}
 }
 return 0;
     
     
         
}