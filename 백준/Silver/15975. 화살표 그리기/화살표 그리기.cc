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
ll n,ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<vl>point(n+1,vl());
    for(i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        point[y].pb(x);
    }
    for(i=1;i<=n;i++){
        if(point[i].size()<2)continue;
        sort(point[i].begin(),point[i].end());
        for(j=0;j<point[i].size();j++){
            if(!j)ans+=abs(point[i][j]-point[i][j+1]);
            else if(j==point[i].size()-1)ans+=abs(point[i][j]-point[i][j-1]);
            else ans+=min(abs(point[i][j]-point[i][j+1]),abs(point[i][j]-point[i][j-1]));
        }
    }
    cout<<ans;
    return 0;
}
