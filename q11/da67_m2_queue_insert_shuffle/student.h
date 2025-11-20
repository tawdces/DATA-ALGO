#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	// write your code here
	CP::queue<T> temp;
	int index=0;
	for(int i=0;i<mSize;i++){
		if(i>=pos && index<items.size()){
			temp.push(items[index]);
			index++;
		}
		temp.push(mData[(mFront+i)%mCap]);
	}
	while(index<items.size()){
		temp.push(items[index]);
		index++;
	}
	*this=temp;
}

#endif
