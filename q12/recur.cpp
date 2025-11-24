#include<bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &v,int a,int b,int r,int c){
    if(a==0){
        v[r][c]=b;
        return;
    }
    int size=1<<(a-1);
    recur(v,a-1,b,r,c);
    recur(v,a-1,b-1,r,c+size);
    recur(v,a-1,b+1,r+size,c);
    recur(v,a-1,b,r+size,c+size);
}

int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<int>> v(1<<a,vector<int>(1<<a,0));
    recur(v,a,b,0,0);
    for(auto i:v){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}