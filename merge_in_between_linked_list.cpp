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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* head1 = list1;
        ListNode* temp = head1;
        
        int count = 0;
        while(count != (a-1))
        {
            temp = temp->next;
            count++;
        }
        
        // Head of first list's 1st part
        ListNode* temp1 = temp;
        
        while(count != (b+1))
        {
            temp = temp->next;
            count++;
        }
        
        // Head of first list's 2nd part
        ListNode* temp2 = temp;
        
        ListNode* head2 = list2;
        temp = head2;
        
        while(temp->next)
        {
            temp = temp->next;
        }
        
        /* connecting first list's 1st part with head of second list */
        temp1->next = head2;
        
        /* connecting end of second list with 2nd part of 1st list */
        temp->next = temp2;
        
        return head1;
        
    }
};