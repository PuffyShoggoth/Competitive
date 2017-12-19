#include <bits/stdc++.h>
using namespace std;

bool visited[105][105][105];
deque<pair<pair<int, int>, int> > moves;
pair<int, int> nxt[8] = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
int main(){
	int n;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		memset(visited, 0, sizeof(visited));
		int r, c, pr, pc, kr, kc;
		int tmoves=0; bool win=0, stale=0;
		scanf("%i%i%i%i%i%i", &r, &c, &pr, &pc, &kr, &kc);
		moves.clear();
		moves.push_back({{kr, kc}, 0});
		while(!moves.empty()){
			pair<pair<int, int>, int> tpp = moves.front();
			pair<int, int> tp = tpp.first;
			moves.pop_front();
			int cpos=pr+tpp.second;
			if (cpos == r){
				if (!stale){tmoves=tpp.second-1;}
				break;
			}
			else if (tp.first<1 || tp.first>r || tp.second<1 || tp.second>c){ continue; }
			else if (visited[tp.first][tp.second][tpp.second]){
				continue;
			}
			else{
				visited[tp.first][tp.second][tpp.second]=1;

				if (tp.first == cpos && tp.second == pc){
					
					tmoves = tpp.second; win=1; break;
				}
				else if (tp.first == cpos+1 && tp.second == pc && !stale){
					tmoves = tpp.second; stale = 1;
				}
				for(pair<int, int> j: nxt){
					moves.push_back({{tp.first+j.first, tp.second+j.second}, tpp.second+1});
				}
			}
		}
		if (win){
			printf("Win in %i knight move(s).\n", tmoves);
		}
		else if (stale){
			printf("Stalemate in %i knight move(s).\n", tmoves);
		}
		else{
			printf("Loss in %i knight move(s).\n", tmoves);
		}

	}
}