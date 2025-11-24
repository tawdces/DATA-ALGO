#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "compressed_vector.h"
#include <cstdlib>

template <typename T> void CP::CompressedVector<T>::expand(size_t capacity) {
  // write your code here
  T* new_mDataV = new T[capacity]();
  size_t* new_mDataL = new size_t[capacity]();
  
  for(size_t i = 0; i < mSize; i++) {
    new_mDataV[i] = mDataV[i];
    new_mDataL[i] = mDataL[i];
  }

  delete [] mDataV;
  delete [] mDataL;

  mDataV = new_mDataV;
  mDataL = new_mDataL;
  mCap = capacity;

  return;
}

template <typename T>
void CP::CompressedVector<T>::insert(int index, const T &element) {
  // write your code here
  int cur = index, idx = 0;
  while(idx < mSize && cur >= mDataL[idx]) {
    cur -= mDataL[idx];
    idx++;
  }
  
  if(idx < mSize) {

    if(mDataV[idx] == element) mDataL[idx]++;
    else {
      if(cur == 0) {
        if(idx - 1 >= 0 && mDataV[idx - 1] == element) mDataL[idx - 1]++;
        else {
          ensureCapacity(mSize + 1);
          for(int i = mSize; i > idx; i--) {
            mDataV[i] = mDataV[i - 1];
            mDataL[i] = mDataL[i - 1];
          }
          mDataV[idx] = element;
          mDataL[idx] = 1;
          mSize++;
        }
      }
    }
    
  }
  else {
    if(mDataV[mSize - 1] == element) mDataL[mSize - 1]++;
    else {
      ensureCapacity(mSize + 1);
      mDataV[mSize] = element;
      mDataL[mSize] = 1;
      mSize++;
    }
  }
}

template <typename T> T &CP::CompressedVector<T>::operator[](int index) const {
  // write your code here
  int cur = index, idx = 0;
  while(idx < mSize && cur >= mDataL[idx]) {
    cur -= mDataL[idx];
    idx++;
  }
  return mDataV[idx];
}

#endif