#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
size_t CP::list<T>::fix_wrong() {
  size_t count=0;
  auto ptr1=mHeader->next;
  auto ptr2=mHeader->next->next;
  if(ptr1->prev!=mHeader){
    count++;
    ptr1->prev=mHeader;
  }
  while(ptr2!=mHeader && ptr1!=nullptr && ptr2!=nullptr){
    if(ptr2->prev!=ptr1){
      count++;
      ptr2->prev=ptr1;
    }
    ptr1=ptr1->next;
    ptr2=ptr2->next;
  }
  return count;
}

#endif