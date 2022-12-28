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

// Ordered set is a policy based data structure in g++ that keeps the unique elements in sorted order.
// It performs all the operations as performed by the set data structure in STL in log(n) complexity and performs two additional operations also in log(n) complexity
// order_of_key (k) : Number of items strictly smaller than k
// find_by_order(k) : ‐Kth element in a set (counting from zero)
// tree<key_type, value_type(set if null), comparator , ...>
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag ,
        tree_order_statistics_node_update >;
using ordered_multi_set = tree<int, null_type, less_equal <int>, rb_tree_tag ,
        tree_order_statistics_node_update >;
void m_erase(ordered_multi_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_multi_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}


int main(){
    setup();
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(2*n);
    iota(all(arr),1);
    for(i=0;i<m;i++){
        ll k;
        cin>>k;
        if(k==0){
            vector<ll>brr(2*n);
            for(j=0;j<n;j++){
                brr[2*j]=arr[j];
                brr[2*j+1]=arr[j+n];
            }
            arr=brr;
        }
        else{
            vector<ll>brr(2*n);
            for(j=k;j<2*n;j++){
                brr[j-k]=arr[j];
            }
            for(j=0;j<k;j++){
                brr[j+2*n-k]=arr[j];
            }
            arr=brr;
        }
    }
    for(j=0;j<2*n;j++)cout<<arr[j]<<'\n';

}