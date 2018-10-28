/* Create linked list from each node of a tree levelwise */

#include <bits/stdc++.h>
using namespace std;

struct tree{
	int data;
	tree* left;
	tree* right;
};

struct linked_list{
	int data;
	linked_list* next;
};

tree* root;

tree* new_node(int val){
	tree* temp = new tree;
	temp->data = val;
	temp->left = temp->right = NULL;

	return temp;
}

linked_list* insert_ll(int val){
	linked_list* temp = new linked_list;
	temp->data = val;
	temp->next = NULL;

	return temp;
}

vector <linked_list*> do_bfs(vector <linked_list*> adj_list,tree* root,int level){

	queue <pair <tree*,int> > q;
	q.push(make_pair(root,level));

	while(!q.empty()){

		pair <tree*,int> p = q.front();

		if(p.first){
			int index = p.second;
			linked_list* temp = adj_list[p.second];

			while(temp->next)
				temp=temp->next;
			
			temp->next = insert_ll(p.first->data);
		}
			
		q.pop();

		if(p.first->left)
			q.push(make_pair(p.first->left,p.second+1));
		if(p.first->right)
			q.push(make_pair(p.first->right,p.second+1));
	}

	return adj_list;
}

int main(){

	root = new_node(4);
	root->left = new_node(3);
	root->left->right = new_node(5);
	root->left->left = new_node(6);
	root->left->left->left = new_node(7);
	root->left->left->left->left = new_node(10);
	root->right = new_node(11);
	root->right->right = new_node(12);
	root->right->left = new_node(13);
	root->right->right->right = new_node(14);

	vector <linked_list*> adj_list(5);

	for(int i=0;i<5;i++){
		adj_list[i] = insert_ll(i);
	}

	adj_list = do_bfs(adj_list,root,0);

	for(int i=0;i<5;i++){
		linked_list* temp = adj_list[i];

		while(temp){
			cout << temp->data << " --> ";
			temp = temp->next;
		}

		cout << "NULL" << endl;
	}
}