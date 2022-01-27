#include <bits/stdc++.h>

using namespace std;

struct node {
	int val;
	node* left;
	node* right;
};

node* newNode(int new_val)
{	
	node* temp = new node;
	temp->val = new_val;
	temp->left = temp->right = NULL;
	return temp;
}

bool check_same(node* temp1,node* temp2)
{
	if(temp1 == NULL && temp2 == NULL)
		return true;
	if(temp1 == NULL && temp2)
		return false;
	if(temp1 && temp2 == NULL)
		return false;
	
	if(temp1->val != temp2->val)
		return false;

	return check_same(temp1->left,temp2->left) && check_same(temp1->right,temp2->right);

	return false;
}


int main() 
{ 
  
  struct node *root = newNode(1); 
  // root->left        = newNode(2); 
  // root->right       = newNode(3); 
  // root->left->left  = newNode(4); 
  // root->left->right = newNode(5);
  // root->left->right->left = newNode(6);
  // root->left->right->right = newNode(7);
  

  struct node *root1 = newNode(1); 
  // root1->left        = newNode(2); 
  // root1->right       = newNode(3); 
  // root1->left->left  = newNode(4); 
  // root1->left->right = newNode(5);
  // root1->left->right->left = newNode(6);
  // root1->left->right->right = newNode(7);

  bool flag = check_same(root,root1);

  if(flag)
  	cout << "SAME\n";
  else
  	cout << "NOT SAME\n";
}