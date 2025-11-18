#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<long long,long long>> arr(N);
    for(int i=0;i<N;i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());
    vector<long long> prefix(N);
    prefix[0] = arr[0].second;
    for(int i=1;i<N;i++)
        prefix[i] = prefix[i-1] + arr[i].second;

    while(Q--) {
        long long p;
        cin >> p;
        int idx = lower_bound(prefix.begin(), prefix.end(), p) - prefix.begin();
        cout << arr[idx].first << "\n";
    }
}
