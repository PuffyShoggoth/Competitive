#include <bits/stdc++.h>
using namespace std;
set <int> classes[505];
vector<int> period[505];
bool gclass[505];
map<int, int > students;
int main() {
	int n, p, s, id, idn, idg, cwg=-1;
	scanf("%i", &n);
	scanf("%i%i", &idn, &idg);
	for(int i=0; i<n; i++){
		scanf("%i%i", &p, &s);
		period[p].push_back(i);
		for(int j=0; j<s; j++){
			scanf("%i", &id); 
			if (id==idg){gclass[i]=1;}
			classes[i].insert(id);
		}
	}
	students[idn]=0;
	for(int j=1; j<=500; j++){
		for(int k=0; k<period[j].size(); k++){
		int i=period[j][k];
		int mn = -1;
		for(set<int> :: iterator it = classes[i].begin(); it!= classes[i].end(); ++it){
			if (students.find(*it)==students.end()){continue;}
			else if (mn==-1 || students[*it]+1<mn) mn = students[*it]+1;
		}
		if (mn<0) continue;
		for(set<int> :: iterator it = classes[i].begin(); it!= classes[i].end(); ++it){
			 if (students.find(*it)==students.end() || students[*it]>mn){
				students[*it]=mn;
				if (*it==idg){cwg=j;}
			} 
		}
		}
	}
	if (students.find(idg)==students.end()){printf("delivery failure");}
	else{ printf("%i\n%i\n", students[idg], cwg);}
}