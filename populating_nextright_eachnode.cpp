// leetcode 116
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node* next;
};

Node* newnode(int data)
{
	Node* temp = new Node;
	temp->val = data;
	temp->left = temp->right = temp->next = NULL;
	return temp;
}

void inorder(Node* temp)
{
	if(temp == NULL)
		return;

	inorder(temp->left);
	cout << "Node: " << temp->val;
	if(temp->next)
		cout << " Next pointer: " << temp->next->val << endl;
	else
		cout << " Next Pointer: " << "NULL" << endl;
	inorder(temp->right);
}

Node* connect_right(Node* temp)
{

	if(temp == NULL)
		return temp;

	queue <Node*> Q;
	Q.push(temp);
	
	while(!Q.empty())
	{
		Node* temp1 = Q.front();
		Q.pop();

		if(temp1->left)
		{
			temp1->left->next = temp1->right;
			Q.push(temp1->left);
			if(temp1->right)
				Q.push(temp1->right);
		}
		if(temp1->next && temp1->right)
		{
			temp1->right->next = temp1->next->left;
		}
	}

	return temp;
}

Node* root;

int main()
{
	root = newnode(-1);
	root->left = newnode(0);
	root->right = newnode(1);
	root->left->left = newnode(2);
	root->left->right = newnode(3);
	root->right->left = newnode(4);
	root->right->right = newnode(5);
	root->left->left->left = newnode(6);
	root->left->left->right = newnode(7);
	root->left->right->left = newnode(8);
	root->left->right->right = newnode(9);
	root->right->left->left = newnode(10);
	root->right->left->right = newnode(11);
	root->right->right->left = newnode(12);
	root->right->right->right = newnode(13);

	root = connect_right(root);

	inorder(root);
	cout << endl;
	return 0;
}
