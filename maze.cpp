//Sadie Jungers
//maze program
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

const int SIZE=10;
char maze[SIZE][SIZE];
void getboard();
int rloc=0,cloc=0;//current coordinates in maze
void printboard();
bool move(int,int);
bool done();

int main(){
	getboard();
	printboard();
	move(rloc,cloc);
	cout << endl;
	printboard();
	return 0;
}

bool move(int r,int c){
	maze[r][c]='*';
	if(done()){ 
		return true;
	} 
	///move down
	if(maze[r+1][c]!='1' && maze[r+1][c]!='*' && r+1<SIZE){
			rloc=r;
			cloc=c;
			move(rloc+1,cloc);
	}
	///move right
	else if(maze[r][c+1]!='1' && maze[r][c+1]!='*' && c+1<SIZE){
			rloc=r;
			cloc=c;
			move(rloc,cloc+1);
	} 
	///move left
	else if(maze[r][c-1]!='1' && maze[r][c-1]!='*' && c-1>=0){
		rloc=r;
		cloc=c;
		move(rloc,cloc-1);
	}
	///move up
	else if(maze[r-1][c]!='1' && maze[r-1][c]!='*' && r-1>=0){
		rloc=r;
		cloc=c;
		move(rloc-1,cloc);
	}
	else {
		maze[rloc][cloc]='0';
		return false;
	}
}

void getboard(){
	ifstream ff;
	string file;
	int a,b;
	cout << "This program is designed to traverse a 10x10 maze.\n";
	cout << "The input file must not have spaces or newlines.\n";
	cout << "Please input the file name of the maze: ";
	cin >> file;
	ff.open(file.c_str());
	for(a=0;a<SIZE;a++){
		for(b=0;b<SIZE;b++){
			maze[a][b]=ff.get(); 
		}
	}
}

void printboard(){
	int j,k;
	for(j=0;j<SIZE;j++){
		for(k=0;k<SIZE;k++){
			cout << setw(2) << maze[j][k];
		}
		cout << endl;
	}
}

bool done(){
	if(rloc==SIZE-1 && cloc==SIZE-1){
		maze[rloc][cloc]='*';
		return true;
	} else {
		return false;
	}
}
