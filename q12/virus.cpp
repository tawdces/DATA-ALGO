#include<bits/stdc++.h>
using namespace std;

bool recur(vector<int> &virus,int start,int len){
    if(len==2){
        return virus[start]==0 && virus[start+1]==1;
    }
    int half=len/2;
    bool normal=(recur(virus,start,half) && recur(virus,start+half,half));
    for(int i=0;i<half/2;i++){
        swap(virus[start+i],virus[start+half-1-i]);
    }
    bool revcheck=(recur(virus,start,half) && recur(virus,start+half,half));
    for(int i=0;i<half/2;i++){
        swap(virus[start+i],virus[start+half-1-i]);
    }
    return normal || revcheck;
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