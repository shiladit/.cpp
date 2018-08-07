// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head;
    
    set <SinglyLinkedListNode*> cycle;
    
    while(temp != NULL) {
        if(cycle.find(temp) != cycle.end())
            return true;
        
        cycle.insert(temp);
        temp = temp->next;
    }
   
    return false;

}