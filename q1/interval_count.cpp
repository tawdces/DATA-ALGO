#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> vc(n);
    for(ll i=0;i<n;i++){
        cin >> vc[i];
    }
    sort(vc.begin(),vc.end());
    while(m--){
        ll p;
        cin >> p;
        ll left=p-k;
        ll right=p+k;
        ll count=upper_bound(vc.begin(),vc.end(),right)-lower_bound(vc.begin(),vc.end(),left);
        cout << count << " ";
    }
}