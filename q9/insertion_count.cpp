#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> A(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        int sum=0;
        for(int j=0;j<n;j++){
            if(A[j]==k){
                break;
            }
            else if(A[j]>k){
                sum++;
            }
        }
        cout << sum << endl;
    }
}