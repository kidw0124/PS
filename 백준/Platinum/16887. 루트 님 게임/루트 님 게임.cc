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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    ll ans=0;
    for(i=0;i<n;i++){
        cin>>j;
        if(j<2*2)ans^=0;
        else if(j<4*4)ans^=1;
        else if(j<9*9+1)ans^=2;
        else if(j<82*82)ans^=0;
        else if(j<15ll*15ll*15ll*15ll+1ll)ans^=3;
        else if(j<(15ll*15ll*15ll*15ll+1ll)*(15ll*15ll*15ll*15ll+1ll))ans^=1;
        else ans^=2;
    }
    ans?cout<<"koosaga":cout<<"cubelover";


    return 0;
}
