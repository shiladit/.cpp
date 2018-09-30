/* Print n-th node from last of a linked list */

#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node* next;
};

node* insert(node* root,int val){

	node* temp = root;

	if(temp == NULL){
		temp = new node;
		temp->data = val;
		temp->next = NULL;
		return temp;
	}
	else {
		while(temp->next != NULL)
			temp = temp->next;

		node* temp1 = new node;
		temp1->data = val;
		temp1->next = NULL;
		temp->next = temp1;
		return root;
	}
}

void print_list(node* temp) {

	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){

	int n;
	cin >> n;

node* root = NULL;

for(int i=0;i<10;i++)
	root = insert(root,i+1);

print_list(root);

node* p1 = root;
node* p2 = root;

int count = 0;

while(count != n){
	count++;
	p2 = p2->next;
}

while(p2->next){
	p1 = p1->next;
	p2 = p2->next;
}

cout << p1->data << endl;

}