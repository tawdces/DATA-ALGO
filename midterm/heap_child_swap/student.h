#include "priority_queue.h"
#include <utility>

template <typename T,typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k) {
  int idx=k*2+1;
  int cnt=1;
  while(idx<mSize){
    for(int i=0;i<cnt;i++){
      std::swap(mData[idx+i],mData[idx+cnt+i]);
    }
    idx=idx*2+1;
    cnt=cnt*2;
  }
}