#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int n,m;
    cin >> n >> m;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        ll f,s;
        cin >> f >> s;
        mp[s]=f;
    }   
    while(m--){
        ll a,b;
        cin >> a >> b;
        ll tempa=0,tempb=0;
        bool check=false;
        if(mp.find(a)!=mp.end()){
            ll next=mp[a];
            if(mp.find(next)!=mp.end()){
                tempa=mp[next];
            }
        }
        if(mp.find(b)!=mp.end()){
            ll next=mp[b];
            if(mp.find(next)!=mp.end()){
                tempb=mp[next];
            }
        }
        if(tempa==tempb && a!=b && tempa!=0 && tempb!=0){
            check=true;
        }
        if(check){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
}