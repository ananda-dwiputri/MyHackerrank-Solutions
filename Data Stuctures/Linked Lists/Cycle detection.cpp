bool find(SinglyLinkedListNode* cache[], int l, SinglyLinkedListNode* q) {
    for (int i = 0; i < l; i++) {
        if (cache[i] == q)
            return true;
    }
    
    return false;
}

bool has_cycle(SinglyLinkedListNode* head) {
    if (head == NULL || head->next == NULL)
        return false;
    
    SinglyLinkedListNode* cache[1000];
    int cache_idx = 0;
    
    for (int i = cache_idx; i < 1000; i++)
        cache[i] = NULL;
    
    SinglyLinkedListNode* tmp = head;
    
    while(tmp->next != NULL) {
        
        if (find(cache, cache_idx+1, tmp))
            return true;
            
        cache[cache_idx] = tmp;
        cache_idx++;
        
        tmp = tmp->next;
    }
    
    return false;

}
