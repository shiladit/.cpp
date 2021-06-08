#include<iostream>
using namespace std;

struct btree
{
	int val;
	btree* left;
	btree* right;
};

bool isSymmetric(btree* root1,btree* root2)
{
	if(!root1 && !root2)
		return true;
	else if(root1 && !root2)
		return false;
	else if(!root1 && root2)
		return false;
	else
	/* when both are not null */
	{
		if(root1->val == root2->val)
			return true & isSymmetric(root1->left,root2->right) & isSymmetric(root1->right,root2->left);
		else
			return false;
	}
}

btree* insert(int new_val){
	btree* temp = new btree;
	temp->val = new_val;
	temp->left = temp->right = NULL;
	return temp;
}

int main()
{
	btree* root = NULL;
	root = insert(1);
	root->left = insert(2);
	root->right = insert(2);
	root->left->left = insert(3);
	root->left->right = insert(4);
	root->right->left = insert(4);
	root->right->right = insert(3);

	if(isSymmetric(root,root))
		cout << "Symmetric\n";
	else
		cout << "Not Symmetric\n";
}
