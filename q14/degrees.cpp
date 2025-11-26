#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> vc(n,vector<int>(n));
    map<int,int> degree;
    int temp=INT_MIN;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            cin >> vc[i][j];
            if(vc[i][j]==1){
                count++;
            }
        }
        degree[count]++;
        temp=max(temp,count);
    }
    for(int i=0;i<=temp;i++){
        cout << degree[i] << " ";
    }
}