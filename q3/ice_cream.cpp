#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,start;
    cin >> n >> m >> start;
    ll MAXD=100000;
    vector<ll> money(MAXD+1,-1);
    money[0]=start;
    while(n--){
        ll a,s;
        cin >> a >> s;
        money[a]=s;
    }
    for(ll i=1;i<=MAXD;i++){
        if(money[i]==-1){
            money[i]=money[i-1];
        }
    }
    vector<ll> prefixsum(MAXD+1,-1);
    prefixsum[0]=money[0];
    for(ll i=1;i<=MAXD;i++){
        prefixsum[i]=prefixsum[i-1]+money[i];
    }
    vector<ll> answer;
    while(m--){
        ll p,x;
        cin >> p >> x;
        auto it=lower_bound(prefixsum.begin(),prefixsum.end(),p);
        ll d=MAXD+1;
        if(it!=prefixsum.end()){
            d=it-prefixsum.begin();
        }
        if(d<=x){
            answer.push_back(d);
        }
        else{
            ll newmoney=p+prefixsum[x];
            auto newit=lower_bound(prefixsum.begin(),prefixsum.end(),newmoney);
            ll newd=MAXD+1;
            if(newit!=prefixsum.end()){
                newd=newit-prefixsum.begin();
            }
            answer.push_back(newd);
        }
    }
    for(ll i=0;i<answer.size();i++){
        cout << answer[i] << " ";
    }
}