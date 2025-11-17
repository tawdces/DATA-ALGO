#include<bits/stdc++.h>
using namespace std;

int a,b;
vector<int> graph;

void dfs(int index,int count){
    if(index==b){
        if(count==a){
            for(int i=b-1;i>=0;i--){
                cout << graph[i];
            }
            cout << endl;
        }
        return;
    }
    if(count<a){
        graph[index]=1;
        dfs(index+1,count+1);
    }
    graph[index]=0;
    dfs(index+1,count);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    graph.assign(b,0);
    dfs(0,0);
}