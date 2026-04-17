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
ll n,m;
const ll INF=INT_MAX;
vector<vector<ll>>arr;
vector<pair<pll,ll>>edge;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n+1,vector<ll>(n+1,INT_MAX));
    for(i=0;i<m;i++){
        ll s,e,l;
        cin>>s>>e>>l;
        edge.push_back({{s,e},l});
        arr[s][e]=min(arr[s][e],l);
        arr[e][s]=min(arr[e][s],l);
    }
    for(i=1;i<=n;i++){
        arr[i][i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    }
    double a=20000000;
    for(j=1;j<=n;j++){
        double ans=0;
        for(i=0;i<m;i++){
            ll s=edge[i].first.first,e=edge[i].first.second,d=edge[i].second;
            ll diff=abs(arr[j][s]-arr[j][e]);
            if(diff>=d)ans=max(ans,min(arr[j][s],arr[j][e])+(double)d);
            else ans=max(ans,min(arr[j][s],arr[j][e])+diff+(d-diff)/2.0);
        }
        a=min(a,ans);
    }
    cout<<fixed<<setprecision(1)<<a;
    return 0;
}
