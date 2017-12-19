# include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin>>a>>b;
    d=0;
    for (int n=a; n<=b; n++){
        c=0;
        for (int m=1; m<=n; m++){
            if (n%m==0)
                c++;
        }
        if (c==4){
           d++; 
        }
    }
    cout<<"The number of RSA numbers between "<<a<<" and "<<b<<" is "<<d;
    return 0;
}
