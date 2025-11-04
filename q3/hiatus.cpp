#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> y_m;
    for(int i=0;i<n;i++){
        int year,month;
        cin >> year >> month;
        y_m.push_back({year,month});
    }
    sort(y_m.begin(),y_m.end());
    for(int i=0;i<m;i++){
        int qy,qm;
        cin >> qy >> qm;
        pair<int,int> q={qy,qm};
        auto it=upper_bound(y_m.begin(),y_m.end(),q);
        if(binary_search(y_m.begin(),y_m.end(),q)){
            cout << "0 0 ";
        }
        else if(it==y_m.begin()){
            cout << "-1 -1 ";
        }
        else{
            it--;
            cout << (*it).first << " " << (*it).second << " ";
        }
    }
}