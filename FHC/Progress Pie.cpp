#include <cstdio>
#include <cmath>
using namespace std;
#define PI 3.14159265
int main() {
	int t, p, x, y;
	double dbp, tpd;
	bool bl;
	scanf("%i", &t);
	for(int donotuse=1; donotuse<=t; donotuse++){
		scanf("%i%i%i", &p, &x, &y);
		dbp=100.0;
		dbp=(p/dbp)*360.0;
		if (((x-50)*(x-50)+(y-50)*(y-50))>2500) bl=0;
		else{
			
			if (x==50){
				if ((y>=50 && p>0) || p>=50){ bl=1;}
				else{ bl=0;}
			}
			else if (y==50){
				if ((x>50 && p>=25 )|| p>=75) {bl=1;}
				else {bl=0;}
			}
			else{
				if (x>50 && y>50){
					tpd=atan((x-50)/((double)(y-50)))*180.0/PI;
				}
				else if (x>50){
					tpd=atan((50-y)/((double)(x-50)))*180.0/PI+90.0;
				}
				else if (y<50){
					tpd=atan((50-x)/((double)(50-y)))*180.0/PI+180.0;
				}
				else{
					tpd=atan((y-50)/((double)(50-x)))*180.0/PI+270.0;
				}
				if (dbp>=tpd){ bl=1;}
				else{bl=0;}
			}
		}
		if (!bl){ printf("Case #%i: white\n", donotuse);}
		else{printf("Case #%i: black\n", donotuse);}
	}
	return 0;
}