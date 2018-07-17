#include<bits/stdc++.h>

using namespace std;

struct node{
	int val;
	struct node* next;
};

node* root;

void insert(int x){
	if(!root){
		node* temp= new node;
		temp->val = x;
		temp->next=NULL;
		root= temp;
	}
	else
	{
		node* temp = root;
		while(temp->next !=NULL){
			temp=temp->next;
		}
		node* temp1 = new node;
		temp1->val = x;
		temp1->next = NULL;
		temp->next = temp1;

	}
}

void rotate_through_K(int k){
	int count =1;

	node* cur = root;
	while(count != k){
		cur=cur->next;
		++count;
	}
	
	node* cur2 = cur->next;
	node* cur1 = cur->next;

	while(cur1->next != NULL)
		cur1 = cur1->next;
	
	cur->next = NULL;
	cur1->next = root;
	root = cur2;

}

void print_ll(){
	node* temp = root;
	while(temp != NULL){
		cout << temp->val << " --> ";
		temp= temp->next;
	}
	cout << endl;
}

int main() {
	int size,x;
	cin >> size;

	while(size){
		cin >> x;
		insert(x);
		--size;
	}
	int k;
	cin >> k;

	//print_ll();

	if( k>0 && k<size)
		rotate_through_K(k);
	else ;

	print_ll();

}