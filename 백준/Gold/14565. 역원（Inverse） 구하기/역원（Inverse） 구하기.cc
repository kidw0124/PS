#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b) {
    if(a&&b)return a*(b/gcd(a,b));
    return a+b;
}
ll POW(ll a, ll b, ll rem) {
    ll p=1;
    for(; b; b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;
    return p;
}

// Extended Euclidean Algorithm
// ax+by=g
// return (g,x,y)
// O(logn) : n is a or b
// Recursive function to demonstrate the extended Euclidean algorithm.
// It returns multiple values using tuple in C++.
tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
    if (a == 0) {
        return make_tuple(b, 0, 1);
    }
    ll gcd, x, y; // unpack tuple returned by function into variables
    tie(gcd, x, y) = extended_gcd(b % a, a);
    return make_tuple(gcd, (y - (b/a) * x), x);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll a, n;
    cin>>n>>a;
    cout<<n-a<<' ';
    ll x,y,z;
    tie(x,y,z)=extended_gcd(a,n);
    if(x==1){
        cout<<(y+n)%n;
    }
    else{
        cout<<"-1";
    }

    return 0;
}
