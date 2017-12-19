#include <iostream>
#include <cmath>
using namespace std;
void faktorizor(long long int x, int y){
    if (x==1){return;}
    int h=sqrt(x)+1;
    for (int i=y; i<=h; i++){
        if (x%i==0){
            cout<<i<<"\n";
            faktorizor(x/i, i);
            return;}
    }
    cout<<x<<"\n";
    return;}
int main()
{
  long long int f;
  cin>>f;
  if (f!=1){faktorizor(f, 2);}
  return 0;
}