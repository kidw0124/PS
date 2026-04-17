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
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

ll n;
vector<ll>grundy;

ll find_g(set<ll>&st){
    ll x=0;
    for(auto k:st){
        if(x!=k)return x;
        x++;
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    grundy.resize(n+1);
    grundy[2]=1;
    for(i=3;i<=n;i++){
        set<ll>st;
        for(j=0;j+j<i-1;j++){
            st.insert(grundy[j]^grundy[i-j-2]);
        }
        grundy[i]=find_g(st);
    }
    if(grundy[n]){
        cout<<1;
    }
    else cout<<2;

    return 0;
}
