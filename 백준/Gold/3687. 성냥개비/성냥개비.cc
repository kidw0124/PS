#include<bits/stdc++.h>
using namespace std;
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
#define INT_MAX (ll)2147483647*2147483647

int main(){
    setup();
    ll i,j;
    ll t,n;
    cin>>t;
    vector<ll>arr({INT_MAX,INT_MAX/10,1,7,4,2,6,8});
    arr.resize(105,INT_MAX);
    for(i=8;i<101;i++){
        for(j=2;j<8;j++){
            if(j==6){
                arr[i]=min(arr[i],arr[i-6]*10);
            }
            else{
                arr[i]=min(arr[i],arr[i-j]*10+arr[j]);
            }
        }
    }
    while(t--){
        cin>>n;
        cout<<arr[n]<<' ';
        if(n&1){
            cout<<7;
            n-=3;
        }
        for(i=0;i<n;i+=2)cout<<1;
        cout<<'\n';
    }


    return 0;
}
