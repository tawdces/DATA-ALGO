#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  for (auto it = ls.begin(); it != ls.end(); ++it) {
    CP::list<T> &current_list = *it;
    
    if (!current_list.empty()) {
      mHeader->prev->next = current_list.mHeader->next;
      current_list.mHeader->next->prev = mHeader->prev;
      
      current_list.mHeader->prev->next = mHeader;
      mHeader->prev = current_list.mHeader->prev;
      
      mSize += current_list.mSize;
      
      current_list.mHeader->next = current_list.mHeader;
      current_list.mHeader->prev = current_list.mHeader;
      current_list.mSize = 0;
    }
  }
}

#endif