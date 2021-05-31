#include<bits/stdc++.h>
using namespace std;

map <int, vector <int> > paths; // global map

struct node {
	int val;
	struct node* left;
	struct node* right;
};
node* root;

node* new_node(int val){
	struct node* temp = new node;
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

void calculate_path(node* root, int is_parent)
{
	if(root == NULL) return;

	vector <int> temp = paths[is_parent];
	temp.push_back(root->val);
	paths[root->val] = temp;

	/* Insertion Checker
        cout << "Root is: " << root->val << "  " << "Parent is: " << is_parent << endl;
	for(int x=0;x<temp.size();x++)
		cout << temp[x] << " ";
	cout << endl;
	*/

	calculate_path(root->left,root->val);
	calculate_path(root->right,root->val);
	
	return;
}

void show_paths()
{
	map <int, vector <int> > :: iterator it;
	
	for(it = paths.begin(); it != paths.end(); it++)
	{
		cout << it->first << " ---> ";
		vector <int> temp = paths[it->first];

		for(int i=0;i<temp.size();i++)
		{	
			if(i == (temp.size()-1))
				cout << temp[i] ;
			else
				cout << temp[i] << " -> ";
		}
		cout << endl;
	}
}	

int find_lca(int x, int y)
{
	vector <int> temp1 = paths[x];
	vector <int> temp2 = paths[y];

	int i,j,val;
	i = j = 0; val = -100;
	while(i < temp1.size() && j < temp2.size())
	{
		if(temp1[i] != temp2[j])
			return val;

		val = temp1[i];
		i++; j++;
	}
	return val;
}

int main() {
	
	/* Create a stupid tree */
	root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(7);
	root->left->right = new_node(8);
	root->left->right->left = new_node(9);
	root->left->right->left->right = new_node(10);
	root->left->left->left = new_node(5);

	struct node* temp=root;

	/* For initial root we pass its own value as parent */
	calculate_path(temp,temp->val);

	/* show paths */
	//show_paths();

	int node1,node2;	
	cout << "Enter two nodes to find LCA." << endl;
	cin >> node1 >> node2;

	cout << find_lca(node1,node2) << endl;
}
