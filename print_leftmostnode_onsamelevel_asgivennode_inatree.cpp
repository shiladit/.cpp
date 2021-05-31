#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* insert(node* temp,int val){

	temp = new node();

	temp->data = val;
	temp->left = temp->right = NULL;

	return temp;
}

void preorder(node* temp){

	if(temp)
		cout << temp->data << " ";
	else
		return;

	preorder(temp->left);
	preorder(temp->right);
}


int main() {

	node* root = NULL;
	root = insert(root,8);
	root->left = insert(root->left,3);
	root->right = insert(root->right,4);
	root->left->right = insert(root->left->right,7);
	root->right->left = insert(root->right->left,1);
	root->right->right = insert(root->right->right,2);


	/* PROVIDED NODE with which comparison is done */
	node* node1 = root->left->left;

	// preorder(root);

	queue <pair <node*,int> > q;
	q.push(make_pair(root,0));
	map <int,int> umap;
	umap[0]=root->data;

	bool flag = false;

	while(!q.empty()){

		pair <node*,int> temp = q.front();
		q.pop();

		if(temp.first == node1){
			if(umap.find(temp.second) != umap.end()){
				cout << umap[temp.second] << endl;
				flag = true;
				break;
			}
			else{
				cout << temp.first->data << endl;
				flag = true;
				break;
			}
		}
		
		if(temp.first->left){
			q.push(make_pair(temp.first->left,temp.second+1));
			if(umap.find(temp.second+1) == umap.end())
				umap[temp.second+1] = temp.first->left->data;
		}
		if(temp.first->right){
			q.push(make_pair(temp.first->right,temp.second+1));
			if(umap.find(temp.second+1) == umap.end())
				umap[temp.second+1] = temp.first->right->data;
		}
	}

	if(!flag){
		cout << "VALUE NOT IN CURRENT TREE\n";
	}
}