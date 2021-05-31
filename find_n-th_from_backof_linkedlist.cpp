#include <iostream>
using namespace std;

struct linked_list
{
	int data;
	linked_list * next;
};

int count_n = 0;

linked_list* insert_node(linked_list * root,int val)
{
	if(!root)
	{
		linked_list * temp = (linked_list *)malloc(sizeof(linked_list));
		temp->next = NULL;
		temp->data = val;
		return temp;
	}

	root->next = insert_node(root->next,val);
	return root;
}

void print_linkedlist(linked_list * temp,int n)
{
	if(!temp)
	{
		return;
	}

	print_linkedlist(temp->next,n);
	++count_n;

	if(count_n == n)
		cout << temp->data << endl;
}

int main()
{
	int x,temp,n;
	cin >> x;

	linked_list *root = NULL;

	for(int i=0;i<x;i++)
	{
		cin >> temp;
		root = insert_node(root,temp);
	}

	cin >> n;

	if(n > 0 && n <= x)
		print_linkedlist(root,n);
	else
		cout << "n is out of bounds\n";
}
