#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> vc(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> vc[i][j];
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=0;i+k<n && j+k<n;k++){
                sum+=vc[i+k][j+k];
                mx=max(mx,sum);
            }
        }
    }
    cout << mx;
}