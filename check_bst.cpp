#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}


bool isBST(struct node *root,int grandpa,int dir){
	//WHEN LOOKING AT ROOT
	if(dir == 0 ) {
		
	if(root == NULL)
		return true;
	else if(root->left == NULL && root->right == NULL)
		return true;
	else if(root->left == NULL && (root->right->data > root->data))
		return true && isBST(root->right,grandpa,2);
	else if(root->right == NULL && (root->left->data < root->data))
		return true && isBST(root->left,grandpa,1);
	else if((root->left->data < root->data) && (root->right->data > root->data))
		return true && isBST(root->left,grandpa,1) && isBST(root->right,grandpa,2);
	else return false;
	
	}
	//WHEN TRAVERSING LEFT CHILD
	else if(dir =1)
	{
		
		if(root == NULL)
		return true;
	else if(root->left == NULL && root->right == NULL)
		return true;
	else if(root->left == NULL && (root->right->data > root->data) && (root->right->data < grandpa))
		return true && isBST(root->right,grandpa,2);
	else if(root->right == NULL && (root->left->data < root->data))
		return true && isBST(root->left,grandpa,1);
	else if((root->left->data < root->data) && (root->right->data > root->data) && (root->right->data < grandpa))
		return true && isBST(root->left,grandpa,1) && isBST(root->right,grandpa,2);
	else return false;

	}
	//WHEN TRAVERSING RIGHT CHILD
	else if(dir =2)
	{
		
		if(root == NULL)
		return true;
	else if(root->left == NULL && root->right == NULL)
		return true;
	else if(root->left == NULL && (root->right->data > root->data))
		return true && isBST(root->right,grandpa,2);
	else if(root->right == NULL && (root->left->data < root->data)  && (root->left->data > grandpa))
		return true && isBST(root->left,grandpa,1); 
	else if((root->left->data < root->data) && (root->right->data > root->data) && (root->left->data > grandpa) )
		return true && isBST(root->left,grandpa,1) && isBST(root->right,grandpa,2);
	else return false;

	}

}



int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(7);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
	
  struct node *top=root;
  int grandpa = top->data;

  bool var = isBST(top,grandpa,0);

  if(!var)
  	cout << "\nNOT A BST\n" ;
  else
  	cout << "\nIT IS A BST\n" ;

  return 0;
}  