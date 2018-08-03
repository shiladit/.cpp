#include<bits/stdc++.h>
#include<queue>
#include<algorithm>

using namespace std;


struct btree {
	int val;
	btree* left;
	btree* right;
};

btree* root;
queue <btree*> q;

btree* insert(int new_val) {
	btree* temp = new btree;
	temp->val = new_val;
	temp->left = temp->right = NULL;

	return temp;
}


int main() {

	root = insert(14);
	root->left = insert(5);
	root->left->left = insert(2);
	root->right = insert(7);
	root->right->left = insert(9);
	root->right->right = insert(10);


	btree* temp =root;
	q.push(temp);

	while(!q.empty()){

		temp= q.front();
		q.pop();
		cout << temp->val << " ";

		if(temp->left)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);

	}

	cout << endl;

}