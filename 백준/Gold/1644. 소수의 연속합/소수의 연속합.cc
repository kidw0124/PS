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
ll n;
vector<ll> primes,sumprime;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    sumprime.push_back(0);
    ll ans=0;
    cin>>n;
    vector<bool> bb(n+1);
    for(i=2;i<=n;i++){
        if(!bb[i]){
            primes.push_back(i);
            sumprime.push_back(i+*sumprime.rbegin());
            for(j=2*i;j<=n;j+=i){
                bb[j]=1;
            }
        }
    }
    for(auto k:sumprime){
        if(binary_search(sumprime.begin(),sumprime.end(),n+k))ans++;
    }
    cout<<ans;

    return 0;
}
