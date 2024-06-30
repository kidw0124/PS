
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

//constexpr ll mod=998244353;

ll ans(vector<ll>arr,ll st){
    ll n=arr.size();
    ll i,j,k;
    ll ret=0;
    for(i=st;i<n-1;i++){
        if(arr[i]==i+1){
            ret=max(ret,ans(arr,i+1));
            vector<ll>tmp(arr.begin(),arr.begin()+i);
            for(j=i+2;j<n;j++)tmp.push_back(arr[j]);
            ret=max(ret,1+ans(tmp,i+1));
            if(arr[i+1]==i+2 && i+2<n){
                tmp=vector<ll>(arr.begin(),arr.begin()+i+1);
                for(j=i+3;j<n;j++)tmp.push_back(arr[j]);
                ret=max(ret,1+ans(tmp,i-1));
            }
        }
    }
//    for(auto x:arr)cout<<x<<" ";
//    cout<<"\n"<<st<<" "<<ret<<"\n";

    return ret;
}

void solve(){
    ll i,j,k;
    ll n;
    cin>>n;
    auto matrix_mult=[&](vector<vector<ll>> a,vector<vector<ll>> b){
        vector<vector<ll>>ret(2,vector<ll>(2));
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                ret[i][j]=0;
                for(k=0;k<2;k++){
                    ret[i][j]+=a[i][k]*b[k][j];
                    ret[i][j]%=10;
                }
            }
        }
        return ret;
    };
    auto matrix_pow=[&](vector<vector<ll>>a,ll x){
        vector<vector<ll>>ret(2,vector<ll>(2));
        ret[0][0]=ret[1][1]=1;
        ret[0][1]=ret[1][0]=0;
        while(x){
            if(x&1)ret=matrix_mult(ret,a);
            a=matrix_mult(a,a);
            x>>=1;
        }
        return ret;
    };
    auto get_fibo=[&](ll x){
        vector<vector<ll>>ret(2,vector<ll>(2));
        ret[0][0]=ret[0][1]=ret[1][0]=1;
        ret=matrix_pow(ret,x);
        return ret[0][1];
    };
    cout<<(get_fibo(n+1)+get_fibo(n-1))%10<<"\n";
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