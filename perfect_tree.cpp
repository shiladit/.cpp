#include <bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}


int isPerfect(struct Node* node,int height){

    if(!node->left && node->right)
        return 0;

    if(!node->right && node->left)
        return 0;

    if(!node->left && !node->right)
        return height;

    return (isPerfect(node->left,height+1) & isPerfect(node->right,height+1));

    
}


int main()
{   

    //Modify tree here 

    struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);
    


    if(root == NULL){
        cout << "yes\n";
        return 0;
    }

    if(!root->left && root->right){
        cout << "no\n";
        return 0;
    }

    if(root->left && !root->right){
        cout << "no\n";
        return 0;
    }

    if(!root->left && !root->right){
        cout << "yes\n";
        return 0;
    }

    int left_height = isPerfect(root->left,1);
    
    int right_height = isPerfect(root->right,1);

    if(left_height == right_height)
        cout << "yes\n";
    else
        cout << "no\n";
 
    
}