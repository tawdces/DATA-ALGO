#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  size_t n=this->size();
  size_t ia=a-this->begin();
  size_t ib=b-this->begin();
  if(m==0){
    return false;
  }
  if(ia>=n || ib>=n){
    return false;
  }
  if(ia+m>n || ib+m>n){
    return false;
  }
  if(!(ia+m-1<ib || ib+m-1<ia)){
    return false;
  }
  for(size_t i=0;i<m;i++){
    std::swap((*this)[ia+i],(*this)[ib+i]);
  }
  return true;
}

#endif
