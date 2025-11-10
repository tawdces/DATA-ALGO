void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if(mSize==0){
        return;
    }
    size_t half=(mSize+1)/2;
    node* curr=mHeader->next;
    node* tmp;
    for(size_t i=0;i<half;i++){
        tmp=curr->next;
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        curr->prev=list1.mHeader->prev;
        curr->next=list1.mHeader;
        list1.mHeader->prev->next=curr;
        list1.mHeader->prev=curr;
        list1.mSize++;
        mSize--;
        curr=tmp;
    }
    while(curr!=mHeader){
        tmp=curr->next;
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        curr->prev=list2.mHeader->prev;
        curr->next=list2.mHeader;
        list2.mHeader->prev->next=curr;
        list2.mHeader->prev=curr;
        list2.mSize++;
        mSize--;
        curr=tmp;
    }
    mHeader->next=mHeader->prev=mHeader;
    mSize=0;
}
