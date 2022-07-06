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
ll n;
ll a=1;
ll mod=998244353;
vector<ll>arr;
ll inverse(ll n, ll MOD){
    return POW(n,MOD-2,MOD);
}
ll ans=0;

ll calc(){
    ll now=1;
    ll i,j,k;
    vector<ll>brr(75);
    for(i=0;i<arr.size();i++){
        for(j=0;j<arr[i];j++){
            brr[j]++;
        }
    }
    for(i=0;i<arr.size();i++){
        for(j=0;j<arr[i];j++){
            now*=(arr[i]-j-1)+(brr[j]-i-1)+1;
            now%=mod;
        }
    }
    return inverse(now,mod);
}

void func(ll now, ll limit,bool t=false){
    if(!now){
        ll tmp=calc();
        tmp=(a*tmp)%mod;
        ans+=(tmp*tmp)%mod;
        ans%=mod;
        return;
    }
    else{
        if(!t)for(ll i=1;i<=min(limit,now);i++){
            arr.push_back(i);
            func(now-i,i);
            arr.pop_back();
        }
        else for(ll i=1;i<=min(limit,now/2);i++){
            arr.push_back(i);
            arr.push_back(i);
            func(now-i*2,i);
            arr.pop_back();
            arr.pop_back();
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        a*=i;
        a%=mod;
    }
    func(n,n/2,1);
    cout<<ans%mod;
    return 0;
}
