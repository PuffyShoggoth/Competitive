#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char p[1000009];
void rev(long long int h){
    for (int i=0; i<h/2+h%2; i++){
        cout<<p[i];}
    for (int i=h/2-1; i>=0; i--){
        cout<<p[i];}
    return;
}
void ad(long long int h){
	char k;
	char f='9';
    for (int q=h/2+h%2-1; q>=0; q--){
        k=p[q];
        if (k!=f){p[q]+=1; rev(h); return;}
        p[q]=0;}
    cout<<1;
    for (int i=1; i<h; i++){
        cout<<0;}
    cout<<1;
    return;}
void gl(long long int h){
	if (p[h/2-1]<p[h/2+h%2]){ad(h); return;}
	if (p[h/2-1]>p[h/2+h%2]+1){rev(h); return;}
	int c=1;
    for (int i=0; i<=h/2; i++){
        if (p[h-i-1]+c>p[i]){
        	c=1;
        }
        else{c=0;}
    }
    if (c==1){ad(h);}
    else{rev(h);}
    return;
}
int main()
{
  cin>>p;
  long long int h=strlen(p);
  gl(h);
  return 0;
}