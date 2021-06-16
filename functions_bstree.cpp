#include <iostream>
#include "construct_bst.h"
using namespace std;

int height(node* root)
{
	if(root == NULL)
		return 0;
	else
		return (1 + max(height(root->left_node),height(root->right_node)));
}
