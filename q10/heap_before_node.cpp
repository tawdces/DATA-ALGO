#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    queue<int> q;
    int size=n;
    q.push(m);
    mp[m]=1;
    size--;
    while(!q.empty()){
        int number=q.front();
        q.pop();
        int left=number*2+1;
        int right=number*2+2;
        if(left<n){
            q.push(left);
            mp[left]=1;
            size--;
        }
        if(right<n){
            q.push(right);
            mp[right]=1;
            size--;
        }
    }
    if(m==0){
        cout << 0;
        return 0;
    }
    cout << size << endl;
    for(int i=0;i<n;i++){
        if(mp[i]!=1){
            cout << i << " ";
        }
    }
}