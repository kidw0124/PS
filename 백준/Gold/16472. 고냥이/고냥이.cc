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
typedef long double ld;
typedef __float128 LD;
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

ll mod=123456789;

void solve() {
    ll i, j;
    ll n,m;
    cin>>n;
    string str;
    cin>>str;
    vector<ll>arr(26);
    ll st=0,en=0,ans=0,cnt=0;
    while(en<=str.size()){
        while(en<=str.size()){
            if(arr[str[en]-'a']==0)cnt++;
            arr[str[en]-'a']++;
            if(cnt>n){
                ans=max(ans,en-st);
                en++;
                break;
            }
            ans=max(ans,en-st);
            en++;
        }
        if(en==str.size()&&cnt<=n)ans=max(ans,en-st);
        while(st<en){
            arr[str[st]-'a']--;
            if(arr[str[st]-'a']==0){
                cnt--;
                st++;
                break;
            }
            st++;
        }
    }
    cout<<ans;
//    cin>>n;
//    vector<bool>sieve(n+1,true);
//    vector<ll>primes;
//    sieve[0]=sieve[1]=0;
//    for(i=2;i<=n;i++){
//        if(sieve[i]){
//            primes.push_back(i);
//            for(j=i*i;j<=n;j+=i){
//                sieve[j]=false;
//            }
//        }
//    }
//    vector<ll>dp(n+1);
//    dp[0]=1;
//    // cout<<primes.size();
//    for(i=0;i<primes.size();i++){
//        for(j=n;j>=1;j--){
//            for(ll k=j/primes[i]*primes[i];k>=1;k-=primes[i]){
//                dp[j]+=dp[j-k];
//                dp[j]%=mod;
//            }
//        }
//    }
//    cout<<dp[n];

}

int main() {
    setup();
    ll t=1;
//    cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve();
    }
    return 0;
}
