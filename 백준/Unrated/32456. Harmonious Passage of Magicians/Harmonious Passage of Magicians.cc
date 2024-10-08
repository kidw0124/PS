#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll,ll>;
const ll mod = 1e10;
ll n,m;
vector<ll>ans;
vector<ll>quo;
vector<ll>now;

void solve2() {
    ll i,j;
    cin>>n>>m;
    now.resize(n+m+1);
    quo.resize(n+m+1);
    for(i=0;i<n;i++)now[i]=i+1;
    for(i=n+1;i<n+m+1;i++){
        now[i]=i;
    }
    for(i=0;i<m;i++)quo[i]=i+n+1;
    quo[m]=0;
    for(i=m+1;i<n+m+1;i++){
        quo[i]=i-m;
    }
    ll blank=n;
    while(1){
        if(blank>1 && now[blank-2]<=n && now[blank-1]>n){
            ans.push_back(now[blank-2]);
            now[blank]=now[blank-2];
            now[blank-2]=0;
            blank=blank-2;
        }
        else if(blank<n+m-1 && now[blank+2]>n && now[blank+1]<=n){
            ans.push_back(now[blank+2]);
            now[blank]=now[blank+2];
            now[blank+2]=0;
            blank=blank+2;
        }
        else if(blank>0 && blank<n+m && now[blank-1]<=n && now[blank+1]>n){
            if(blank<2 || now[blank-2]<=n){
                ans.push_back(now[blank-1]);
                now[blank]=now[blank-1];
                now[blank-1]=0;
                blank=blank-1;
            }
            else{
                ans.push_back(now[blank+1]);
                now[blank]=now[blank+1];
                now[blank+1]=0;
                blank=blank+1;
            }
        }
        else if(blank>0&& now[blank-1]<=n){
            ans.push_back(now[blank-1]);
            now[blank]=now[blank-1];
            now[blank-1]=0;
            blank=blank-1;
        }
        else if(blank<n+m&& now[blank+1]>n){
            ans.push_back(now[blank+1]);
            now[blank]=now[blank+1];
            now[blank+1]=0;
            blank=blank+1;
        }
        else break;
    }
    for(auto k:ans){
        cout<<k<<' ';
    }
    cout<<'\n';
    ans.clear();


}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ll t;
    cin>>t;
    while(t--)solve2();
}