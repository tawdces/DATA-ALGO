#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        mp[number]++;
    }
    bool check=false;
    for(int i=1;i<=n;i++){
        if(mp[i]!=1){
            break;
        }
        if(i==n){
            check=true;
        }
    }
    if(check==true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}