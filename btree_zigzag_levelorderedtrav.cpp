// leetcode

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
    #define LEVEL_MARKER -9876

    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        queue <TreeNode*> Q;
       
	/* if root is NULL, dont insert */ 
        if(root != NULL)
            Q.push(root);
        
	/* This NULL marks the end of a level,
	so if we are not inserting root, then queue
	will be empty and no need to mark a level */ 
        if(!Q.empty())
            Q.push(NULL);
        
        vector <int> arr;
        int row_size = 0;
        
        while(!Q.empty())
        {
            TreeNode* elem = Q.front();
            Q.pop();

	    /* create an array in level ordered fashion
	    where we mark end of each level using LEVEL_MARKER*/            
            if(elem == NULL)
                arr.push_back(LEVEL_MARKER);
            else
                arr.push_back(elem->val);
            
            if(elem == NULL)
            {
                row_size++;
                Q.push(NULL);
                if(Q.size() == 1)
                    break;
            }
            else
            {
                if(elem->left)
                    Q.push(elem->left);
                if(elem->right)
                    Q.push(elem->right);
            }
        }
        
        vector < vector <int> > result(row_size);
        bool turn = 0;
        int i=0;
        int row = 0;
        int j = arr.size();
        
        while(i < j)
        {
            if(arr[i] == LEVEL_MARKER)
            {
                i++;
            }

	    /* Traverse array and print each level once
	    from left to right, then next level from right to left */
            else if(turn == 0)
            {
                while(arr[i] != LEVEL_MARKER)
                {
                    result[row].push_back(arr[i]);
                    i++;
                }
                row++;
                turn = !turn;
            }
            else if (turn == 1)
            {
                stack <int> stk;
                while(arr[i] != LEVEL_MARKER)
                {
                    stk.push(arr[i]);
                    i++;
                }
                
                while(!stk.empty())
                {
                    result[row].push_back(stk.top());
                    stk.pop();
                }
                
                row++;
                turn = !turn;
            }

            i++;
        }
        
        return result;
    }
};
