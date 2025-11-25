#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vc(46);
    vc[0]=0;
    vc[1]=1;
    vc[2]=1;
    for(int i=3;i<=45;i++){
        vc[i]=vc[i-1]+vc[i-2];
    }
    int n;
    cin >> n;
    cout << vc[n];
}
