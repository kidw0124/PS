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

ll pow_10_[19]={1};
ll n,k;
ll cnt(ll x, ll t){
    set<int>arr;
    x/=pow_10_[t];
    while(x){
        arr.insert(x%10);
        x/=10;
    }
    return arr.size();
}

void ans(ll x,ll t){
    ll xx=x-x%pow_10_[t];;
    set<int>arr,arr2;
    vector<int> brr,brr2;
    arr2.insert({0,1,2,3,4,5,6,7,8,9});
    x/=pow_10_[t];
    while(x){
        arr.insert(x%10);
        arr2.erase(x%10);
        x/=10;
    }
    for(auto y:arr2){
        brr2.push_back(y);
    }
    ll cn=k-arr.size();
    ll j;
    for(j=0;j<cn;j++){
        xx+=pow_10_[j]*brr2[cn-j-1];
        arr.insert(brr2[cn-j-1]);
    }
    for(auto y:arr){
        brr.push_back(y);
    }
    for(;j<t;j++){
        xx+=pow_10_[j]*brr[0];
    }
    cout<<xx;
    return;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,m;
    for(i=1;i<19;i++){
        pow_10_[i]=pow_10_[i-1]*10;
    }
    cin>>n>>k;
    if(cnt(n,0)==k){
        cout<<n;
        return 0;
    }
    for(i=0;;i++){
        ll now=n/pow_10_[i]%10,now2=n%pow_10_[i];
        for(j=now+1;j<10;j++){
            n-=now*pow_10_[i];
            n+=j*pow_10_[i];
            ll cn=cnt(n,i);
            if(cn<=k&&cn+i>=k){
                ans(n,i);
                return 0;
            }
            n-=j*pow_10_[i];
            n+=now*pow_10_[i];
        }
    }

    return 0;
}
