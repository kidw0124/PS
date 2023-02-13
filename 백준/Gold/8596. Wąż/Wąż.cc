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

map<char,pll>dir({{'N',{-1,0}},{'S',{1,0}},{'W',{0,-1}},{'E',{0,1}}});

pll operator+(const pll&a,const pll&b){
    return {a.first+b.first,a.second+b.second};
}

char turn_right(char x){
    switch (x) {
        case 'N':
            return 'E';
        case 'E':
            return 'S';
        case 'S':
            return 'W';
        case 'W':
            return 'N';
    }
}
char turn_left(char x){
    switch (x) {
        case 'E':
            return 'N';
        case 'S':
            return 'E';
        case 'W':
            return 'S';
        case 'N':
            return 'W';
    }
}


int main() {
    setup();
    ll i,j;
    ll n,m,r;
    char nowdir;
    cin>>n>>m>>r;
    cin>>nowdir;
    pll now;
    vector<string>arr(n);
    vector<vector<ll>>dp(n,vector<ll>(m,-1));
    ll len=1;
    for(i=0;i<n;i++) {
        cin >> arr[i];
        for(j=0;j<m;j++){
            switch (arr[i][j]) {
                case'W':
                dp[i][j]=1;
                now={i,j};
                arr[i][j]='.';
            }
        }
    }
    char moving;
    for(i=0;i<r;i++){
        cin>>moving;
        ll turn = i+2;
        switch (moving) {

            case'P':
                nowdir= turn_right(nowdir);
                break;
            case 'L':
                nowdir= turn_left(nowdir);
        }
        pll nex=now+dir[nowdir];
        if(nex.first<0||nex.second<0||
            nex.first>=n||nex.second>=m){
            cout<<turn -1;
            return 0;

        }

        if (arr[nex.first][nex.second]=='J') {
            len++;
        }
        arr[nex.first][nex.second]='.';
        if(turn - dp[nex.first][nex.second] <= len){
            cout<<turn -1;
            return 0;
        }
        dp[nex.first][nex.second]=turn;
        now=nex;
    }
    cout<<"OK";
}