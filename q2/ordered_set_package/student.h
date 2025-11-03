#include <vector>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<T> u_s;
    for(auto i:A){
        v.push_back(i);
        u_s.insert(i);
    }
    for(auto i:B){
        if(u_s.find(i)==u_s.end()){
            v.push_back(i);
            u_s.insert(i);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<T> u_s(B.begin(),B.end());
    for(auto i:A){
        if(u_s.find(i)!=u_s.end()){
            v.push_back(i);
        }
    }
    return v;
}
