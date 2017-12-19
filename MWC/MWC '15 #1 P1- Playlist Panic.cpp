#include <cstdio>
#include <algorithm>
using namespace std;
int songs[1005];
int main() {
	int n, min, sec, tms, used=0, tt=0;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i%i", &min, &sec);
		songs[i]=min*60+sec;
	}
	sort(songs, songs+n);
	scanf("%i%i", &min, &sec);
	tms=min*60+sec;
	for (int i=0; i<n; i++){
		if (used+songs[i]<=tms){
			used+=songs[i];
			tt+=1;}
		else{break;}
	}
	printf("%i", tt);
	return 0;
}