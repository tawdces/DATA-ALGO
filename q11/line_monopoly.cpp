#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int,int> mp;
    while(n--){
        int mode;
        cin >> mode;
        if(mode==1){
            int l,r;
            cin >> l >> r;
            auto itr=mp.lower_bound(l);
            if(itr!=mp.begin()){
                auto prev=itr;
                prev--;
                if(prev->second>=l-1){
                    l=min(l,prev->first);
                    r=max(r,prev->second);
                    itr=mp.erase(prev);
                }
            }
            while(itr!=mp.end() && itr->first<=r+1){
                l=min(l,itr->first);
                r=max(r,itr->second);
                itr=mp.erase(itr);
            }
            mp[l]=r;
        }
        else if(mode==2){
            cout << mp.size() << "\n";
        }
    }
}