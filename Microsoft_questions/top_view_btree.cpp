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


void topview(node* root,int level){

	if(!root)
		return;

	if(umap.find(level) == umap.end())
		umap.insert(make_pair(level,root->val));

	topview(root->left,level-1);
	topview(root->right,level+1);

}

int main(){
	
	root = newnode(4);
	root->right = newnode(7);
	root->right->right = newnode(8);
	root->right->right->left = newnode(9);
	root->right->right->left->left = newnode(10);

	//traversal(root);

	topview(root,0);

	map <int,int>::iterator it;

	//PRINTING ELEMENTS IN MAP WHiCH IS BASICALLY THE TOP VIEW
	for(it =umap.begin();it !=umap.end(); it++){
		cout << it->second << " ";
		//cout << it->first << "-->" << it->second << endl;
	}
	cout << endl;
}