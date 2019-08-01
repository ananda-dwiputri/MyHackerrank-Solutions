int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int cnt1 = 0, cnt2 = 0;
    SinglyLinkedListNode *h1=head1,*h2=head2;

    while(h1 != NULL){
        cnt1++;
        h1 = h1->next;
    }
    while(h2 != NULL){
        cnt2++;
        h2 = h2->next;
    }

    if(cnt1>cnt2){
        for(int i=0; i<cnt1-cnt2; i++) head1 = head1->next;
    } else{
        for(int i=0; i<cnt2-cnt1; i++) head2 = head2->next;
    }
    
    while(head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }
  
    return head1->data;

}
