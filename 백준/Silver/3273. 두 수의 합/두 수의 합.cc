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
ll n,x;
vector<ll>arr;

ll nc2(ll a){
    return a*(a-1)/2;
}

auto _count(auto a, auto b, auto c){
    return upper_bound(a,b,c)-lower_bound(a,b,c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        arr.push_back(j);
    }
    cin>>x;
    ll ans=0;
    sort(arr.begin(),arr.end());
    for(i=0;i<n;i++){
        if(arr[i]*2==x)continue;
        ans+=_count(arr.begin(),arr.end(),x-arr[i]);
    }
    ans/=2;
    if(x%2==0)ans+=nc2(_count(arr.begin(),arr.end(),x/2));
    cout<<ans;
    return 0;
}
