//#include "construct_bst.cpp"

struct node
{
	int data;
	int left_height;
	int right_height;
	node* left_node;
	node* right_node;
};

extern node* insert_node_bsttree(node* temp,int val);
extern node* allocinit_node(int val);
extern void in_order(node* temp);
extern int height(node* root);
extern bool isSymmetric(node* root1,node* root2);
