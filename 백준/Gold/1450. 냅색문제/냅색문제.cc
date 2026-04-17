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
ll n,c;
vector<ll>arr,brr;
vector<ll>bsum;
void cntsum(vector<ll>&vec){
    ll tot=(1<<vec.size()),cnt=0;
    for(ll i=0;i<tot;i++){
        ll p=0;
        for(ll j=0;j<vec.size();j++){
            if(i&(1<<j))p+=vec[j];
        }
        bsum.push_back(p);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>c;
    arr.resize(n/2);
    brr.resize(n-n/2);
    for(i=0;i<n/2;i++){
        cin>>arr[i];
    }
    for(i=n/2;i<n;i++){
        cin>>brr[i-n/2];
    }
    cntsum(brr);
    sort(bsum.begin(),bsum.end());
    ll tot=(1<<arr.size()),ans=0;
    for(i=0;i<tot;i++){
        ll p=0;
        for(j=0;j<arr.size();j++){
            if(i&(1<<j))p+=arr[j];
        }
        ans+=upper_bound(bsum.begin(),bsum.end(),c-p)-bsum.begin();
    }
    cout<<ans;
    return 0;
}
