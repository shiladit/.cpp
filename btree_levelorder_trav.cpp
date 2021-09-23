// leetcode
#include <iostream>
#include <queue>
using namespace std;

#define EO_LEVEL -999

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* insert_into_treenode(int data)
{
	TreeNode* node = new TreeNode;

	node->val = data;
	node->left = node->right = NULL;
	return node;
}

void insert_endoflevel_inQ(queue < TreeNode* > &Q)
{
	/* if there is nothing in Q already,
	there is no need for level breaks */
	if(!Q.empty())
	{
		TreeNode* node1 = new TreeNode;
		node1->val = EO_LEVEL;
		node1->left = node1->right = NULL;
		Q.push(node1);
	}
}

vector < vector <int> > levelorder_trav(TreeNode* root)
{
	vector < vector <int> > result;
	vector <int> per_level;

	queue < TreeNode* > Q;

	/* if root is NULL, skip */
	if(root)
	{
		Q.push(root);
	}

	insert_endoflevel_inQ(Q);

	while(Q.empty() == false)
	{
		TreeNode* temp = Q.front();
		Q.pop();

		if(temp->val != EO_LEVEL)
		{
			per_level.push_back(temp->val);

			if(temp->left)
				Q.push(temp->left);

			if(temp->right)
				Q.push(temp->right);
		}
		else
		{
			/* when we find an EO_LEVEL, we insert another EO_LEVEL
			to the Q(if not empty), indicating its a level breaker */
			result.push_back(per_level);
			per_level.clear();

			insert_endoflevel_inQ(Q);
		}
	}

	return result;
}

int main()
{
	/* i/p */
	TreeNode* root = new TreeNode;
	root = insert_into_treenode(10);
	root->left = insert_into_treenode(12);
	root->right = insert_into_treenode(14);
	root->right->left = insert_into_treenode(15);
	root->right->left->right = insert_into_treenode(17);
	root->left->left = insert_into_treenode(13);
	root->left->left->right = insert_into_treenode(18);

	vector < vector <int> > result = levelorder_trav(root);

	/* o/p */
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
