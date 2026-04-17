#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> pl[21];

vector<bool> mmi(21,true);

int n;
int arr[10][10];

int dfs(int a){
    if(a>2*n-2){
        return 0;
    }
    int ma=dfs(a+2);
    for(int i=0;i<pl[a].size();i++){
        int x=pl[a][i].first,y=pl[a][i].second;
        if(arr[x][y]==0||mmi[x-y+n]==0)continue;
        else{
            mmi[x-y+n]=0;
            ma=max(ma, 1 + dfs(a+2));
            mmi[x-y+n]=1;
        }
    }
    return ma;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            pl[i+j].push_back({i,j});
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<dfs(0)+dfs(1);
}