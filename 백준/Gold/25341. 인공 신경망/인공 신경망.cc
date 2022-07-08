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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m,q;
    cin>>n>>m>>q;
    vector<ll>a(n+1),b(m+1),cor(n+1);
    vector<vector<ll>>w(m+1);
    vector<vector<ll>>p(m);
    a[n]=1;
    for(i=0;i<m;i++){
        ll c;
        cin>>c;
        p[i].resize(c);
        w[i].resize(c);
        for(j=0;j<c;j++){
            cin>>p[i][j];
            p[i][j]--;
        }
        for(j=0;j<c;j++)cin>>w[i][j];
        cin>>b[i];
    }
    w[m].resize(m);
    for(i=0;i<m;i++){
        cin>>w[m][i];
    }
    cin>>b[m];
    for(i=0;i<m;i++){
        for(j=0;j<w[i].size();j++){
            cor[p[i][j]]+=w[i][j]*w[m][i];
        }
        cor[n]+=b[i]*w[m][i];
    }
    while(q--){
        ll ans=cor[n];
        for(i=0;i<n;i++){
            cin>>j;
            ans+=j*cor[i];
        }
        cout<<ans+b[m]<<'\n';
    }
    return 0;
}
