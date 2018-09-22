#include<bits/stdc++.h>

using namespace std;

// #define SIZE 5

struct node {
	int val;
	struct node* left;
	struct node* right;
	int ast;
};

node* root;

node* new_node(int val){
	struct node* temp = new node;
	temp->val = val;
	temp->left = temp->right = NULL;
	temp->ast = -1;
	return temp;
}

vector <int> pass(node* temp,int target_val,int a,vector <int> result){

	temp->ast = a;
	result.push_back(temp->ast);

	// cout << temp->val << " --> " << temp->ast << endl; //DEBUG

	if(temp->val == target_val)
		return result;

	if(temp->left)
		return pass(temp->left,target_val,temp->val,result);
	if(temp->right)
		return pass(temp->right,target_val,temp->val,result);

	return result;
}

void print_vec(vector <int> arr){
	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";

	cout << endl;
}

int finding_ancestor(vector <int> result1,vector <int> result2){
	int i=0;
	while(i != result1.size() || i !=  result2.size()) {
		if(result1[i] != result2[i])
			return result1[i-1];
		i++;
	}

	return -1;
}

int main() {

	root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->left->right = new_node(5);

	struct node* temp=root;

	vector <int> result1;
	vector <int> result2;

	int a,b;
	
	cout << "Enter node 1: ";
	cin >> a;
	cout << "Enter node 2: ";
	cin >> b;

	// cout << pass(temp,a,temp->val) << endl;
	// cout << pass(temp,b,temp->val) << endl;
	
	result1 = pass(temp,a,temp->val,result1);
	result2 = pass(temp,b,temp->val,result2);

	// print_vec(result1);
	// print_vec(result2);

	cout << finding_ancestor(result1,result2) << "\n";
	
}