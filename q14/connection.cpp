#include<bits/stdc++.h>
using namespace std;

int n,e,k;
int mx=INT_MIN;
vector<vector<int>> vc;

void bfs(int node){
    vector<int> distance(n,INT_MAX);
    queue<int> q;
    int count=1;
    q.push(node);
    distance[node]=0;
    while(!q.empty()){
        int from=q.front();
        q.pop();
        if(distance[from]>=k){
            continue;
        }
        for(auto to:vc[from]){
            if(distance[to]>distance[from]+1){
                distance[to]=distance[from]+1;
                q.push(to);
                count++;
            }
        }
    }
    mx=max(mx,count);
}

int main(){
    cin >> n >> e >> k;
    vc.resize(n);
    for(int i=0;i<e;i++){
        int from,to;
        cin >> from >> to;
        vc[from].push_back(to);
        vc[to].push_back(from);
    }
    for(int i=0;i<n;i++){
        bfs(i);
    }
    cout << mx;
}