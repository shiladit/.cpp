#include<bits/stdc++.h>
#include <queue>

using namespace std;

struct node {
	node* left;
	node* right;
	node* nextRight;
	int val;
};

node* root;


node* insert(int new_val){
	node* temp= new node;
	temp->val = new_val;
	temp->left = temp->right = temp->nextRight =  NULL;
	return temp;
}

void level_traversal(node* temp,int level,queue <pair<node*,int> > q){

	while(temp != NULL){
		
		node* cur_node = temp;
		int cur_level = level;
		
		// cout << cur_node->val << " " << cur_level << endl;

		if(temp->left)
			q.push(make_pair(temp->left,level+1));
		if(temp->right)
			q.push(make_pair(temp->right,level+1));
		if(!q.empty()){
			// cout << "Hi\n" ;
			pair<node*,int>  p ;
			p= q.front();
			temp = p.first;
			level = p.second;
				
				if(level == cur_level)
					cur_node->nextRight = temp;
				else
					cur_node = NULL;

			q.pop(); //Dequeue
		}
		else
			break;
		
		
	}

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

	queue <pair<node*,int> > q;
	node* temp = root;

	level_traversal(temp,0,q);

	cout << root->left->left->nextRight->nextRight->nextRight->val << endl;

}