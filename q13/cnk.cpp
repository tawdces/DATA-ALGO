#include <bits/stdc++.h>
using namespace std;

int combi(int n,int k){
    if(n==k || k==0){
        return 1;
    }
    return combi(n-1,k-1)+combi(n-1,k);
}

int main(){
    int n,k;
    cin >> n >>k;
    cout << combi(n,k);
}
