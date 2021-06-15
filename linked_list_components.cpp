//leetcode

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    map <int,int> umap;
    #define VISITED -9876
    
    int numComponents(ListNode* head, vector<int>& nums)
    {
        ListNode* temp_head = head;
        vector <int> insertion_order;
       

	/* We need to maintain order of insertion here
	to keep track of connected elements in the linked
	list. We do this using an array and we store the index
	of each value in a hash map for fast lookup.
	Our intention is to traverse nums and mark each value
	in nums as VISITED in the array we created. This will
	create chunks of VISITED and NON-VISITED nodes.
	Now compute the no. of contiguous VISITED nodes. */ 
        int i=0;
        while(temp_head != NULL)
        {
            insertion_order.push_back(temp_head->val);
            umap[temp_head->val] = i;
            temp_head = temp_head->next;
            i++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int index = umap[nums[i]];
            insertion_order[index] = VISITED;
        }
        
        int conn_comp = 0;
       
	/* Computes no. of contiguous nodes marked as VISITED */ 
        int j=0;
        while(j < insertion_order.size())
        {
            if(insertion_order[j] == VISITED)
            {
                while(j < insertion_order.size() && insertion_order[j] == VISITED)
                    j++;
                
                conn_comp++;
            }
            else
                j++;
        }
        return conn_comp;
    }
};
