void shift(int k) {
    if (mHeader->next == mHeader || mHeader->next == mHeader->prev) return;
    
    int size = 0;
    node* current = mHeader->next;
    while (current != mHeader) {
        size++;
        current = current->next;
    }
    
    if (size == 0) return;
    
    k = k % size;
    if (k < 0) k = size + k;
    if (k == 0) return;
    
    node* new_first = mHeader->next;
    for (int i = 0; i < k; i++) {
        new_first = new_first->next;
    }
    
    node* new_last = new_first->prev;
    
    node* old_first = mHeader->next;
    node* old_last = mHeader->prev;
    
    mHeader->next = new_first;
    mHeader->prev = new_last;
    
    new_first->prev = mHeader;
    new_last->next = mHeader;
    
    old_first->prev = old_last;
    old_last->next = old_first;
}