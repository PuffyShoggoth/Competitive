#include <iostream>

int pi[255][130][255];
using namespace std;

int pizza(int pie, int people);
int pizza(int pie, int people)
{
    
    for (int i=1; i<=pie/people; i++){
        pi[1][i][i]=1; }
    for (int i=2; i<people; i++){
        for (int j=1; j<=pie/2; j++){
            for (int prev=1; prev<=j; prev++){
                for (int used=i-2+prev; used<=min((i-1)*prev, pie-j*(people-i+1)); used++){
                            
                            pi[i][j][used+j]+=pi[i-1][prev][used];
                }
            }
        }
    }
    int total=0;
    for (int j=1; j<=pie/2; j++){
                for (int p=people-1; p<=pie-pie/people; p++){
                            total+=pi[people-1][j][p];
                }
    }

    return total;
    
}
int main(){
    int pie, people;
    cin>>pie;
    cin>>people;
    if (people==1){
        cout<<1;}
    else{
        cout<<pizza(pie, people);}
    return 0;
    }