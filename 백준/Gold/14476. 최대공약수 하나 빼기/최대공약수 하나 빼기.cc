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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>arr(n),le(n),ri(n),ans(n);
    for(i=0;i<n;i++)cin>>arr[i];
    le[0]=arr[0],ri[n-1]=arr[n-1];
    for(i=1;i<n;i++)le[i]=gcd(le[i-1],arr[i]);
    for(i=n-2;i>=0;i--)ri[i]=gcd(ri[i+1],arr[i]);
    ans[0]=ri[1],ans[n-1]=le[n-2];
    for(i=1;i<n-1;i++)ans[i]=gcd(le[i-1],ri[i+1]);
    for(i=0;i<n;i++)if(arr[i]%ans[i]==0)ans[i]=-1;
    auto k=max_element(all(ans));
    if(*k<0)cout<<-1;
    else{
        cout<<*k<<' '<<arr[k-ans.begin()];
    }

    return 0;
}
