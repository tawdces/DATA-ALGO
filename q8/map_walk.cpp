#include<bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<char> movechar={'A','B','C'};
vector<int> moverow={0,1,-1};
vector<int> movecol={1,0,0};

void dfs(int row,int col,string path){
    if(row==r-1 && col==c-1){
        cout << path << endl;
        return;
    }
    for(int i=0;i<3;i++){
        int newr=row+moverow[i];
        int newc=col+movecol[i];
        if(newr>=0 && newr<r && newc>=0 && newc<c && !visited[newr][newc] && graph[newr][newc]==0){
            visited[newr][newc]=true;
            dfs(newr,newc,path+movechar[i]);
            visited[newr][newc]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);   
    cin.tie(0);
    cin >> r >> c;
    graph.assign(r,vector<int>(c,0));
    visited.assign(r,vector<bool>(c,false));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> graph[i][j];
        }
    }
    visited[0][0]=true;
    dfs(0,0,"");
    cout << "DONE";
}