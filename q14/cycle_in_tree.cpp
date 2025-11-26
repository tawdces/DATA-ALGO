#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<set<int>> adj(n);
	for(int i=0;i<n;i++) {
		int a,b; 
        cin >> a >> b;
		adj[a].insert(b); 
        adj[b].insert(a);
	}
	queue<int> q;
	for(int i=0;i<n;i++){
        if(adj[i].size()==1){
            q.push(i);
        }
    }
	int ans=n;
	while(!q.empty()){
		int v=q.front(); 
        q.pop();	
        ans--;
		int u=*adj[v].begin();
		adj[u].erase(v); 
        adj[v].clear();
		if(adj[u].size()==1){
            q.push(u);
        }
	}
	cout << ans;
}