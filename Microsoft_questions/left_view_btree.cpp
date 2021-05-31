#include<bits/stdc++.h>

using namespace std;

struct node{
	int val;
	node* left;
	node* right;
} ;

node* root;
map <int,int> umap; 


node* newnode(int x){
	node* temp = new node;
	temp->val = x;
	temp->left = temp->right = NULL;
	return temp;
}


//PREORDER TRAVERSAL
void traversal(node* root) {
	if(!root)
		return;

	cout << root->val << " ";
	traversal(root->left);
	traversal(root->right);
}

void leftview(node* root,int height) {
	if (!root)
		return;

	if(umap.find(height) == umap.end())
		umap.insert(make_pair(height,root->val));

	leftview(root->left,height+1);
	leftview(root->right,height+1);
}


int main(){
	
	root = newnode(4);
	root->left = newnode(5);
	root->left->left = newnode(6);
	root->left->right = newnode(10);
	root->left->right->left = newnode(11);
	root->right = newnode(7);
	root->right->right = newnode(8);
	root->right->right->left = newnode(9);
	root->right->right->left->left = newnode(10);

	//traversal(root);

	leftview(root,0);

	map <int,int>::iterator it;

	//PRINTING ELEMENTS IN MAP WHiCH IS BASICALLY THE LEFT VIEW
	for(it =umap.begin();it !=umap.end(); it++){
		cout << it->second << " ";
		//cout << it->first << "-->" << it->second << endl;
	}
	cout << endl;
}