SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    
    if(head == NULL){
        head = new SinglyLinkedListNode(data);
        head->next = NULL;
    }
    else{
        SinglyLinkedListNode* current_node = head;
        
        while(current_node->next != NULL){
            current_node = current_node->next;
        }
        SinglyLinkedListNode *new_node = new SinglyLinkedListNode(data);
        new_node->next = NULL;
        
        current_node->next = new_node;
    }
    
    return head;


}
