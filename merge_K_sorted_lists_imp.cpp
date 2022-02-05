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
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            if(l->val > r->val)
                return true;
            else
                return false;
        }
    };
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //Min-heap        
        priority_queue < ListNode*, vector <ListNode*>, compare > pq;
        
        int n = lists.size();
        
        for(int i=0;i<n;i++)
        {
            if(lists[i] != NULL)
                pq.push(lists[i]);
            
        }
        
        if(pq.empty())
            return NULL;
        
        ListNode* head = pq.top();
        pq.pop();
        
        if(head->next)
            pq.push(head->next);
        
        ListNode* temp = head;
        
        while(!pq.empty())
        {   
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
            if(temp && temp->next)
                pq.push(temp->next);            
        }

        return head;
    }
};