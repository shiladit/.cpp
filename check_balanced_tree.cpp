#include <bits/stdc++.h>

using namespace std;

struct tree{
	int data;
	tree* left;
	tree* right;
};


tree* root;


tree* new_node(int val){
	tree* temp = new tree;
	temp->data = val;
	temp->left = temp->right = NULL;

	return temp;
}

int height_max(tree* temp){

	if(temp == NULL)
		return 0;

	else if(temp->left == NULL && temp->right == NULL)
		return 0;

	else return max(1+height_max(temp->left),1+height_max(temp->right));
}



int height_min(tree* temp){

	if(temp == NULL)
		return 0;

	else if(temp->left == NULL && temp->right == NULL)
		return 0;

	else return min(1+height_min(temp->left),1+height_min(temp->right));
}

int main(){

	root = new_node(4);
	root->left = new_node(3);
	root->left->right = new_node(5);
	root->left->left = new_node(6);
	root->left->left->left = new_node(7);
	root->left->left->left->left = new_node(10);
	root->right = new_node(11);
	root->right->right = new_node(12);
	root->right->left = new_node(13);
	root->right->right->right = new_node(14);

	if(abs(height_max(root)-height_min(root)) > 1)
		cout << "NOT BALANCED\n";
	else
		cout << "BALANCED\n";

}