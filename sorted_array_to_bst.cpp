/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
  
        int n = nums.size();

        if(n == 0)
            return NULL;
        
        TreeNode* temp = new TreeNode();

        /* Pick middle element and make it root */
        int middle = n/2;
        temp->val = nums[middle];
        
        vector <int> left(nums.begin(),nums.begin()+middle);
        vector <int> right(nums.begin()+middle+1,nums.end());
        
        /* Recursively call left part of middle and attach it to left node*/
        temp->left = sortedArrayToBST(left);
        /* Recursively call right part of middle and attach it to right node*/
        temp->right = sortedArrayToBST(right);
        
        return temp;
    }
};