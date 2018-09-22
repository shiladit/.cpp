#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

node* insert(node* temp,int new_val){
    if(!temp) {
        node* temp1 = new node;
        temp1->val = new_val;
        temp1->left = temp1->right = NULL;
        temp = temp1;
        return temp;
    }
    else {
        if((temp->val) > new_val)
            temp->left = insert(temp->left,new_val);
        else
            temp->right = insert(temp->right,new_val);
        
    }
    
    return temp;
}

void inorder_print(node* temp){
	if(!temp)
		return;

	if(temp->left)
		inorder_print(temp->left);

	cout << temp->val << " ";

	if(temp->right)
		inorder_print(temp->right);
}

bool find_node(node* temp,int find_val){

	if(!temp)
		return false;

	if(temp->val == find_val )
		return true;
	else if (temp->val > find_val)
		return find_node(temp->left,find_val);
	else
		return find_node(temp->right,find_val);
}

int main() {
    
    node* root = NULL;
    
    int q;
    cin >> q;
    
    
    
    while(q--){
        int val;
        cin >> val;
        
        
        root = insert(root,val);
    }
    
    inorder_print(root);
    cout << endl;

    int val;
    cin >> val;
    bool flag = find_node(root,val);

    if(flag)
    	cout << "FOUND\n";
    else
    	cout << "NOT FOUND\n";
}
