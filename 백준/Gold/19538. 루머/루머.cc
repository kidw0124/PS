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
const ll MN=200000+5;
queue<ll> rum;
vector<ll> node[MN];
ll tim[MN];
ll rela[MN];
queue<int> arr;

void bfs(){
    while(!rum.empty()){
        ll y=rum.front();
        rum.pop();
        for(auto i : node[y]){
            if(2*rela[i]<node[i].size()){
                rela[i]++;
                if(2*rela[i]>=node[i].size()){
                    tim[i]=tim[y]+1;
                    rum.push(i);
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    memset(tim,-1,sizeof(tim));
    for(i=1;i<=n;i++){
        ll t1=1;
        while(t1){
            cin>>t1;
            node[i].push_back(t1);
        }
        node[i].pop_back();
    }
    cin>>m;
    for(i=0;i<m;i++){
        ll t1;
        cin>>t1;
        rela[t1]=MN;
        tim[t1]=0;
        rum.push(t1);
    }
    bfs();
    for(i=1;i<=n;i++){
        cout<<tim[i]<<' ';
    }

    return 0;
}
