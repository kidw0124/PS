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
ll t,n,m,r,s,g,h;
const ll INF=INT_MAX;

vector<vector<pair<ll,ll>>>arr;
vector<ll>dist,hdist,gdist;
set<ll>des;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        ll p;
        cin>>n>>m>>r>>s>>g>>h;
        arr.clear();
        dist.clear();
        hdist.clear();
        gdist.clear();
        des.clear();
        arr.resize(n+1);
        dist.resize(n+1,INF);
        hdist.resize(n+1,INF);
        gdist.resize(n+1,INF);
        for(i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            arr[a].push_back({b,c});
            arr[b].push_back({a,c});
            if(min(a,b)==min(h,g)&&max(a,b)==max(h,g))p=c;
        }
        dist[s]=0;
        priority_queue<pair<ll,ll>>pq;
        pq.push({0,s});
        while(!pq.empty()){
            ll nowv=pq.top().second,nowc=-pq.top().first;
            pq.pop();
            if(nowc!=dist[nowv])continue;
            for(auto k:arr[nowv]){
                if(dist[k.first]>dist[nowv]+k.second){
                    dist[k.first]=dist[nowv]+k.second;
                    pq.push({-dist[k.first],k.first});
                }
            }
        }
        gdist[g]=0;
        pq.push({0,g});
        while(!pq.empty()){
            ll nowv=pq.top().second,nowc=-pq.top().first;
            pq.pop();
            if(nowc!=gdist[nowv])continue;
            for(auto k:arr[nowv]){
                if(gdist[k.first]>gdist[nowv]+k.second){
                    gdist[k.first]=gdist[nowv]+k.second;
                    pq.push({-gdist[k.first],k.first});
                }
            }
        }
        hdist[h]=0;
        pq.push({0,h});
        while(!pq.empty()){
            ll nowv=pq.top().second,nowc=-pq.top().first;
            pq.pop();
            if(nowc!=hdist[nowv])continue;
            for(auto k:arr[nowv]){
                if(hdist[k.first]>hdist[nowv]+k.second){
                    hdist[k.first]=hdist[nowv]+k.second;
                    pq.push({-hdist[k.first],k.first});
                }
            }
        }
        for(i=0;i<r;i++){
            ll a;
            cin>>a;
            //cout<<a<<":"<<dist[a]<<' '<<dist[h]<<' '<<dist[g]<<' '<<p<<' '<<gdist[a]<<' '<<hdist[a]<<'\n';
            if(dist[h]+p+gdist[a]==dist[a]||dist[g]+p+hdist[a]==dist[a]){
                des.insert(a);
            }
        }
        for(auto k:des){
            cout<<k<<' ';
        }
        cout<<'\n';


    }


    return 0;
}
