#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  auto n=last-first;
  auto posindex=position-this->begin();
  auto oldsize=this->size();
  this->resize(this->size()+n);
  for(auto i=oldsize;i>posindex;i--){
    (*this)[i+n-1]=(*this)[i-1];
  }
  for(auto i=0;i<n;i++){
    (*this)[posindex+i]=first[i];
  }
}

#endif
