#include<bits/stdc++.h>
using namespace std;
#ifdef ATCODER
#include<atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

void yes(){
    cout<<"Yes\n";
}

void no(){
    cout<<"No\n";
}

void preprocess(){

}

constexpr ll mod=998244353;

void solve(){
    ll i,j,k;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(auto &x:arr)cin>>x;
    sort(all(arr));
    for(i=0;i+1<n;i++){
        if(arr[i]+1==arr[i+1]){
            vector<ll>::iterator it;
            if((it=find_if(arr.begin(), arr.end(),[&](ll x){
                return arr[i+1]<x;
            }))!=arr.end()){
                swap(arr[i+1],*it);
            }
            else{
                ll now=i;
                while(now>=0 && arr[now]==arr[i])now--;
                ll now2=i+1;
                while(now2<n && arr[now2]==arr[i+1])now2++;
                vector<ll>tmp(arr.begin(),arr.begin()+now+1);
                tmp.insert(tmp.end(),arr.begin()+i+1,arr.begin()+now2);
                tmp.insert(tmp.end(),arr.begin()+now+1,arr.begin()+i+1);
                tmp.insert(tmp.end(),arr.begin()+now2,arr.end());
                arr=tmp;
            }
        }
    }
    for(auto x:arr)cout<<x<<' ';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
#ifdef kidw0124
    clock_t st=clock();
#endif
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}