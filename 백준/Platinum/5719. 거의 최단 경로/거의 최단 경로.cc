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
ll n,m,s,d;
vector<vector<pll>> grp;
vector<vector<ll>> del;
set<pll> visited;
vector<ll> dist;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    while(1){
        cin>>n>>m;
        if(!(n|m))break;
        cin>>s>>d;
        grp.clear();
        grp.resize(n);
        del.clear();
        del.resize(n);
        for(i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            grp[a].push_back({b,c});
        }
        dist.clear();
        dist.resize(n,INT_MAX);
        priority_queue<pll> pq;
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            ll x=-pq.top().first;
            ll y=pq.top().second;
            pq.pop();
            if(dist[y]<x)continue;
            else{
                for(auto [i,j]:grp[y]){
                    if(j==-1||j+x>dist[i])continue;
                    else if(j+x<dist[i]){
                        dist[i]=j+x;
                        pq.push({-j-x,i});
                        del[i].clear();
                        del[i].push_back(y);
                    }
                    else{
                        del[i].push_back(y);
                    }
                }
            }
        }
        visited.clear();
        queue<ll> que;
        que.push(d);
        while(!que.empty()){
            ll x= que.front();
            que.pop();
            for(auto i:del[x]){
                if(visited.find({i,x})!=visited.end())continue;
                else{
                    visited.insert({i,x});
                    for(auto j=grp[i].begin();j!=grp[i].end();j++){
                        if(j->first==x)j->second=-1;
                    }
                    que.push(i);
                }
            }
        }
        dist.clear();
        dist.resize(n,INT_MAX);
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            ll x=-pq.top().first;
            ll y=pq.top().second;
            pq.pop();
            if(dist[y]<x)continue;
            else{
                for(auto [i,j]:grp[y]){
                    if(j==-1||j+x>dist[i])continue;
                    else if(j+x<dist[i]){
                        dist[i]=j+x;
                        pq.push({-j-x,i});
                        del[i].clear();
                        del[i].push_back(y);
                    }
                    else{
                        del[i].push_back(y);
                    }
                }
            }
        }
        cout<<(dist[d]==INT_MAX?-1:dist[d])<<'\n';
    }

    return 0;
}
