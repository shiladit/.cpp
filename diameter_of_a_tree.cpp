#include <bits/stdc++.h>

using namespace std;

struct node {
	int val;
	node* left;
	node* right;
	int l_height;
	int r_height;
};

node* newNode(int new_val){
	
	node* temp = new node;
	temp->val = new_val;
	temp->left = temp->right = NULL;
	temp->l_height = temp->r_height = -1;
	return temp;

}

int height(node* temp){
	if(temp == NULL)
		return 0;

	return max(1+height(temp->left),1+height(temp->right));
}



void diameter(node* temp){

	if(temp == NULL)
		return;

	temp->l_height = height(temp->left);
	temp->r_height = height(temp->right);

	diameter(temp->left);
	diameter(temp->right);
}

int trav(node* temp,int* dia){
	if(temp == NULL)
		return *dia;

	
	*dia = max(*dia,temp->l_height + temp->r_height  + 1) ; //+1 because of the edge count being one less than the node count
	// cout << temp->val << "-- left_height: " << temp->l_height << " -- right height: " << temp->r_height << endl ;


	trav(temp->left,dia);
	trav(temp->right,dia); 

	return *dia;
}

int main() 
{ 
  
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);
  root->left->right->left = newNode(6);
  root->left->right->right = newNode(7);
  root->right->right = newNode(8);
  root->right->right->right = newNode(9);
  root->right->right->right->left = newNode(10);
  root->right->right->right->right = newNode(11);
  root->right->right->right->left->right = newNode(12);

  diameter(root);

  int dia = -INT_MAX;
  cout <<  trav(root,&dia) << endl;
}