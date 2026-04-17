#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void solve(){
    ll i,j;
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n,vector<ll>(n));
    vector<ll>row,col;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(i=0;i<n;i++){
        bitset<100>bs;
        for(j=0;j<n;j++){
            bs[arr[i][j]]=1;
        }
        if(bs.count()==n){
            row.push_back(i);
        }
        bs.reset();
        for(j=0;j<n;j++){
            bs[arr[j][i]]=1;
        }
        if(bs.count()==n){
            col.push_back(i);
        }
    }
    bool swapped=0;
    vector<tuple<ll,ll,ll>>ans;
    if(col.size()>row.size()){
        swapped=1;
        for(i=0;i<n;i++){
            for(j=0;j<i;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        swap(row,col);
    }
    for(i=0;i<row.size();i++){
        if(i<col.size()){
            auto [r,c]=pll(row[i],col[i]);
            if(c<1){
                ans.push_back({r,c,arr[r][c+1]});
                arr[r][c]=arr[r][c+1];
            }
            else{
                ans.push_back({r,c,arr[r][c-1]});
                arr[r][c]=arr[r][c-1];
            }
        }
        else{
            auto [r,c]=pll(row[i],1);
            ll v=arr[r][c-1];
            for(j=0;j<n;j++){
                if(arr[j][c]==v && j!=r)break;
            }
            if(j==n){
                v=arr[r][c+1];
            }
            ans.push_back({r,c,v});
            arr[r][c]=v;
        }
    }
    cout<<ans.size()<<'\n';
    if(swapped){
        for(auto [c,r,v]:ans){
            cout<<r+1<<' '<<c+1<<' '<<v<<'\n';
        }
    }
    else{
        for(auto [r,c,v]:ans){
            cout<<r+1<<' '<<c+1<<' '<<v<<'\n';
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)solve();
}