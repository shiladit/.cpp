#include<bits/stdc++.h>

using namespace std;

struct bnode {
	int val;
	bnode* left;
	bnode* right;
};

bnode* root;

int min_depth = INT_MAX;

bnode* new_node(int new_val){
	bnode* temp = new bnode;
	temp->val = new_val;
	temp->left = temp->right = NULL;

	return temp;
}

void preorder(bnode* temp){

	cout << temp->val << " ";

	if(temp->left == NULL && temp->right == NULL)
		return;

	if(temp->left)
		preorder(temp->left);
	if(temp->right)
		preorder(temp->right);

}

int find_path_sum(bnode* temp,int sum,int depth){

	if(sum - temp->val == 0 && (temp->left== NULL && temp->right == NULL)){
		// cout << "YES\n";
		if(depth < min_depth)
			min_depth = depth;
	}

	if(temp->left)
		find_path_sum(temp->left,sum-temp->val,depth+1);

	if(temp->right)
		find_path_sum(temp->right,sum-temp->val,depth+1);

	return min_depth;
}

int main() {

	root = new_node(1);
	root->left = new_node(3);
	root->right = new_node(8);
	root->left->left = new_node(5);
	root->left->right = new_node(6);

	bnode* temp = root;
	cout << "\n---------Preorder Traversal---------\n";
	preorder(temp);
	cout << endl;

	int sum =9;

	cout << "\n----Min depth of a path from root to leaf that sums upto a particular value----\n";
	cout << find_path_sum(temp,sum,0) << endl;

}