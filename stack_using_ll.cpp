#include<bits/stdc++.h>

using namespace std;

struct list1{
	int val;
	list1* next;
};

list1* root;

void push(int new_val){

	if(root == NULL){
		list1* temp2 = new list1;
		temp2->val = new_val;
		temp2->next = NULL;
		root=temp2;
		// cout << "Hi" << endl;
	}

	else {
	list1* temp=root;
	while(temp->next != NULL){
		temp=temp->next;
	}

	list1* temp1 = new list1;
	temp1->val = new_val;
	temp1->next = NULL;
	temp->next = temp1;	
   }
}

void print() {
	list1* temp=root;

	while(temp !=NULL){
		cout << temp->val << "-->";
		temp=temp->next;
	}

	cout << endl;
}

int pop() {
	list1* back= NULL;
	list1* fwd = NULL;

	if(root == NULL) {
		cout << "Stack Empty\n";
		return -1;
	}
	else
		back = root;

	if(root->next != NULL)
		 fwd = root->next;
	
	if(fwd == NULL){
		int a = back->val;
		back = NULL;
		root=NULL;
		return a;
	}

	while(fwd->next != NULL){
		back= back->next;
		fwd= fwd->next;
	}
	back->next = NULL;
	return fwd->val;

}

void top() {
	list1* temp = root;
	if(temp ==NULL) {
		cout << "Stack is Empty\n";
		return; 
	}
	else{
		while(temp->next !=NULL)
			temp=temp->next;
	}

	cout << "Top: " << temp->val << endl;

}

int main() {
	push(4); cout << "Pushed !!" << endl;
	push(5); cout << "Pushed !!" << endl;
	push(10); cout << "Pushed !!" << endl;
	cout << "\nPrinting stack trace: " ; print();
	cout <<  "\nPopped: " << pop() << endl;
	cout <<  "\nPopped: " << pop() << endl;
	cout <<  "\nPopped: " << pop() << endl;
	
	cout << "\nPrinting stack trace: "; print();
	push(22); cout << "Pushed !!" << endl;

	// print();
	top();
}