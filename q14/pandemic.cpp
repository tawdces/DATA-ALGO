#include<bits/stdc++.h>
using namespace std;

vector<int> x={0,-1,0,1};
vector<int> y={-1,0,1,0};

// left top right bottom
// (0,-1) (-1,0) (0,1) (1,0);

int main() {
    int r,c,t;
    cin >> r >> c >> t;
    vector<vector<int>> vc(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> vc[i][j];
        }
    }
    while(t--){
        vector<vector<int>> temp=vc;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vc[i][j]==1){
                    for(int k=0;k<4;k++){
                        int newi=i+x[k];
                        int newj=j+y[k];
                        if(newi>=0 && newi<r && newj>=0 && newj<c && vc[newi][newj]!=2){
                            temp[newi][newj]=1;
                        }
                    }
                }
            }
        }
        vc=temp;
    }
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
           if(vc[i][j]==1){
            count++;
           }
        //    cout << vc[i][j] << " ";
        }
        // cout << endl;
    }
    cout << count;
}