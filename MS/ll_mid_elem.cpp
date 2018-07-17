#include<bits/stdc++.h>

using namespace std;

class node{
	public:
	int val;
	node* next;

	void insert(int);
};

node* root; //Global Variable


void insert(int a){

	if(!root){
		node* new_node = new node;
		new_node->val = a;
		new_node->next = NULL;
		root=new_node;
		}
	else
	{
		node* cur=root;
		while(cur->next){
			cur=cur->next;
		}
		node* new_node1= new node;
		new_node1->val = a;
		new_node1->next =NULL;
		cur->next=new_node1;
	}

} 

void print()
{
	node* cur1;
	node* cur2;
	cur1 = root;
	cur2 = root;

	while(cur2){
		// cout << cur1->val << " --> " ;
		cur1=cur1->next;
		cur2=cur2->next->next;

	}

	cout << cur1->val << endl;	
}


int main(){

  int node_count;
  cin >> node_count;
  int s = node_count;

  while(node_count) {
  	int a;
  	cin >> a;
  	insert(a);
  	node_count--;
  }

  if(s == 0)
  	cout << "No Nodes\n";
  else if(s == 1)
  	cout << root->val  << endl;
  else if(s == 2 || s == 3)
  	cout << root->next->val  << endl;
  else 
  		print();
		
}