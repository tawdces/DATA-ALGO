#include<bits/stdc++.h>
using namespace std;

int v,e;

int findparent(vector<int> &parent,int number){
    if(parent[number]==-1){
        return number;
    }
    return parent[number]=findparent(parent,parent[number]);
}

void merge(vector<int> &parent,int x,int y){
    int s1=findparent(parent,x);
    int s2=findparent(parent,y);
    if(s1!=s2){
        parent[s1]=s2;
    }
}

bool checkcycle(vector<int> &parent,int x,int y){
    int s1=findparent(parent,x);
    int s2=findparent(parent,y);
    if(s1==s2){
        return true;
    }
    return false;
}

bool checkstraight(vector<int> &parent,vector<int> &degree,int root){
    vector<int> child;
    for(int i=0;i<v;i++){
        if(findparent(parent,i)==root){
            child.push_back(i);
        }
    }
    if(child.size()==1){
        return true;
    }
    int endcount=0;
    for(auto edge:child){
        if(degree[edge]>2){
            return false;
        }
        if(degree[edge]==1){
            endcount++;
        }
    }
    return endcount==2;
}

int main(){
    cin >> v >> e;
    vector<vector<int>> vc(v);
    vector<int> parent(v,-1);
    vector<int> degree(v,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        if(!checkcycle(parent,a,b)){
            merge(parent,a,b);
        }
        degree[a]++;
        degree[b]++;
    }
    set<int> roots; 
    for (int i=0;i<v;i++){
        roots.insert(findparent(parent,i));
    }
    int count=0;
    for(auto i:roots){
        if(checkstraight(parent,degree,i)){
            count++;
        }
    }
    cout << count;
}