#include<bits/stdc++.h>

using namespace std;

struct node {
	node* left;
	node* right;
	int val;
};

node* root;
node* mir_tree;



node* insert_bst(node* root,int x){

	if(!root){
		root= new node;
		root->left = root->right = NULL;
		root->val = x;

	}
	else if (root->val > x){
		root->left = insert_bst(root->left,x);
	}
	else if (root->val < x) {
		root->right = insert_bst(root->right,x);
	}
	else 
		;

	return root;

	
}

void inorder_traversal(node* q) {
    
    
    if(!q)
        return ;
    
    inorder_traversal(q->left);
    if(q->val !=0 )
    	cout << q->val << " " ;
    inorder_traversal(q->right);
    
}

node* mirror(node* root){
	node* temp = new node;
	if(root){
		
		temp->val= root->val;
		temp->left = mirror(root->right);
		temp->right = mirror(root->left);
	}
	
	return temp;


}


int main() {

	int s; // no of statements
	cin >> s;
	int val;

	while(s){
		cin >> val;

		root=insert_bst(root,val);
		s--;

	}

	// inorder_traversal(root);
	cout << endl;

	mir_tree= mirror(root);
	inorder_traversal(mir_tree);
}