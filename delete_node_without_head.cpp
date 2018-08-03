#include <bits/stdc++.h>

using namespace std;

struct list1{
	int val;
	list1* next;
};

list1* root;

void insert(int new_val){

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

void delete_val(int del) {

	list1* temp = new list1;
	temp=root;

	while(temp->next != NULL){
		if(temp->val ==del)
			break;
		else
			temp=temp->next;
	}

	list1* del_ptr = temp;
	
	if(del_ptr)
		cout << del_ptr->val << endl;
	//GOT NODE TO BE DELETED

	while(del_ptr->next){
		del_ptr->val = del_ptr->next->val;
		del_ptr=del_ptr->next;
	
		// cout << del_ptr->val << endl;
	}

	del_ptr= NULL;




	// 1-2-3-4

}


int main() {
	int q;
	cin >> q;
	while(q) {
		int a;
		cin >> a;
		insert(a);

		q--; 
	}
	print();


	int b;
	cin >> b;
	
	delete_val(b);


	print();
}