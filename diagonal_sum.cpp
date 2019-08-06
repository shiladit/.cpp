#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

node* new_node(int val){
	 node* temp = new node;
	 temp->data = val;
	 temp->left = temp->right = NULL;

	 return temp;
}

void calculate(){

	map <int,int> umap;

	queue <pair <node*,int> > q;

	q.push(make_pair(root,0));

	while(!q.empty()){

		pair <node*,int> p = q.front();
		umap[p.second] += p.first->data;
		// cout << p.second << " -- " << p.first->data << endl;
		q.pop();

		if(p.first->left)
			q.push(make_pair(p.first->left,p.second+1));

		if(p.first->right)
			q.push(make_pair(p.first->right,p.second));

	}

	map <int,int> :: iterator it;

	for(it= umap.begin();it != umap.end(); it++){
		cout << it->first << " --> " << it->second << endl;
	}

}

int main() {

	root = new_node(1);
	root->right = new_node(3);
	root->left = new_node(2);
	root->right->right = new_node(5);
	root->left->right = new_node(6);
	root->right->left = new_node(4);
	root->right->left->right = new_node(7);
	root->left->right->left = new_node(11);
	root->left->left = new_node(9);

	calculate();
}