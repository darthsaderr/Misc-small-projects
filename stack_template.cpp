//Sadie Jungers
//stack class header 
#include <iostream>
using namespace std;

const int MAX=30;
template<class T>
class sstack{
	public:
		sstack();
		T pop();
		void push(const T&);
		bool empty();
		T peek();
		void printstack();
	private:
		T stack[MAX];
		T *sp;
};

////////////////////constructor
template <class T>
sstack<T>::sstack(){
	sp=stack;
}
///////////////////pop element off stack
template <class T>
T sstack<T>::pop(){
	sp--;
	return *sp;
}
///////////////////////////////push element onto stack
template <class T>
void sstack<T>::push(const T& thing){
	*sp++=thing;
	return;
}
////////////////////////check to see if stack is empty
template <class T>
bool sstack<T>::empty(){
	if(sp==stack) return true;
	else return false;
}
//////////////////peek at top element of stack
template <class T>
T sstack<T>::peek(){
	return *(sp-1);
}
/////////////////print out the whole stack
/*template<class T>
T sstack<T>::printstack(){
	sstack<T> temp=
}*/
