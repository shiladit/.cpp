#include <bits/stdc++.h>
using namespace std;

struct tree {
	int data;
	tree* left;
	tree* right;
};

tree* root;
map <int,vector<int> > umap;

tree* create(int new_val){
	tree* temp = new tree;
	temp->data = new_val;
	temp->left = temp->right = NULL;
	return temp;
}

void find_sum(tree* root,int height){
	
	if(!root)
		return ;
	
	if(root->left == NULL && root->right == NULL)
		umap[height].push_back(root->data);

	find_sum(root->left,height+1);
	find_sum(root->right,height+1);

}

int main() {

	root = create(10);
	root->left = create(20);
	root->right = create(30);
	root->left->left = create(40);
	root->left->right = create(50);
	root->left->right->left = create(70);
	root->left->right->right = create(80);
	root->right->right = create(60);

	find_sum(root,0);

	map <int,vector<int> > :: iterator it;

	it=umap.begin(); //picking lowest leaf level 

	int sum = 0;

	vector <int> a = it->second;
	for(int i=0;i<a.size();i++)
		sum += a[i];

	cout << sum << endl;

}