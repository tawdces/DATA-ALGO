#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  for(int i=0;i<pos.size();i++){
    this->erase(this->begin()+pos[i]-i);
  }
}

#endif
