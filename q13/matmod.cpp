#include <bits/stdc++.h>
using namespace std;

vector<int> mul(const vector<int> &A, const vector<int> &B, int k) {
    vector<int> R(4);
    R[0]=((A[0]*B[0])%k+(A[1]*B[2])%k)%k;
    R[1]=((A[0]*B[1])%k+(A[1]*B[3])%k)%k;
    R[2]=((A[2]*B[0])%k+(A[3]*B[2])%k)%k;
    R[3]=((A[2]*B[1])%k+(A[3]*B[3])%k)%k;
    return R;
}

vector<int> power(vector<int> base,long long n,int k){
    vector<int> result={1,0,0,1};
    while(n>0){
        if(n&1){
            result=mul(result,base,k);
        }
        base=mul(base,base,k);
        n>>=1;
    }
    return result;
}

int main(){
    long long n;
    int k;
    cin >> n >> k;
    vector<int> A(4);
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    vector<int> R=power(A,n,k);
    cout << R[0] << " " << R[1] << " " << R[2] << " " << R[3];
}
