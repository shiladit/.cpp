#include<bits/stdc++.h>

using namespace std;



struct btree{
	int val;
	btree* left;
	btree* right;
};

btree* root;


btree* insert(int new_val){
	btree* temp = new btree;
	temp->val = new_val;
	temp->left = temp->right = NULL;
	return temp;
}

void pre_trav(btree* temp) {
	if(!temp)
		return;

	cout << temp->val << " ";
	pre_trav(temp->left);
	pre_trav(temp->right);

}

bool isSymmetric(btree* temp1,btree* temp2){

	bool flag = true;

	if((temp1 != NULL && temp2 == NULL ) || (temp2 != NULL && temp1 == NULL ))
		return false;

	if(temp1 == NULL && temp2 == NULL)
		return true;

	if(temp1->val != temp2->val)
		return false;

	flag = isSymmetric(temp1->left,temp2->right) && isSymmetric(temp1->right,temp2->left);

	return flag; 
}

int main() {

	root = insert(1);
	root->left = insert(2);
	root->right = insert(2);
	root->left->left = insert(3);
	root->left->right = insert(4);
	root->right->left = insert(4);
	root->right->right = insert(3);

	btree* temp = root;

	pre_trav(temp);
	cout << endl;

	bool flag = isSymmetric(temp,temp);

	if(flag == true)
		cout << "Symmetric\n";
	else
		cout << "Not Symmetric\n";


}