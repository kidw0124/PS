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
vector<pll> circle;
bool find_in(pll a, ll b){
    return a.first<b;
}
int area(ll k){
    ll s=k+1;
    if(circle[k].first!=circle[s].first)return 1;
    while(1){
        if(circle[k].second==circle[s].second)return 2;
        auto x=lower_bound(circle.begin()+s,circle.end(),circle[s].second,find_in);
        if(x==circle.end()||circle[s].second!=x->first){
            return 1;
        }
        else s=x-circle.begin();
    }
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        ll r,x;
        cin>>x>>r;
        circle.push_back({x-r,-(x+r)});
    }
    sort(circle.begin(),circle.end());
    for(i=0;i<n;i++)circle[i].second*=-1;
    ll ans=2;
    for(i=0;i<n-1;i++){
        ans+=area(i);
    }
    cout<<ans;
    return 0;
}
