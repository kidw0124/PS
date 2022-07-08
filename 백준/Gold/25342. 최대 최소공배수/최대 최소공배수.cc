#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n&1){
            cout<<(n-1)*n*(n-2);
        }
        else{
            ll ans=n*(n-1);
            ll x=3,tt;
            for(i=x;;i+=2){
                if((n)%i){
                    tt=ans*(n-i);
                    break;
                }
            }
            cout<<max(tt,(n-1)*(n-2)*(n-3));
        }
        cout<<'\n';
    }
    return 0;
}
