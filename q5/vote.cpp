#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<string,int> mp;
    int n,k;
    cin >> n >> k;
    while(n--){
        string str;
        cin >> str;
        mp[str]++;
    }
    vector<pair<string,int>> vc(mp.begin(),mp.end());
    sort(vc.begin(),vc.end(),[](const auto &a,const auto &b){
        return a.second>b.second;
    });
    if(k>vc.size()){
        cout << vc[vc.size()-1].second;
    }
    else{
        cout << vc[k-1].second;
    }
}