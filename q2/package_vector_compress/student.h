#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    T* newdata=new T[mSize];
    for(auto i=0;i<mSize;i++){
        newdata[i]=mData[i];
    }
    delete[] mData;
    mData=newdata;
    mCap=mSize;
}

#endif
