#include<bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    setup();
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>org,arr(n+1),brr(n+1),crr(n+1),loca(n+1),locb(n+1),locc(n+1);
    vector<vector<ll>>locs(n+1,vector<ll>(n+1));
    vector<vector<ll>>edge(n+1);
    vector<ll>redge(n+1);
    for(i=0;i<n;i++){
        cin>>arr[i];
        loca[arr[i]]=i;
    }
    for(i=0;i<n;i++){
        cin>>arr[i];
        locb[arr[i]]=i;
    }
    for(i=0;i<n;i++){
        cin>>arr[i];
        locc[arr[i]]=i;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(loca[i]<loca[j])locs[i][j]-=1,locs[j][i]+=1;
            else if(loca[i]>loca[j])locs[i][j]+=1,locs[j][i]-=1;
            if(locb[i]<locb[j])locs[i][j]-=1,locs[j][i]+=1;
            else if(locb[i]>locb[j])locs[i][j]+=1,locs[j][i]-=1;
            if(locc[i]<locc[j])locs[i][j]-=1,locs[j][i]+=1;
            else if(locc[i]>locc[j])locs[i][j]+=1,locs[j][i]-=1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(loca[i]<loca[j])locs[i][j]-=1,locs[j][i]+=1;
            else if(loca[i]>loca[j])locs[i][j]+=1,locs[j][i]-=1;
            if(locb[i]<locb[j])locs[i][j]-=1,locs[j][i]+=1;
            else if(locb[i]>locb[j])locs[i][j]+=1,locs[j][i]-=1;
            if(locc[i]<locc[j])locs[i][j]-=1,locs[j][i]+=1;
            else if(locc[i]>locc[j])locs[i][j]+=1,locs[j][i]-=1;
        }
    }
    queue<ll>que;
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(locs[i][j]>0){
                edge[i].push_back(j);
                redge[j]++;
            }
            else if(locs[i][j]<0){
                edge[j].push_back(i);
                redge[i]++;
            }
        }
        if(redge[i]==0)que.push(i);
    }
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        org.push_back(now);
        for(auto k:edge[now]){
            redge[k]--;
            if(redge[k]==0)que.push(k);
        }
    }
    reverse(all(org));
    for(auto k:org)cout<<k<<' ';
    return 0;
}
