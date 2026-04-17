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
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

void preprocess(){
    ll i,j,k;

}

void solve(ll testcase){
    ll i,j,k;
    ll a,b,c,d;
    for(a=1;a<=100;a++){
        for(b=2;b<=100;b++){
            for(c=b;c<=100;c++){
                for(d=c;d<=100;d++){
                    if(a*a*a==b*b*b+c*c*c+d*d*d){
                        cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")\n";
                    }
                }
            }
        }
    }

}

int main(){
    setup();
    preprocess();
    ll t,tc=1;
//    cin>>tc;
    for(t=1;t<=tc;t++){
        solve(t);
    }
    return 0;
}
