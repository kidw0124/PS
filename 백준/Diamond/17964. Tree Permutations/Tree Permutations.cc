#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

int main() {
    setup();
    ll i, j;
    ll n,sum=0,m=0;
    cin>>n;
    ll now=2*n-2,fro=0;
    vector<ll>arr(2*n-2);
    vector<bool>vis(2*n-2);
    set<ll>st;
    multiset<ll>mst;
    for(i=0;i<2*n-2;i++){
        cin>>arr[i];
        st.insert(arr[i]);
        mst.insert(arr[i]);
    }
    std::sort(arr.begin(), arr.end());
    for(i=0;i<n;i++){
        if(arr[i]>i+1){
            for(j=1;j<n;j++)cout<<"-1 ";
            return 0;
        }
        else if(i+1==arr[i]){
            st.erase(arr[i]);
            mst.erase(mst.find(arr[i]));
            m++;
        }
    }
    for(i=1;i<=m-1;i++)cout<<"-1 ";
    ll cnt=0;
    auto rit=mst.rbegin();
    multiset<ll>ans;
    while(cnt++<m){
        sum+=*rit;
        ans.insert(*rit);
        mst.erase(mst.find(*rit));
        rit=mst.rbegin();
    }
    cout<<sum<<' ';
    i++;
    for(auto k:st){
        if(mst.find(k)==mst.end()){
            ans.erase(ans.find(k));
            sum-=k;
            sum+=*rit;
            ans.insert(*rit);
            mst.erase(mst.find(*rit));
            rit=mst.rbegin();
        }
        else{
            mst.erase(mst.find(k));
            rit=mst.rbegin();
        }
        sum+=*rit;
        ans.insert(*rit);
        mst.erase(mst.find(*rit));
        rit=mst.rbegin();
        cout<<sum<<' ';
        i++;
    }
    for(;i<n;i++)cout<<"-1 ";
}