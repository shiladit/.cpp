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


void deleteK(int k,int s){
	int count=1;
	node* cur = root;

	if(!cur || cur->next ==NULL || k>s)
		return;

	node* cur_fol = root->next; 

	while(cur->next){
		if(count == k-1){
			count =1;
			// cout << "HI" << endl;
			cur->next = cur_fol->next;
			if(cur_fol->next == NULL){
				cur_fol = NULL;
				return;
			}
			cur = cur->next;
			if(cur->next == NULL)
				return;
			cur_fol = cur->next;


			

		}
		else {
		count++;
		cur=cur->next;
		cur_fol=cur_fol->next;
		}
	}
}

void print()
{
	node* cur;
	cur = root;
	

	while(cur){
		 cout << cur->val << " " ;
		cur = cur->next;	

	}
	cout << endl;

	
}




int main(){

  int node_count,T,s;
  cin >> T; //No of test cases

	for(int u=0;u<T;u++) {
		cin >> node_count;
		s=node_count;
	  	while(node_count) {
	  		int a;
	  		cin >> a;
	  		insert(a);
	  		node_count--;
	  }
	  int k;
	  cin >> k; //k-th node

	  deleteK(k,s);
	  print();
}

		
}