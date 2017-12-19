#include <stdio.h>

int main(void) {
	int x=0, t, p; 
	scanf("%d", &p);
	for(int i=0; i<p; i++){
		scanf("%d", &t);
		x^=t;
	}
	printf("%d", x);
	return 0;
}