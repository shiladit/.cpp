#include<bits/stdc++.h>

using namespace std;

int count_leaves = 0;

struct btree {
	int val;
	btree* left;
	btree* right;
};

btree* root;

btree* insert(int new_val) {
	btree* temp = new btree;
	temp->val = new_val;
	temp->left = temp->right = NULL;

	return temp;
}

void find_leaves(btree* temp){

	if(temp == NULL)
		return;

	if(temp->left == NULL && temp->right == NULL){
		++count_leaves;
		return ;
	}

	find_leaves(temp->left);
	find_leaves(temp->right);

	
}

int main() {
	
	root = insert(14);
	root->left = insert(5);
	root->left->left = insert(2);
	root->right = insert(7);
	root->right->left = insert(9);
	root->right->right = insert(10);


	btree* temp =root;

	find_leaves(temp);

	cout << count_leaves << endl;

}