#include<bits/stdc++.h>
using namespace std;

bool recur(vector<int> &virus,int start,int len){
    if(len==2){
        return true;
    }
    int half=len/2;
    int counta=0,countb=0;
    for(int i=0;i<half;i++){
        counta=counta+virus[start+i];
    }
    for(int i=half;i<len;i++){
        countb=countb+virus[start+i];
    }
    if(abs(counta-countb)>1){
        return false;
    }
    return (recur(virus,start,half) && recur(virus,start+half,half));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        vector<int> virus(1<<k);
        for(int j=0;j<(1<<k);j++){
            int code;
            cin >> virus[j];
        }
        if(recur(virus,0,virus.size())){
            cout << "yes";
        }
        else{
            cout << "no";
        }
        cout << endl;
    }
}