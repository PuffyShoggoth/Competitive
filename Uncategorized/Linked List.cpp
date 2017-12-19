#include <stdio.h>
using namespace std;

const unsigned long long int longone=1;
const unsigned long long int sign=(longone<<43);
const unsigned long long int onbits=((longone<<44)-1);

unsigned long long int convert(long long int number){
		if (number<0){return (-number)|sign;}
		else{return number;}
}

long long int convertb(unsigned long long int number){
		if (number&sign){return -(number&(~sign));}
		else{return number;}
}

unsigned long long int address(unsigned long long int contents){
		return contents>>44;
}

unsigned long long int value(unsigned long long int contents){
		return contents&onbits;
}

unsigned long long int combine(unsigned long long int varaddress, unsigned long long int contents){
		return (varaddress<<44)|contents;
}

unsigned long long int linkedlist[1000001];
	
int main() {
	long long int m, curr=1000000, nextmemory=0, n, inttmp, addholder, prev=1000000, next=1000000;
	char temp;
	for(int i=0; i<1000000; i++){
		linkedlist[i]=i+1;
	}
	scanf("%lld", &m);
	for (unsigned long long int i=0; i<m; i++){
		do{scanf("%c", &temp);}
		while(temp==' ' || temp=='\n');
		if(temp=='+'){
			scanf("%lld", &n);
			inttmp=linkedlist[nextmemory];
			addholder=address(linkedlist[curr]);
			linkedlist[nextmemory]=combine(curr^addholder^next, convert(n));
			linkedlist[addholder^next]=combine(nextmemory^curr^address(linkedlist[addholder^next]), value(linkedlist[addholder^next]));
			linkedlist[curr]=combine(addholder^prev^nextmemory, value(linkedlist[curr]));
			next=curr;
			curr=nextmemory;
			prev=address(linkedlist[curr])^next;
			nextmemory=inttmp;
		}
		else if(temp=='='){
			scanf("%lld", &n);
			linkedlist[curr]=combine(address(linkedlist[curr]), convert(n));
		}
		else if(temp=='<'){
			next=curr;
			curr=prev;
			prev=address(linkedlist[curr])^next;
		}
		else if(temp=='>'){
			prev=curr;
			curr=next;
			next=address(linkedlist[curr])^prev;
		}
		else if(temp=='-'){
			addholder=address(linkedlist[next]);
			linkedlist[prev]=combine(address(linkedlist[prev])^curr^next, value(linkedlist[prev]));
			linkedlist[next]=combine(address(linkedlist[next])^curr^prev, value(linkedlist[next]));
			inttmp=nextmemory;
			nextmemory=curr;
			curr=next;
			next=addholder^nextmemory;
			linkedlist[nextmemory]=inttmp;
		}
		else if(temp=='!'){
		printf("%lld\n", convertb(value(linkedlist[curr])), curr);
		
		}
	}
	return 0;
}
//Bugs, bugs, bugs