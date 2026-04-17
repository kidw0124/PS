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

ll n,d,g;
const ll MN=300000+5;
ll par[MN];
bool visit[MN];
vector<ll> road[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n-1;i++){
        int t1,t2;
        cin>>t1>>t2;
        road[t1].pb(t2);
        road[t2].pb(t1);
    }
    for(i=1;i<=n;i++){
        g+=road[i].size()*(road[i].size()-1)*(road[i].size()-2);
    }
    for(i=1;i<=n;i++){
        for(auto j : road[i]){
            d+=max(0,(int)((road[i].size()-1)*(road[j].size()-1)));
        }
    }
    if(d>g){
        cout<<"D";
    }
    else if(d==g){
        cout<<"DUDUDUNGA";
    }
    else{
        cout<<"G";
    }

    return 0;
}
