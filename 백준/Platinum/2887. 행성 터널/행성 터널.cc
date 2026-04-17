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
ll n,m;
struct point{
    ll x,y,z,w;
};

bool cmpx(point a, point b){
    return a.x<b.x;
}
bool cmpy(point a, point b){
    return a.y<b.y;
}
bool cmpz(point a, point b){
    return a.z<b.z;
}

vector<ll> par;

ll _find(ll x){
    if(par[x]==-1)return x;
    else return par[x]=_find(par[x]);
}

void _union(ll x, ll y){
    par[_find(x)]=_find(y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<point>arr(n);
    par.resize(n,-1);
    priority_queue<pair<ll,pll>>pq;
    for(i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y>>arr[i].z;
        arr[i].w=i;
    }
    sort(arr.begin(),arr.end(),cmpx);
    for(i=0;i<n-1;i++){
        pq.push({-abs(arr[i].x-arr[i+1].x),{arr[i].w,arr[i+1].w}});
    }
    sort(arr.begin(),arr.end(),cmpy);
    for(i=0;i<n-1;i++){
        pq.push({-abs(arr[i].y-arr[i+1].y),{arr[i].w,arr[i+1].w}});
    }
    sort(arr.begin(),arr.end(),cmpz);
    for(i=0;i<n-1;i++){
        pq.push({-abs(arr[i].z-arr[i+1].z),{arr[i].w,arr[i+1].w}});
    }

    ll c=0,ans=0;
    while(c<n-1){
        ll nowc=-pq.top().first;
        ll a=pq.top().second.first,b=pq.top().second.second;
        pq.pop();
        if(_find(a)!=_find(b)){
            ans+=nowc;
            c++;
            _union(a,b);
        }
    }
    cout<<ans;
    return 0;
}
