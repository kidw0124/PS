#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef double ld;

using ll = long long;
using pld=pair<ld,ld>;
using pll=pair<ll,ll>;
using segment = pair<pld,pld>;
const ll n=12,m=6;
ll dx[]={0,0,1,-1},dy[]={1,-1,0,0};
vector<string>arr(12),brr;
void dfs(pll a,set<pll>&vis){
    ll i,j;
    auto [x,y]=a;
    for(i=0;i<4;i++){
        ll nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m||vis.find({nx,ny})!=vis.end()||arr[x][y]!=arr[nx][ny])continue;
        else {
            vis.insert({nx,ny});
            dfs({nx,ny},vis);
        }
    }
}

bool chk(){
    ll i,j;
    bool ret=0;
    for(i=0;i<12;i++){
        for(j=0;j<6;j++){
            set<pll>vis;
            if(arr[i][j]!='.')dfs({i,j},vis);
            else continue;
            if(vis.size()>=4){
                ret=1;
                for(auto [x,y]:vis){
                    arr[x][y]='.';
                }
            }
        }
    }
    return ret;
}

void solve()
{
    ll i,j;
    for(auto&k:arr)cin>>k;
    ll ans=0;
    while(chk()){
//        for(auto&k:arr)cout<<k<<'\n';
//        cout<<'\n';
        ans++;
        for(j=0;j<m;j++){
            for(i=11;i>=0;i--){
                if(arr[i][j]!='.'){
                    ll k=i;
                    while(k<11&&arr[k+1][j]=='.')swap(arr[k][j],arr[k+1][j]),k++;
                }

            }
        }
//        cout<<'\n';
//        for(auto&k:arr)cout<<k<<'\n';
//        cout<<'\n';
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
//    cin >> t;
    while(t--)solve();

    return 0;
}