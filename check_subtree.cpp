#include<bits/stdc++.h>

using namespace std;

int a=0;
int b=0;


struct node{
	node* left;
	node* right;
	int val;
};

node* root;
node* sub;

node* insert(int val){
	node* temp1=new node;
	temp1->left=temp1->right=NULL;
	temp1->val = val;
	
	return temp1;

}

bool check_subtree(node* temp1,node* temp2) {
	if(temp1 == NULL || temp2 == NULL)
		return true;

	if(temp1->val != temp2->val)
		return false;

	return ((check_subtree(temp1->left,temp2->left)) && (check_subtree(temp2->right,temp2->right)));


}

void traverse (node* temp1,node * temp2){
	bool flag= false;
	if(temp1 != NULL)
		flag = check_subtree(temp1,temp2);
	else
		return;

	if(flag){
		cout << "yes" << endl;
	}


	// cout << temp1->val << endl;
	traverse(temp1->left,temp2);
	traverse(temp1->right,temp2);

}

int  find_min_height(node* temp1,int h) {

	// int h1=0;
	// int h2=0;

	if(temp1 == NULL)
		return h;

	return	min(find_min_height(temp1->left,h+1),find_min_height(temp1->right,h+1));

	// cout << h1 << " -- " << h2 << endl;

	}

int main() {
	
	root = insert(5);
	root->left= insert(3);
	root->right= insert(6);
	// root->right->right=insert(3);
	root->right->right = insert(10);
	root->left->left = insert(4);
	// root->left->right= insert(6);
	// root->left->left->right=insert(30);

	sub = insert(10);
	sub->left= insert(4);
	// sub->left->left = insert(2);
	sub->right= insert(6);
	sub->left->right=insert(30);

	node* temp1=root;
	node* temp2=sub;

	traverse(temp1,temp2);

	int ht= find_min_height(temp1,0);
	cout << ht << endl;



	return 0;
}