#include <bits/stdc++.h>
using namespace std;

const int MOD=1000003;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> S(k);
    for(int i=0;i<k;i++){
        cin >> S[i];
    }
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int s:S){
            if(i-s>=0){
                dp[i]=(dp[i]+dp[i-s])%MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
