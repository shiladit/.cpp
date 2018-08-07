// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    
    if(llist == NULL){
        SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
        llist = temp;  
    }
    else{
        SinglyLinkedListNode* temp1 = new SinglyLinkedListNode(data);
        temp1->next = llist;
        llist = temp1;
        
    }
    
    return llist;
    
}