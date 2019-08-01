/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
     if(head==NULL)
        return head;
    else{
        DoublyLinkedListNode *temp_ = head->next;
        DoublyLinkedListNode *temp = head;
        DoublyLinkedListNode *_temp = head->prev;
        while(temp->next!=NULL)
        {
            temp->prev = temp_;
            temp->next = _temp;
            temp = temp->prev;
            temp_ = temp->next;
            _temp = temp->prev;
        }
        temp->next = temp->prev;
        return temp;
    }

}
