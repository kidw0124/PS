#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef __float128 LD;
//typedef __int128_t LL;
//typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b)
{
    if (a && b)
        return a * (b / gcd(a, b));
    return a + b;
}

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

const ll mod = 1e9+7;

void setup()
{
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j;

}

struct square{
    ll x, y, a;
};

struct point{
    ll x, y;
    ll dist2(const point &p) const {
        return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
    }
};

void solve(ll testcase){
    ll i,j,k;
    square Mat, Kor;
    cin >> Mat.x >> Mat.y >> Mat.a;
    cin >> Kor.x >> Kor.y >> Kor.a;
    ll n, m;
    cin >> n >> m;
    vector<point> mat(n), kor(m);
    for(auto &p : mat) cin >> p.x >> p.y;
    for(auto &p : kor) cin >> p.x >> p.y;
    vector<point> mat_candidate, kor_candidate;
    unordered_map<ll,vector<point>>tmp;
    for(auto &p : mat){
        tmp[p.x].push_back(p);
    }
    for(auto &p : tmp){
        mat_candidate.push_back(*min_element(p.second.begin(),p.second.end(),[](const point &a, const point &b){
            return a.y < b.y;
        }));
        mat_candidate.push_back(*max_element(p.second.begin(),p.second.end(),[](const point &a, const point &b){
            return a.y < b.y;
        }));
    }
    tmp.clear();
    for(auto &p : mat){
        tmp[p.y].push_back(p);
    }
    for(auto &p : tmp){
        mat_candidate.push_back(*min_element(p.second.begin(),p.second.end(),[](const point &a, const point &b){
            return a.x < b.x;
        }));
        mat_candidate.push_back(*max_element(p.second.begin(),p.second.end(),[](const point &a, const point &b){
            return a.x < b.x;
        }));
    }
    tmp.clear();
    for(auto &p : kor){
        tmp[p.x].push_back(p);
    }
    for(auto &p : tmp){
        kor_candidate.push_back(*min_element(p.second.begin(),p.second.end(),[](const point &a, const point &b){
            return a.y < b.y;
        }));
        kor_candidate.push_back(*max_element(p.second.begin(),p.second.end(),[](const point &a, const point &b){
            return a.y < b.y;
        }));
    }
    tmp.clear();
    for(auto &p : kor){
        tmp[p.y].push_back(p);
    }
    for(auto &p : tmp){
        kor_candidate.push_back(*min_element(p.second.begin(),p.second.end(),[](const point &a, const point &b){
            return a.x < b.x;
        }));
        kor_candidate.push_back(*max_element(p.second.begin(),p.second.end(),[](const point &a, const point &b){
            return a.x < b.x;
        }));
    }

    ll ans=1e18;
    pair<point,point>ans_pair;
    for(auto &p : mat_candidate){
        for(auto &q : kor_candidate){
            ll dist = p.dist2(q);
            if(dist < ans){
                ans = dist;
                ans_pair = {p,q};
            }
        }
    }
    cout << ans << '\n';
    cout << ans_pair.first.x << ' ' << ans_pair.first.y << '\n';
    cout << ans_pair.second.x << ' ' << ans_pair.second.y << '\n';




}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}
