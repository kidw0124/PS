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
ll n;

vector<pair<ll,ll>>brr;

void dfs(vector<ll>&arr,ll b){
    if(n>(b<<1)){
        dfs(arr,b<<1);
    }
    brr.push_back({arr[b],64-__builtin_clzll(b)});
    if(n>=(b<<1|1)){
        dfs(arr,b<<1|1);
    }
}

ll maxi(ll a, ll b){
    vector<ll>ret;
    for(auto k:brr){
        if(k.second<a||k.second>b)continue;
        else{
            if(ret.empty()){
                ret.push_back(k.first);
            }
            else{
                ret.push_back(max(*ret.rbegin()+k.first,k.first));
            }
        }
    }
    return *max_element(ret.begin(),ret.end());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    ll ln=64-__builtin_clzll(n);
    vector<ll>arr(n+1);
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    dfs(arr,1);
    ll ans=-((ll)INT_MAX*INT_MAX);
    for(i=1;i<=ln;i++){
        for(j=i;j<=ln;j++){
            ans=max(ans,maxi(i,j));
        }
    }
    cout<<ans;
    return 0;
}
