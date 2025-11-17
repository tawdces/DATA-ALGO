#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> indeg;
vector<int> permu;
vector<int> used;

void dfs(int index){
    if(index==n){
        for(int i=0;i<n;i++){
            cout << permu[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i] && indeg[i]==0){
            used[i]=1;
            permu[index]=i;
            for(auto j:graph[i]){
                indeg[j]--;
            }
            dfs(index+1);
            for(auto j:graph[i]){
                indeg[j]++;
            }
            used[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    graph.assign(n,{});
    indeg.assign(n,0);
    permu.assign(n,-1);
    used.assign(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }
    dfs(0);
}