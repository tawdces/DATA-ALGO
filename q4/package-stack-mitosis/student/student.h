#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    CP::stack<T> tempstack;
    for(int i=0;i<=b;i++){
        tempstack.push(this->top());
        if(i>=a && i<=b){
            tempstack.push(this->top());
        }
        this->pop();
    }
    while(!tempstack.empty()){
        this->push(tempstack.top());
        tempstack.pop();
    }
}

#endif