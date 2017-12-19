#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    if (a+b+c-max(a,(max(b,c)))>max(a, max(b, c))){
        cout<<"Huh? A triangle?";
    }
    else{
        cout<<"Maybe I should go out to sea...";
    }
}