#ifndef _STUDENT_H_
#define _STUDENT_H_
#include<bits/stdc++.h>
// you can also include anything else here

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  std::vector<size_t> r;
  //write your code here
  std::vector<int> mem;
  for(auto i:data){
    mem.push_back(i.second);
  }
  std::sort(mem.begin(),mem.end());
  for(auto i:queries){
    auto s=std::lower_bound(mem.begin(),mem.end(),i.first);
    auto e=std::upper_bound(mem.begin(),mem.end(),i.second);
    r.push_back(e-s);
  }
  
  return r;
}

#endif
