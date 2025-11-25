#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> A(n+1);
    A[0]=0;
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    for(int i=1;i<=n;i++){
        A[i]=A[i]+A[i-1]+k;
    }
    while(m--){
        int a,b;
        cin >> a >> b;
        auto itr=upper_bound(A.begin(),A.end(),b+A[a]);
        if(itr==A.begin()+1){
            cout << 0 << endl;
            continue;
        }
        itr--;
        cout << *itr-A[a]-((itr-A.begin()-a)*k) << endl;
    }
}