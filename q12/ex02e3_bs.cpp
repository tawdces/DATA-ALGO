#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<m;i++){
        int number;
        cin >> number;
        int ans=-1;
        auto itr=upper_bound(v.begin(),v.end(),number);
        ans=ans+(itr-v.begin());
        cout << ans << endl;
    }
}