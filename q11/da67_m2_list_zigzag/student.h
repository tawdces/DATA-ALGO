
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {
    /*

        “In war, then, let your great object be victory, not lengthy campaigns.”
        ― Sun Tzu, The Art of War 

    */
   bool check=true;
   node* cur=mHeader->next->next;
   node* lscur=ls.mHeader->next;
   while(lscur!=ls.mHeader){
    node* prev=cur->prev;
    node* temp=lscur->next;
    prev->next=lscur;
    lscur->prev=prev;
    cur->prev=lscur;
    lscur->next=cur;
    if(cur!=this->mHeader){
        cur=cur->next;
    }
    lscur=temp;
   }
   this->mSize+=ls.mSize;
   ls.mHeader->next=ls.mHeader;
   ls.mHeader->prev=ls.mHeader;
   ls.mSize=0;
}

#endif
