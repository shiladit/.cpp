#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

node* root;

node* new_node(int val){

	node* temp = new node();
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void topview(struct node* temp){
	
	queue <pair <node* , int> > q;

	q.push(make_pair(temp,0));

	map <int,int> umap;

	while(!q.empty()){

	pair <node*,int> p = q.front();

		if(umap.find(p.second) == umap.end())
			umap[p.second] = p.first->data;

	q.pop();

	if(p.first->left)
		q.push(make_pair(p.first->left,p.second-1));
	if(p.first->right)
		q.push(make_pair(p.first->right,p.second+1));

	}

	map <int,int> :: iterator it;

	for(it = umap.begin();it != umap.end();it++)
		cout << it->second << " ";

	cout << endl;	
}

int main() {
	
	root = new_node(4);
	root->left = new_node(2);
	root->left->right = new_node(6);
	root->left->left = new_node(1);
	root->right = new_node(5);

	topview(root);


}



