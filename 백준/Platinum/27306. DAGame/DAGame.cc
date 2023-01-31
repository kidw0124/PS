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

vector<vector<int>>edge,redge;
vector<vector<int>>grundy;
vector<vector<bool>>vis;

int get_grd(int i,int j){
    if(i>j)swap(i,j);
    if(vis[i][j])return grundy[i][j];
    else{
        vis[i][j]=1;
        bitset<6000>bs;
        if(i==j){
            for (auto k: edge[i]) {
                bs.set(get_grd(k,k));
            }
        }
        else {
            for (auto k: edge[i]) {
                if (k < j) {
                    bs.set(get_grd(k, j));
                } else {
                    bs.set(get_grd(j, k));
                }
            }
            for (auto k: edge[j]) {
                if (i < k) {
                    bs.set(get_grd(i, k));
                } else {
                    bs.set(get_grd(k, i));
                }
            }
        }
        bs.flip();
        return grundy[i][j]=bs._Find_first();
    }
}

int main(int argc, char* argv[]) {
    setup();
    ios_base::sync_with_stdio(false);
    int i,j;
    int n,m;
    cin>>n>>m;
    edge.resize(n+1);
    redge.resize(n+1);
    for(i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        edge[p].push_back(q);
        redge[q].push_back(p);
    }
    vis.resize(n+1,vector<bool>(n+1));
    grundy.resize(n+1,vector<int>(n+1,-1));
    vector<int>points;
    for(i=1;i<=n;i++){
        if(redge[i].empty()){
            points.push_back(i);
        }
    }
    int ans=0;
    int k;
    vector<vector<int>>color(n+1);
    cin>>k;
    for(i=0;i<k;i++){
        int v,c;
        cin>>v>>c;
        color[c].push_back(v);
    }
    for(i=1;i<=n;i++){
        if(color[i].size()==1){
            ans^= get_grd(color[i][0],color[i][0]);
        }
        else if(color[i].size()==2){
            ans^= get_grd(color[i][0],color[i][1]);
        }
    }
    if(ans){
        cout<<"Young\n";
    }
    else{
        cout<<"Cheol\n";
    }

}