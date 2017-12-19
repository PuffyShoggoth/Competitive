#include <cstdio>
using namespace std;
struct node{int open, unfit;}tr[262200];
int bins[100009];
bool fhalf[100009];
int pos[100009];
void updatenode(int i){
	tr[i].unfit=tr[(i<<1)+1].unfit+tr[i<<1].unfit;
    tr[i].open=tr[(i<<1)+1].open+tr[i<<1].open;
    if (tr[i<<1].unfit<=tr[(i<<1)+1].open){
            tr[i].unfit-=tr[i<<1].unfit;
            tr[i].open-=tr[i<<1].unfit;
    }
    else{
            tr[i].unfit-=tr[(i<<1)+1].open;
            tr[i].open-=tr[(i<<1)+1].open;
    }
    
}
void build(int i, int s, int e){
    if (s==e){
        pos[s]=i;
        if(fhalf[s]){
            tr[i].open=1;
            tr[i].unfit=0;
            }
        else{
            tr[i].unfit=1;
            tr[i].open=0;
            }
        return;
    }
    else{
        build(i<<1, s, (s+e)>>1);
        build((i<<1)+1, ((s+e)>>1)+1, e);
        updatenode(i);
        return;
    }
}
void update(int pos){
   pos=pos>>1;
   while (pos>0){
   	updatenode(pos);
   	pos=pos>>1;
   }
   return;
}
int main() {
    int n, pf;
    scanf("%i", &n);
    pf=n>>1;
    for (int i=0; i<n; i++){
        scanf("%i", &bins[i]);
    }
    for (int i=0; i<n/2; i++){
        fhalf[bins[i]]=1;
    }
    build(1, 1, n);
    for(int i=0; i<n; i++){
    }
    while ((tr[1].open!=0 || tr[1].unfit!=0) && pf>0){
    	pf-=1;
        tr[pos[bins[(pf<<1)]]].unfit=0;
        tr[pos[bins[(pf<<1)+1]]].unfit=0;
        tr[pos[bins[pf]]].open=0;
        tr[pos[bins[pf]]].unfit=1;
        update(pos[bins[pf<<1]]);
        update(pos[bins[(pf<<1)+1]]);
        update(pos[bins[pf]]);
    }
    printf("%i", pf);
    return 0;
}