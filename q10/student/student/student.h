#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  std::vector<int> mark(mSize,0);
  for(int i=0;i<pos.size();i++){
    mark[pos[i]]=1;
  }
  CP::queue<T> temp;
  auto it=pos.begin();
  for(int i=0;i<mSize;i++){
    if(!mark[i]){
      temp.push(mData[(i+mFront)%mCap]);
    }
  }
  *this=temp;
}

#endif
