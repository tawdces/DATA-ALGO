#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
using namespace std;
template <typename T, typename Comp>
size_t CP::priority_queue<T, Comp>::get_rank(size_t pos) const {
    const T& target=mData[pos];
    size_t rank=0;
    for(size_t i=0;i<mSize;i++){
      if(mLess(target,mData[i])){
        rank++;
      }
    }
    return rank;
}

#endif
