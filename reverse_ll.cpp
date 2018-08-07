// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    
    SinglyLinkedListNode* prev,*curr,*next_one;
    next_one = NULL;
    prev = NULL;
    curr = head;
    
    while(curr != NULL){
        next_one = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_one;
    }
    
    head = prev;
    return head;
}