#include <iostream>
#include "stdio.h"

using namespace std;

class LinkList {

int val;
LinkList *next;

public:
// create node and return the ptr to that node
LinkList* create_node(LinkList* head,int passed_val) {

LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));
newnode->val = passed_val;
newnode->next = NULL;

LinkList* trav = head;

if(head == NULL) {
	head = newnode;
	return head;
}

while(trav->next != NULL)
	trav = trav->next;

trav->next = newnode;

return head;
}

// traverse entire linked list
void print_linklist(LinkList *head) {

while(head != NULL) {

cout << head->val << " --> ";
head = head->next;
}
cout << "NULL" << endl;
}

LinkList* reverse_linklist(LinkList* head) {

LinkList* glob_head;

if(head == NULL)
	return NULL;
if(head->next == NULL) {
	glob_head = head;
	return head;
}

LinkList* newnode = reverse_linklist(head->next);
newnode->next = head;
head->next = NULL;

return glob_head;
}

LinkList* add_numbers(LinkList* first, LinkList* second) {

bool carry = false;
LinkList* newlist = NULL;

/* until both becomes equal to NULL we
   continue to traverse the linked list.
   If one becomes NULL 
*/
while(first != NULL || second != NULL || carry!= false) {

int sum= 0;

if(first != NULL)
	sum+= first->val;

if(second != NULL)
	sum+= second->val;

if(carry == true)
	sum = sum + 1;

if(sum > 9) {
	carry = true;
}
else
	carry = false;

//cout << (sum%10);
newlist = create_node(newlist, sum%10);

if(first != NULL)
	first = first->next;
if(second != NULL)
	second = second->next;
}

return newlist;
}

};


int main() {

LinkList obj;

LinkList* first_head = NULL;
first_head = obj.create_node(first_head,2);
first_head = obj.create_node(first_head,3);
first_head = obj.create_node(first_head,5);

LinkList* sec_head = NULL;
sec_head = obj.create_node(sec_head,9);
sec_head = obj.create_node(sec_head,3);
sec_head = obj.create_node(sec_head,8);

// printing contents in the linked list
obj.print_linklist(first_head);
obj.print_linklist(sec_head);

// add two numbers which are given in reverse order
LinkList* newlist = obj.add_numbers(first_head, sec_head);
newlist = obj.reverse_linklist(newlist);
obj.print_linklist(newlist);

return 0;
}
