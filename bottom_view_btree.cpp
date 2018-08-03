#include<bits/stdc++.h>

using namespace std;

struct node {
	node* left;
	node* right;
	int val;
};

node* root;

map <int,pair<int,int> > umap; //key val height

node* insert(int new_val){
	node* temp= new node;
	temp->val = new_val;
	temp->left = temp->right = NULL;
	return temp;
}

void traversal(node* temp,int level,int height){
	if(!temp)
		return;

	if(umap.find(level)==umap.end())
		umap[level] = make_pair(temp->val,height);
	else {
		pair <int,int> p = umap[level];
		if(p.second < height) {
			umap[level].first = temp->val;
			umap[level].second = height;
		}
	
	}

	cout << "Val: "<< temp->val << " Level: " << level << endl;
	traversal(temp->left,level-1,height+1);
	traversal(temp->right,level+1,height+1);
}

int main() {

	root = insert(20);
	root->left = insert(8);
	root->right = insert(22);
	root->left->left = insert(5);
	root->left->right = insert(3);
	root->left->right->left = insert(10);
	root->right->right =insert(25);
	root->right->left = insert(4);
	root->right->left->right = insert(14);

	node* temp = root;

	traversal(temp,0,0);

	map <int,pair<int,int> > :: iterator it;

	for(it=umap.begin();it != umap.end(); it++){
		pair <int,int> p = it->second;
		cout << p.first << " ";
	}
	
	cout << endl;

}