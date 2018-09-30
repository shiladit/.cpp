#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* left ;
	node* right;
};

node* root;

node* new_insert(int val){
	node* temp = new node;
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

void remove(int a,int b,node* temp,vector <int> *arr){


	if(temp == NULL)
		return ;

	// cout <<"hi\n";
	if(temp->left && (temp->left->data <a || temp->left->data >b)){
		arr->push_back(temp->left->data);
		 remove(a,b,temp->left,arr);
	}

	// arr->push_back(temp->data);

	if(temp->right && (temp->right->data <a || temp->right->data >b)){
		arr->push_back(temp->right->data);
		 remove(a,b,temp->right,arr);
	}


} 



int main() {

root = new_insert(6);
root->left = new_insert(-13);
root->right = new_insert(14);
root->left->right = new_insert(-8);
root->right->left = new_insert(13);
root->right->right = new_insert(15);
root->right->left->left = new_insert(7);

int range_1,range_2;

cin >> range_1 >> range_2;


node* temp = root;
vector <int> arr;
remove(range_1,range_2,temp,&arr); 

for(int i=0;i<arr.size();i++)
	cout << arr[i] << " ";

cout << endl;

}