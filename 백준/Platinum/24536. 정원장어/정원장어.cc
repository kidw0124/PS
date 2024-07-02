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
    vector<ll>org(n),arr,brr;
    string str;
    cin>>str;
    for(i=0;i<n;i++){
        cin>>org[i];
        if(str[i]=='L')arr.push_back(org[i]);
        else brr.push_back(org[i]);
    }
    reverse(all(brr));
    //ret[i]: lis of arr[0~i] on nlogn
    auto lis=[](vector<ll>&arr){
        vector<ll>ret;
        vector<ll>ret2;
        ret2.push_back(0);
        for(auto x:arr){
            auto it=lower_bound(all(ret),x);
            if(it==ret.end())ret.push_back(x);
            else *it=x;
            ret2.push_back(ret.size());
        }
        return ret2;
    };
    auto lisa=lis(arr);
    auto lisb=lis(brr);
    vector<ll>ans(n);
    j=0;
    for(i=0;i<n;i++){
        if(str[i]=='L'){
            j++;
        }
        ans[i]=lisa[j];
    }
    j=0;
    for(i=n-1;i>=0;i--){
        if(str[i]=='R'){
            j++;
        }
        ans[i]+=lisb[j];
    }
    cout<<n-*max_element(all(ans))<<'\n';

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