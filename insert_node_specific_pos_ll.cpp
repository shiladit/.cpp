// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    
    int count=1;
    SinglyLinkedListNode* temp = head;
    
    while(count != position && temp->next){
        count++;
        temp = temp->next;
    
    }
    
    SinglyLinkedListNode* temp1= temp->next;
    SinglyLinkedListNode* temp2 = new SinglyLinkedListNode(data);
    temp->next = temp2;
    temp2->next = temp1;
    
    
    
    return head;


}