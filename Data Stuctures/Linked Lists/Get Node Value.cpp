/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode *current = head;
    SinglyLinkedListNode *temp = head;
    int con = 0;
    
    while(current != NULL){
        current = current->next;
        
        if(con++ > positionFromTail)
            temp = temp->next;
    }
    return temp->data;

}
