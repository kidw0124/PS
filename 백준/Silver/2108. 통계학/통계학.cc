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
ll n,sum=0;
ll cnt[500005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vl arr(n);
    priority_queue<pll> brr;
    for(i=0;i<n;i++){
        cin>>arr[i];
        cnt[arr[i]+4000]++;
        sum+=arr[i];
    }
    for(i=0;i<=8000;i++)brr.push({cnt[i],-i+4000});
    i=brr.top().first;
    j=-brr.top().second;
    brr.pop();
    if(brr.top().first==0);
    else if(brr.top().first==i)j=-brr.top().second;
    sort(arr.begin(),arr.end());
    cout<<round(sum/(double)n)+1-1<<'\n'<<arr[n/2]<<'\n'<<j<<'\n'<<arr[n-1]-arr[0];
    return 0;
}
