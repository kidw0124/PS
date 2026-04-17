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
ll n,r,q;
vector<vector<ll>>arr;
vector<ll>ans;

ll dfs(ll a){
    ans[a]=1;
    for(auto k:arr[a]){
        if(ans[k])continue;
        else{
            ans[a]+=dfs(k);
        }
    }
    return ans[a];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>r>>q;
    arr.resize(n+1);
    ans.resize(n+1);
    for(i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(r);
    for(i=0;i<q;i++){
        cin>>j;
        cout<<ans[j]<<'\n';
    }

    return 0;
}
