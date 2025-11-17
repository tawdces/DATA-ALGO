#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> graph;

void dfs(int index,int count,int maxcount){
    if(index==n){
        if(maxcount>=k){
            for(int i=0;i<n;i++){
                cout << graph[i];
            }
            cout << endl;
        }
        return;
    }
    graph[index]=0;
    dfs(index+1,0,maxcount);
    graph[index]=1;
    dfs(index+1,count+1,max(maxcount,count+1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    graph.assign(n,0);
    dfs(0,0,0);
}