#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>> tmp;
    while(!a.empty()){
        auto vc=a.top();
        a.pop();
        for(auto &i:vc){
            std::queue<int> q;
            while(!i.empty()){
                auto number=i.front();
                i.pop();
                if(number==from){
                    number=to;
                }
                q.push(number);
            }
            i=q;
        }
        tmp.push(vc);
    }
    while(!tmp.empty()){
        a.push(tmp.top());
        tmp.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto &i:a){
        auto &value_first=i.second.first;
        auto &value_second=i.second.second;
        std::priority_queue<int> temp;
        while(!value_first.empty()){
            auto number=value_first.top();
            value_first.pop();
            if(number==from){
                number=to;
            }
            temp.push(number);
        }
        value_first=temp;
        if(value_second==from){
            value_second=to;
        }
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::vector<std::pair<std::list<int>,std::map<int,std::pair<int,string>>>> to_add;
    std::vector<std::pair<std::list<int>,std::map<int,std::pair<int,string>>>> to_remove;
    for(auto &i:a){
        auto copy_i=i;
        for(auto &num:copy_i.first){
            if(num==from){
                num=to;
            }
        }
        std::map<int, std::pair<int, string>>  tempmp;
        for(auto &kv:copy_i.second){
            auto key=kv.first;
            auto value=kv.second;
            if(key==from){
                key=to;
            }
            if(value.first==from){
                value.first=to;
            }
            tempmp[key]=value;
        }
        copy_i.second=tempmp;
        to_remove.push_back(i);
        to_add.push_back(copy_i);
    }
    for(auto &x:to_remove){
        a.erase(x);
    }
    for(auto &x:to_add){
        a.insert(x);
    }
}

#endif
