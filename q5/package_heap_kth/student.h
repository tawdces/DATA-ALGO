#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
    std::vector<T> candidates;
    for(size_t i=0;i<mSize && i<7;i++){
        candidates.push_back(mData[i]);
    }
    std::sort(candidates.begin(),candidates.end(),mLess);
    return candidates[candidates.size()-k];
}

#endif