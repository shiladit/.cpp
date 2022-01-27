//leetcode
#include <iostream>

using namespace std;

struct TreeNode 
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* newNode(int data)
{
	TreeNode* temp = new TreeNode;
	temp->value = data;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* mergeTree(TreeNode* root1, TreeNode* root2)
{
	if(!root1 && !root2)
		return NULL;

	int sum = 0;

	if(root1)
		sum += root1->value;

	if(root2)
		sum += root2->value;

	TreeNode* root3 = newNode(sum);

	root3->left = mergeTree(root1 ? root1->left : NULL , root2 ? root2->left : NULL);
	root3->right = mergeTree(root1 ? root1->right : NULL,root2 ? root2->right : NULL);

	return root3;
}

void inorderTrav(TreeNode* temp)
{
	if(!temp)
		return;

	inorderTrav(temp->left);
	cout << temp->value << " " ;
	inorderTrav(temp->right);

	return;
}

int main()
{
	TreeNode* root1 = newNode(1);
	root1->left = newNode(2);

	TreeNode* root2 = newNode(3);
	root2->left = newNode(4);
	root2->right = newNode(5);

	TreeNode* root3 = mergeTree(root1,root2);

	inorderTrav(root3);

	return 0;
}