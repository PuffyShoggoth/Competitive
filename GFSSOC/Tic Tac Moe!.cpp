#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char board[3][3];
bool checkwins(bool pl){
	for(int i=0; i<3; i++){
		if(board[i][0]==pl && board[i][1]==pl && board[i][2]==pl){return 1;}
		if(board[0][i]==pl && board[1][i]==pl && board[2][i]==pl){return 1;}
	}
	if (board[0][0]==pl && board[1][1]==pl && board[2][2]==pl){return 1;}
	if (board[0][2]==pl && board[1][1]==pl && board[2][0]==pl){return 1;}
	return 0;
}
int main() {
	memset(board, 0, 9);
	char temp;
	bool x, o;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			do{scanf("%c", &temp);} while(temp=='\n');
			if (temp=='X'){board[i][j]=1;}
			else{board[i][j]=0;}
		}
	}
	x=checkwins(1);
	o=checkwins(0);
	if (x && o){printf("%s", "Error, redo");}
	else if (x){printf("%s", "Timothy");}
	else if (o){printf("%s", "Griffy");}
	else{printf("%s", "Tie");}
	return 0;
}