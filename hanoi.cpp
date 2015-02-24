//Sadie Jungers
//towers of hanoi
#include <iostream>
#include "stackclass.h"
#include <iomanip>
using namespace std;

void animate();
void towers(int,sstack<char>&,sstack<char>&,sstack<char>&);
void print(int);
sstack<char> A,B,C;

int main(){
	int n,i;
	cout << "How many disks should we use? ";
	cin >> n;
	for(i=n-1;i>=0;i--){
		A.push(i+97);
	}
	towers(n,A,B,C);
}

void towers(int n, sstack<char>& start, sstack<char>& tmp, sstack<char>& dest){
	if(n==1){
		dest.push(start.pop());
		print(n);
		return;
	}
	towers(n-1,start,dest,tmp);
	dest.push(start.pop());
	print(n);
	towers(n-1,tmp,start,dest);
}

void print(int n){
	sstack<char> temp1,temp2,temp3;
	//cout << "N = " << n;
	cout << endl << "A: ";
	while(!A.empty()) {
		temp1.push(A.pop());
	}
	while(!temp1.empty()){
		cout << temp1.peek();
		A.push(temp1.pop());
	}
	cout << endl << "B: ";
	while(!B.empty()){
		temp2.push(B.pop());
	}
	while(!temp2.empty()){
		cout << temp2.peek();
		B.push(temp2.pop());
	}
	cout << endl << "C: ";
	while(!C.empty()){
		temp3.push(C.pop());
	}
	while(!temp3.empty()){
		cout << temp3.peek();
		C.push(temp3.pop());
	} 
	cout << endl;
