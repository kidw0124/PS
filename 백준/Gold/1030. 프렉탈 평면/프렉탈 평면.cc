#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

//ll n;
//vector<ll>arr;
//void func(ll rsum, ll sum, ll now, vector<vector<vector<ll>>>&a,vector<ll>b){
//    if(now==n-1){
//        for(ll i=0;i<=min(sum,arr[now]);i++){
//            b.push_back(i);
//            a[rsum+i].push_back(b);
//            b.pop_back();
//        }
//    }
//    else{
//        for(ll i=0;i<=min(sum,arr[now]);i++){
//            b.push_back(i);
//            func(rsum+i, sum-i,now+1,a,b);
//            b.pop_back();
//        }
//    }
//}

ll s,n,k,r1,r2,c1,c2;

bool isin(ll x, ll y, ll lev){
    return lev/n * (n-k)/2 <= x &&
            lev/n * (n+k)/2 > x &&
            lev/n * (n-k)/2 <= y &&
            lev/n * (n+k)/2 > y;
}

bool chk(ll x,ll y,ll lev){
    if(lev==1)return 0;
    if(isin(x,y,lev)){
        return 1;
    }
    else{
        return chk(x%(lev/n),y%(lev/n),lev/n);
    }
}

void solve(){
    ll i,j;
    cin>>s>>n>>k>>r1>>r2>>c1>>c2;
    ll tot=1;
    for(i=0;i<s;i++)tot*=n;
    for(i=r1;i<=r2;i++){
        for(j=c1;j<=c2;j++){
            cout<<chk(i,j,tot);
        }
        cout<<'\n';
    }
}

int main() {
    setup();
    ll t=1;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve();
    }
    return 0;
}
