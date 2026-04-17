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
ll t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    vl arr(1000007),brr(1000007);
    arr[1]=3,brr[1]=7;
    for(i=2;i<1000007;i++){
        arr[i]=arr[i-1]*2+brr[i-1];
        arr[i]%=1000000007;
        brr[i]=arr[i-1]*4+brr[i-1]*3;
        brr[i]%=1000000007;
    }
    while(t--){
        cin>>n;
        cout<<brr[n]<<'\n';
    }
    return 0;
}
