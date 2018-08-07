// Complete the reversePrint function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void reversePrint(SinglyLinkedListNode* head) {
    
    stack <long> stk;
    
    while(head != NULL){
        stk.push(head->data);
        head= head->next;
    }
    
    while(!stk.empty()){
        cout << stk.top() << endl;
        stk.pop();
    }


}