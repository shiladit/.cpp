// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    set <SinglyLinkedListNode*> s;
    
    while(head1 != NULL) {
        s.insert(head1);
        head1 = head1->next;
    }
    
    while(head2 != NULL){
        if(s.find(head2) != s.end())
            return head2->data;
        
        head2= head2->next;
    }

    return -1;
}