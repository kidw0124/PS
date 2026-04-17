#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double ld;
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
ld dist(pair<ld,ld>a,pair<ld,ld>b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
vector<ll>par;

ll _find(ll x){
    if(par[x]==x)return x;
    else return par[x]=_find(par[x]);
}

void _union(ll x, ll y){
    par[_find(y)]=_find(x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,m;
    cin>>n>>m;
    vector<pair<ld,ld>>arr(n+1);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    par.resize(n+1,-1);
    iota(par.begin(),par.end(),0);
    vector<vector<ld>>brr(n+1,vector<ld>(n+1));
    priority_queue<pair<ld,pll>>pq;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            brr[i][j]=dist(arr[i],arr[j]);
            if(i!=j)pq.push({-brr[i][j],{i,j}});
        }
    }
    ld ans=0;
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        //ans+=brr[a-1][b-1];
        _union(a-1,b-1);
    }
    while(!pq.empty()){
        ld nowc=-pq.top().first;
        pll nowv=pq.top().second;
        pq.pop();
        if(_find(nowv.first)==_find(nowv.second))continue;
        else{
            ans+=nowc;
            _union(nowv.first,nowv.second);
        }
    }
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}
