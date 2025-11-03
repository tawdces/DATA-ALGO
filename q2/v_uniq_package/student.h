#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include<bits/stdc++.h>
using namespace std;

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  map<T,bool> mp;
  int index=0;
  for(auto i=0;i<mSize;i++){
    if(mp.find(mData[i])==mp.end()){
      mp[mData[i]]=true;
      mData[index]=mData[i];
      index++;
    }
  }
  mSize=index;
}

#endif
