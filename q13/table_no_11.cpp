#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vc(10000001);
    vc[0]=0;
    vc[1]=0;
    vc[2]=7;
    vc[3]=17;
    for(int i=4;i<=10000000;i++){
        vc[i]=(2*vc[i-1]+vc[i-2])%100000007;
    }
    int n;
    cin >> n;
    cout << vc[n];
}
