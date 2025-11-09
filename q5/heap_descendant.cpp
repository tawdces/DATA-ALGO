#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n >> a;
    vector<int> descendants;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        descendants.push_back(u);
        int left=2*u+1;
        int right=2*u+2;
        if(left<n){
            q.push(left);
        }
        if(right<n){
            q.push(right);
        }
    }
    sort(descendants.begin(),descendants.end());
    cout << descendants.size() << "\n";
    for(int i=0;i<descendants.size();i++){
        if(i){
            cout << " ";
        }
        cout << descendants[i];
    }
    cout << "\n";
}
