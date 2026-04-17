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
const ll MAX_NUM=2005;
bool prime[MAX_NUM];
ll n;
vector<vl> arr(2);
vector<vl>conn(25);
vl rec(25);
vector<bool> chk(25);

bool func(ll x, ll y){
    for(ll i=0;i<conn[x].size();i++){
        ll t=conn[x][i];
        if(chk[t]||arr[1][t]==y)continue;
        chk[t]=true;
        if(!rec[t]||func(rec[t],y)){
            rec[t]=x;
            return 1;
        }
    }
    return 0;
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll i,j;
    for(i=2;i<MAX_NUM;i++){
        for(j=i;i*j<MAX_NUM;j++)prime[i*j]=1;
    }
    cin>>n;
    for(i=0;i<n;i++){
        ll t;
        cin>>t;
        if(i==0)arr[0].pb(t);
        else arr[t%2!=arr[0][0]%2].pb(t);
    }
    if(arr[0].size()!=arr[1].size()){
        cout<<-1;
        return 0;
    }
    for(i=0;i<n/2;i++){
        for(j=0;j<n/2;j++){
            if(!prime[arr[0][i]+arr[1][j]])conn[i].pb(j);
        }
    }
    priority_queue<int> pq;
//    for(i=0;i<n/2;i++){
//        cout<<'\n'<<arr[0][i]<<" : ";
//        for(j=0;j<conn[i].size();j++){
//            cout<<arr[1][j]<<' ';
//        }
//    }
    for(i=0;i<conn[0].size();i++){
        ll cnt=0;
        fill(rec.begin(),rec.end(),0);
        for(j=1;j<n/2;j++){
            fill(chk.begin(),chk.end(),0);
            if(func(j,arr[1][conn[0][i]]))cnt++;
        }
        if(cnt==n/2-1)pq.push(-arr[1][conn[0][i]]);
    }
    if(pq.size()==0){
        cout<<-1;
        return 0;
    }
    while(!pq.empty()){
        cout<<-pq.top()<<' ';
        pq.pop();
    }
    return 0;
}
