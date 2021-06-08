#include <iostream>
#include <vector>
using namespace std;

#define DUMMY -99

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* allocnode(int data)
{
	TreeNode* temp = new TreeNode;
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}

int tryRob(TreeNode* root, int &l, int &r)
{
	if(root == NULL)
		return 0;

	int ll =0;
	int lr =0;
	int rl =0;
	int rr =0;

	l = tryRob(root->left,ll,lr);
	r = tryRob(root->right,rl,rr);

	return max((root->val + ll + lr + rl + rr), (l + r));
}

int rob(TreeNode* root)
{
	int l,r;
	return tryRob(root,l,r);
}

int main()
{
	TreeNode* root = allocnode(7);
	root->left = allocnode(1);
	root->left->left = allocnode(4);
	root->left->right = allocnode(5);
	root->left->right->left = allocnode(2);
	root->left->right->left->left = allocnode(3);
	root->right = allocnode(3);
	root->right->left = allocnode(11);
	root->right->right = allocnode(7);
	root->right->left->left = allocnode(1);
	root->right->left->left->left = allocnode(2);
	root->right->left->left->left->left = allocnode(6);

	cout << rob(root) << endl;
}
