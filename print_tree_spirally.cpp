#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};


node* root;

node* newNode(int val){
	node* temp = new node;
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

void print_spiral(node* root){
	stack <node*> stk1;
	stack <node*> stk2;

	stk1.push(root);

	while(!stk1.empty() || !stk2.empty()){

		while(!stk1.empty()){
			node* temp = stk1.top();
			stk1.pop();
			cout << temp->data << " ";

			if(temp->right)
				stk2.push(temp->right);
			if(temp->left)
				stk2.push(temp->left);
		}

		while(!stk2.empty()){
			node* temp = stk2.top();
			stk2.pop();

			cout << temp->data << " ";
			if(temp->left)
				stk1.push(temp->left);
			if(temp->right)
				stk1.push(temp->right);
		}

	}

	cout << endl;
}

int main() {

	root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left  = newNode(5); 
    root->right->right = newNode(4); 

    print_spiral(root);
}