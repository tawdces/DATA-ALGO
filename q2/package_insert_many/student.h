#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <bits/stdc++.h>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
    auto n=this->size();
    auto m=data.size();
    CP::vector<T> new_v(n+m);
    std::sort(data.begin(),data.end(),[](const std::pair<int,T> &a, const std::pair<int,T> &b){
        return a.first < b.first;
    });
    int old_idx=0,new_idx=0,data_idx=0;
    while(new_idx<new_v.size()){
        if(data_idx<m && new_idx==(int)data[data_idx].first+data_idx){
            new_v[new_idx]=data[data_idx].second;
            new_idx++;
            data_idx++;
        } 
        else{
            new_v[new_idx]=(*this)[old_idx];
            new_idx++;
            old_idx++;
        }
    }
    *this=new_v;
}

#endif
