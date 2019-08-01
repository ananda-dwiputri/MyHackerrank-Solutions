SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode *new_node = new SinglyLinkedListNode(data);
    
    if(head == NULL){
        new_node->next = NULL;
        return new_node;
    }
    
    if(position == 0){
        new_node->next = head;
        return new_node;
    }
    
    SinglyLinkedListNode *current_node = head;
    while(position > 1){
        current_node = current_node->next;
        position--;
    }
    
    new_node->next = current_node->next;
    current_node->next = new_node;
    
    return head;

}
