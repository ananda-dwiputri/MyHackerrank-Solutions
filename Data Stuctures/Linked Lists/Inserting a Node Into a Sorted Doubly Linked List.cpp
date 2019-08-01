DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *add = new DoublyLinkedListNode(data);
    //add->data = data;
    add->prev = NULL;
    add->next = NULL;
    if(head == NULL)
    {
        head = add;
        return head;
    }
    else if(data < head->data)
    {
        add->next = head;
        head->prev = add;
        head = add;
        return head;
    }
    else
    {
        DoublyLinkedListNode *cur = head;
        
        while(cur->next != NULL)
        {
            if(data < (cur->next)->data)
            {   
                DoublyLinkedListNode *temp = new DoublyLinkedListNode((cur->next)->data);
                temp = cur->next;
                cur->next = add;
                add->prev = cur;
                add->next = temp;
                (add->next)->prev = add;
                return head;
            }
            cur = cur->next;
        }
        cur->next = add;
        add->prev = cur;
        return head;
    }


}
