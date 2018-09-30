#include <iostream>

using namespace std;

void push(int* stk,int* top,int val){

	if(*top == -1){
		stk[0] = val;
		*top = 1;
	}
	else{
		stk[*top] = val;
		++*top;
	}
}

void pop(int* stk,int* top){

	--*top;
}

int peek(int* stk,int* top){

	return stk[*top-1]; //Always look at one element to the less of top
}

int main() {

	int stk[100];
	int top = -1;

	for(int i=0;i<10;i++)
		push(&stk[0],&top,i*10+1);


	pop(&stk[0],&top);

	cout << peek(&stk[0],&top) << "\n";
}