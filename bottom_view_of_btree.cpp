#include<bits/stdc++.h>

using namespace std;

// #define SIZE 5

struct node {
	int val;
	struct node* left;
	struct node* right;
};

node* root;

map <int,pair <int,int> > umap;

node* new_node(int val){
	struct node* temp = new node;
	temp->val = val;
	temp->left = temp->right = NULL;
	
	return temp;
}

void traversal(node* temp,int vert,int height){

	if(temp == NULL)
		return ;

	// cout << temp->val << " -- " << vert << " -- " << height << endl;
	if(umap.find(vert) == umap.end())
		umap[vert] = make_pair(height,temp->val);
	else{
		pair <int,int> p = umap[vert];
		if(height > p.first)
			umap[vert] = make_pair(height,temp->val);  

	}


	if(temp->left)
		traversal(temp->left,vert-1,height+1);
	if(temp->right)
		traversal(temp->right,vert+1,height+1);
}

int height(node* temp){
	if(temp == NULL)
		return 0;
	
	else
		return max(1+height(temp->left),1+height(temp->right));
}


int main() {

	root = new_node(20);
	root->left = new_node(8);
	root->right = new_node(22);
	root->right->right = new_node(25);
	root->left->left = new_node(5);
	root->left->right = new_node(3);
	root->left->right->left = new_node(10);
	root->left->right->right = new_node(14);

	node* temp =root;

	cout << "The height of the btree is: " << height(temp) << endl;


	traversal(temp,0,0);

	map <int,pair<int,int> > :: iterator it;

	for(it=umap.begin();it !=umap.end();it++){

		pair <int,int> p = it->second;
		cout << p.second << " ";
	}

	cout << endl;
}