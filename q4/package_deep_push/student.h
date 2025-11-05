#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  stack<T> newstack;
  for(size_t i=0;i<pos;i++){
    newstack.push(this->top());
    this->pop();
  }
  this->push(value);
  while(!newstack.empty()){
    this->push(newstack.top());
    newstack.pop();
  }
}

#endif
