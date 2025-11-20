#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,D,T,Z;
    cin >> N >> D >> T >> Z;
    vector<priority_queue<int,vector<int>,greater<int>>> dungeon(Z);
    for(int i=0;i<D;i++){
        int t,z;
        cin >> t >> z;
        dungeon[z].push(t);
    }
    int count=0;
    int indexboss=0;
    for(int i=0;i<N;i++){
        int q;
        cin >> q;
        vector<int> artifact(q);
        for(int j=0;j<q;j++){
            cin >> artifact[j];
        }
        bool check=true;
        for(int k:artifact){
            if(dungeon[k].empty()){
                check=false;
                break;
            }
            int cost=dungeon[k].top();
            dungeon[k].pop();
            T-=cost;
            if(T<0){
                check=false;
                break;
            }
        }
        if(!check){
            break;
        }
        count++;
    }
    cout << count;
}