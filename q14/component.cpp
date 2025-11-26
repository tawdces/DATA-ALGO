#include<bits/stdc++.h>
using namespace std;

int findparent(vector<int> &parent,int number){
    if(parent[number]==-1){
        return number;
    }
    return findparent(parent,parent[number]);
}

void merge(vector<int> &parent,int x,int y){
    int s1=findparent(parent,x);
    int s2=findparent(parent,y);
    parent[s1]=s2;
    return;
}

int checkcycle(vector<int> &parent,int x,int y){
    int s1=findparent(parent,x);
    int s2=findparent(parent,y);
    if(s1==s2){
        return true;
    }
    return false;
}

int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> vc(v+1);
    vector<int> parent(v+1,-1);
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        if(!checkcycle(parent,a,b)){
            merge(parent,a,b);
        }
    }
    int count=0;
    for(auto i:parent){
        if(i==-1){
            count++;
        }
    }
    cout << count-1;
}