#include <iostream>
#include <cassert>
using namespace std;

/* LL structure */
struct linkedlist
{
	int data;
	linkedlist * next;
};

/* DEBUG FUNCTION */
void printlist(linkedlist * root)
{
	while(root != NULL)
	{
		cout << root->data;
		if(root->next)
		{
			cout << "->";
		}
		else
		{
			cout << endl;
		}

		root = root->next;
	}
}

linkedlist * alloc_node(int val)
{
	linkedlist * new_node = new linkedlist;
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}

/* This function takes an int, and converts
it to a linked list where each node in the
linked list represents a digit from the int */
linkedlist * create_linkedlist(int num)
{
	linkedlist * root = NULL;
	linkedlist * looper = NULL;

	while(num > 0)
	{
		if(root == NULL)
		{
			root = alloc_node(num % 10);
			looper = root;
		}
		else
		{
			/* allocate at fag end of the LL */
			looper->next = alloc_node(num % 10);
			looper = looper->next;
		}

		num = num / 10;
	}
	return root;
}

linkedlist * add_linkedlist(linkedlist * root1, linkedlist * root2)
{
	int carry = 0;
	linkedlist * new_root = NULL;

	/* Check if root1 or root2 is not NULL and also
	check if we have a previous carry */
	while((root1 != NULL || root2!= NULL) || (carry != 0))
	{
		int sum = 0;
		if(root1)
		{
			sum += root1->data;
			root1 = root1->next;
		}
		if(root2)
		{
			sum += root2->data;
			root2 = root2->next;
		}

		sum += carry;

		/* Creating new node and adding to the
		front, this gives the added number in
		correct order */
		linkedlist * temp = new linkedlist;
		temp->data = sum % 10;
		temp->next = new_root;
		new_root = temp;

		if(sum >= 10)
			carry = 1;
		else
			carry = 0;
	}

	return new_root;
}

int main()
{
	int num_1, num_2;
	cin >> num_1 >> num_2;

	/* creates LL from the integer and returns the root of the LL */
	linkedlist * root_1 = create_linkedlist(num_1);
	linkedlist * root_2 = create_linkedlist(num_2);

	linkedlist * added_list = add_linkedlist(root_1,root_2);
	printlist(added_list);

	return 0;
}
