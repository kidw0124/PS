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
ll n,m,k;
ll arr[200][200],brr[200][200];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)cin>>arr[i][j];
    }
    cin>>m>>k;
    for(i=0;i<m;i++){
        for(j=0;j<k;j++)cin>>brr[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<k;j++){
            ll ans=0;
            for(ll l=0;l<m;l++){
                ans+=arr[i][l]*brr[l][j];
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
