#include <iostream>
using namespace std;

struct node
{
	int data;
	int left_height;
	int right_height;
	node* left_node;
	node* right_node;
};

node* allocinit_node(int val)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = val;
	temp->left_height = temp->right_height = 0;
	temp->left_node = temp->right_node = NULL;
	return temp;
}

node* insert_node_bsttree(node* root, int val)
{
	if(!root)
	{
		root = allocinit_node(val);
		return root;
	}

	if(val < root->data) 
	{	
		++root->left_height;
		root->left_node = insert_node_bsttree(root->left_node, val);
	}
	else
	{
		++root->right_height;
		root->right_node = insert_node_bsttree(root->right_node, val);
	}

	return root;
}

void in_order(node* root)
{
	if(root) 
	{
		in_order(root->left_node);
		assert(root);
		cout << "value of: " << root->data << " with left subtree height: " << root->left_height
			<< ", and with right subtree height: " << root->right_height << " " ; 
		if((root->left_height == 0) && (root->right_height == 0))
		{
			cout << "( LEAVES ! )\n";
		}
		else
		{
			cout << "\n";
		}	
		in_order(root->right_node);
	}
}

int main()
{
	struct node* bst_root = NULL;
	
	int no_of_nodes;
	cin >> no_of_nodes;
	while(no_of_nodes--)
	{
		int temp_val;
		cin >> temp_val;
		bst_root = insert_node_bsttree(root,temp_val);
	}
	
	in_order(bst_root);

	return 0;
}
