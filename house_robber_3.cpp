#include <iostream>
using namespace std;

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

/* For every node we check if its NULL, then
it contributes 0 to the sum and we return 0.
if root->left exists we recurse by skipping one level
same for root->right.
When we reach a leaf, whose both left and right are NULL,
we compare the roots value + grandchildren's sum &&
the sum of its immediate children. Why?
Because we can select a node and its grandchildren or we can
not select the root and only select the roots children */
int rob(TreeNode* root)
{
	if(!root)
		return 0;

	int value = 0;

	if(root->left)
		value += rob(root->left->left) + rob(root->left->right);
	if(root->right)
		value += rob(root->right->left) + rob(root->right->right);

	return max((root->val + value),(rob(root->left) + rob(root->right)));
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
