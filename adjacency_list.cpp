#include <iostream>

using namespace std;

#define MAX 100

class node{
public:
	int data;
	node* next;
};

node* adj[MAX] = {NULL};

node* new_node(int val){
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;

	return temp;
}

void print_ll(int V){
	for(int i=0;i<V;i++){
		cout << i << " : ";
		node* temp = adj[i];
		if(temp != NULL){
		while(temp){
			cout << " --> " << temp->data;
			temp = temp->next; 
			}
		}
		cout << endl;
	}
}

int main() {

int V,E;
cin >> V >> E;

for(int i=0;i<E;i++){
	int a,b;
	cin >> a >> b;
	// cout << b << endl;
	if(adj[a] == NULL){
		adj[a] = new_node(b);

	}
	else{
		node* temp = adj[a];
		// cout << "Hi\n";
		while(temp->next)
			temp = temp->next;
		temp->next = new_node(b);
	}
}


print_ll(V);
}