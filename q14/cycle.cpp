#include<bits/stdc++.h>
using namespace std;

bool check(int n,vector<vector<int>>& vc){
    for(int i=0;i<n;i++){
        vector<int> visited(n,0);
        vector<int> parent(n,-1);
        queue<int> q;
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
            int from=q.front();
            q.pop();
            for(auto to:vc[from]){
                if(!visited[to]){
                    visited[to]=1;
                    parent[to]=from;
                    q.push(to);
                }
                else if(visited[to] && to!=parent[from]){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,e;
        cin >> n >> e;
        if(e==0){
            cout << "NO" << endl;
            continue;
        }
        vector<vector<int>> vc(n);
        while(e--){
            int from,to;
            cin >> from >> to;
            vc[from].push_back(to);
            vc[to].push_back(from);
        }
        if(check(n,vc)){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
}