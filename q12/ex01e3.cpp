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
        auto itr=upper_bound(v.begin(),v.end(),number);
        if(itr!=v.begin()){
            itr--;
            cout << *itr;
        }
        else{
            cout << -1;
        }
        cout << endl;
    }
}