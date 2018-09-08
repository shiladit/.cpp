#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
int minDepth(Node *node);
/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
    malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
/* Driver program to test size function*/
int main()
{
    
    Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout<<minDepth(root)<<endl;
    
    
    return 0;
}


/*Please note that it's Function problem i.e.
 you need to write your solution in the form of Function(s) only.
 Driver Code to call/invoke your function is mentioned above.*/

/* The Node structure is
 struct Node
 {
 int data;
 Node* left;
 Node* right;
 }; */
/*You are required to complete this method*/



int minDepth(Node *node)
{
    
    if(!node->left && !node->right)
        return 1;
    else if (!node->right)
           return minDepth(node->left) + 1;
    else if(!node->left)
         return  minDepth(node->right) +1;
    else
        return min(minDepth(node->left)+1,minDepth(node->right)+1);
    
    
}
