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

vector<vector<pair<ll,ll>>> arr;
vector<ll> dist;
bool func(){
    dist[1]=0;
    ll i,j;
    for(i=1;i<n;i++){
        for(j=1;j<=n;j++){
            for(auto k:arr[j]){
                ll nowv=k.first,nowc=k.second;
                if(dist[j]!=INT_MAX&&dist[nowv]>dist[j]+nowc){
                    dist[nowv]=dist[j]+nowc;
                }
            }
        }
    }
    bool a=true;
    for(j=1;j<=n;j++){
        for(auto k:arr[j]){
            ll nowv=k.first,nowc=k.second;
            if(dist[j]!=INT_MAX&&dist[nowv]>dist[j]+nowc){
                a=false;
            }
        }
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n+1);
    dist.resize(n+1,INT_MAX);
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
    }
    if(func()){
        for(i=2;i<=n;i++){
            cout<<(dist[i]==INT_MAX?(-1):dist[i])<<'\n';
        }
    }
    else{
        cout<<-1;
    }

    return 0;
}
