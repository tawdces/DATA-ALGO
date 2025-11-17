#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans=INT_MAX;
vector<bitset<1000>> graph;
bitset<1000> check;

void dfs(int index,int count){
    if(count>=ans){
        return;
    }
    if(check.count()==n){
        ans=min(count,ans);
        return;
    }
    if(index==m){
        return;
    }
    bitset<1000> tempcheck=check;
    check|=graph[index];
    dfs(index+1,count+1);
    check=tempcheck;
    dfs(index+1,count);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    graph.assign(m,bitset<1000>());
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int day;
            cin >> day;
            graph[i].set(day-1);
        }
    }
    dfs(0,0);
    cout << ans;
}