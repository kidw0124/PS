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
vector<deque<ll>>arr;
vector<ll> brr,crr;
vector<bool> drr;

ll cnt_brr(){
    ll cnt=0;
    for(ll i=1;i<=n;i++) if (brr[i])cnt++;
}

ll bipartite_matching(ll k){
    bool is=0;
    for(auto b :arr[k]){
        if(!crr[b]) {
            crr[b]=k;
            brr[k]=b;
            b=1;
            is=1;
            break;
        }
    }
    if(is){
        arr[k].pop_front();
        return 1;
    }
    else{
        is=0;
        for(auto b :arr[k]){
            ll x=crr[b];
            if(drr[x])continue;
            crr[b]=k;
            brr[k]=b;
            drr[k]=1;
            if(bipartite_matching(x)){
                is=1;
                break;
            }
            else{
                crr[b]=x;
                brr[k]=0;
                drr[k]=0;
                arr[k].pop_front();
            }
        }
        if(is){
            arr[k].pop_front();
            return 1;
        }
        else return 0;

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n+1);
    brr.resize(n+1);
    crr.resize(m+1);
    drr.resize(n+1);
    for(i=0;i<n;i++){
        ll t;
        cin>>t;
        arr[i+1].resize(t);
        for(j=0;j<t;j++){
            cin>>arr[i+1][j];
        }
    }
    ll ans=0;
    for(i=1;i<=n;i++){
        drr.clear();
        drr.resize(n+1);
        ans+=bipartite_matching(i);
    }
    cout<<ans;
    return 0;
}
