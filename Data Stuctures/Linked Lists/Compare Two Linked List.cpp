/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == NULL && head2 == NULL) return true;
    if (head1 == NULL || head2 == NULL) return false;
    if (head1->data != head2->data) return false;
    
    bool equal = true;
    
    SinglyLinkedListNode *current1 = head1, *current2 = head2;

    if ((current1->next == NULL && current2->next != NULL)
           || (current1->next != NULL && current2->next == NULL)) {
            equal = false;
            return equal;
        }
    
    while(current1->next != NULL && current2->next != NULL) {
        
        if (current1->data != current2->data) {
            equal = false;
            return equal;
        }
        
        current1 = current1->next;
        current2 = current2->next;
    }
    
    return equal;

}
