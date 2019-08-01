/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    SinglyLinkedListNode* node = head;
    while(node->next != NULL){
        if(node->data == node->next->data)
            node->next = node->next->next;
        else
            node = node->next;
    }
    return head;

}
