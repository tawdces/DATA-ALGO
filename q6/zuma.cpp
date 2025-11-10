#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int>
#define ll long long
#define pb push_back
#define pf push_front

void fileIO(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    //fileIO("");
    int n, k, v;
    cin >> n >> k >> v;
    list<int> l;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.push_back(x);
    }
    auto it_r = l.begin();
    advance(it_r, k);
    auto it_l = it_r;
    bool fnd = false;
    int val = v;
    do {
        while(it_r != l.end() && *it_r == val) it_r++;
        while(it_l != l.begin() && *prev(it_l) == val) it_l--;
        int cnt = distance(it_l, it_r) + (fnd == false);
        if(cnt >= 3) {
            fnd = true;
            l.erase(it_l, it_r);
        }
        else break;

        it_l = it_r;
        if(it_l == l.begin() || it_r == l.end()) break;
        val = *(--it_l);
        if(val != *it_r) break;

    }while(true);

    if(!fnd) l.insert(it_r, v);

    for(int i : l) cout << i << ' ';
}