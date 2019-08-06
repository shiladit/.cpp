#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	node* nextright;
};


node* root;

node* nn(int val){
	node* temp = new node;
	temp->data = val;
	temp->left = temp ->right = temp->nextright = NULL;

	return temp;
}

void connect(){

	queue <node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* p = q.front();
		q.pop();

		if(p != NULL){
			p->nextright = q.front();

			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);

		}
		else if(!q.empty())
				q.push(NULL);
	}
}

void print_nodes(node* temp) {

	if(temp)
		cout << temp->data << " ";

	if(temp->nextright)
		print_nodes(temp->nextright);

	if(temp->left)
		print_nodes(temp->left);

}


int main() {

	root = nn(1);
	root->left = nn(2);
	root->right = nn(3);
	root->left->left = nn(7);
	root->left->right = nn(8);
	root->right->right = nn(11);

	connect();

	node* temp = root;
	print_nodes(temp);
}