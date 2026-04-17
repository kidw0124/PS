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
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n;
ll powm[1'000'003]={1,2};
ll powm2[1'000'003]={1,4};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    ll ans=0;
    for(i=2;i<1'000'003;i++){
        powm[i]=powm[i-1]*2%1'000'003;
    }
    ll inv3=1;
    for(i=2;i<1'000'003;i++){
        if((i*3)%1'000'003==1)inv3=i;
    }
    ans=inv3*(powm[n%1'000'002]-1)*(powm[(n-1)%1'000'002]-1);
    cout<<ans%1'000'003;
    return 0;
}
