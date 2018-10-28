#include <bits/stdc++.h>

using namespace std;

struct tree{
	int data;
	tree* left;
	tree* right;
};

tree* new_node(vector <int> arr,int low, int high){

	if(low < high){
		int mid = (low+high)/2;

		tree* root = new tree;
		root->data = arr[mid];
		root->left = NULL;
		root->right = NULL;

		root->right = new_node(arr,mid+1,high);

		root->left = new_node(arr,low,mid-1);

		return root;
	}
	else
		return NULL;
}

void traversal(tree* root){

	if(root == NULL)
		return ;

	traversal(root->left);
	cout << root->data << " ";
	traversal(root->right);
}

int main() {

	vector <int> arr;

	for(int i=0;i<10;i++){
		arr.push_back(i+1);
	}

	int low = 0;
	int high = arr.size()-1;

	tree* root;
	root = new_node(arr,low,high);

	// In-order trav to check if BST or not
	traversal(root);
	cout << endl;

}