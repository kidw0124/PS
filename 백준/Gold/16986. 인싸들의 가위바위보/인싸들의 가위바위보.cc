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

int main(){
    setup();
    ll i,j;
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>>score(n+1,vector<ll>(n+1));
    vector<vector<ll>>arr(3,vector<ll>(20));
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>score[i][j];
        }
    }
    for(i=0;i<20;i++){
        cin>>arr[1][i];
    }
    for(i=0;i<20;i++){
        cin>>arr[2][i];
    }
    for(i=0;i<n;i++){
        arr[0][i]=i+1;
    }
    arr[0].resize(n);
    do{
        pll player = {0,1};
        vector<ll>game(3),turn(3);
        while(*max_element(all(game))<k){
            if(player.first>player.second)swap(player.first,player.second);
            if(turn[player.first]>=arr[player.first].size()
                ||turn[player.second]>=arr[player.second].size()){
                break;
            }
            pll now={arr[player.first][turn[player.first]],
                    arr[player.second][turn[player.second]]};
            turn[player.first]++,turn[player.second]++;
            if(score[now.first][now.second]==2){
                game[player.first]++;
                player.second=3-player.first-player.second;
            }
            else{
                game[player.second]++;
                player.first=3-player.first-player.second;
            }
            if(game[0]>=k){
                debugc(arr[0]);
                cout<<1;
                return 0;
            }
        }
    }while(next_permutation(all(arr[0])));
    cout<<0;
    return 0;
}
