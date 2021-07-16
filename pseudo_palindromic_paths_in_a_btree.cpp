// Leetcode
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

int count = 0;

/* this routine checks the number of node values
that occur odd number of times. If the odd_count is
more than 1, we can't form a palindrome */
bool checkOdd(vector <int> &vec)
{
	int odd_count = 0;
	for(int i=1;i<=9;i++)
	{
		if(vec[i] % 2 != 0)
		{
			odd_count++;
		}
	}

	return (odd_count > 1)?false:true;
}

TreeNode* newnode(int data)
{
	TreeNode* temp = new TreeNode;
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}

void findPaths(TreeNode* root, vector <int> result)
{
	// pushing into individual path vector
	result[root->val]++;

	if((root->left ==  NULL) and (root->right == NULL))
	{
		if(checkOdd(result))
			count++;

		return;
	}

	if(root->left)
		findPaths(root->left,result);
	if(root->right)
		findPaths(root->right,result);

	return;
}

int pseudoPalindromicPaths(TreeNode* root)
{	
	vector <int> path(10);
	findPaths(root,path);

	return count;
}

int main()
{
	TreeNode* root = newnode(2);
	root->left = newnode(1);
	root->right = newnode(1);
	root->left->left = newnode(1);
	root->left->right = newnode(3);
	root->left->right->right = newnode(1);

	cout << pseudoPalindromicPaths(root) << endl;

	return 0;
}