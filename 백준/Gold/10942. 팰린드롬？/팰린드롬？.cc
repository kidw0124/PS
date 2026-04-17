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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vl arr(n+1),crr(n+1,0),drr(n+1,0);
    for(i=1;i<=n;i++)cin>>arr[i];
    cin>>m;
    vector<pll>brr(m);
    for(i=0;i<m;i++)cin>>brr[i].first>>brr[i].second;
    for(i=1;i<=n;i++){
        bool c=0;
        for(j=1;j<i&&i+j<=n;j++){
            if(arr[i-j]!=arr[i+j]){c=1,crr[i]=j-1;break;}
        }
        if(!c)crr[i]=j-1;
        c=0;
        for(j=1;j<=i&&i+j<=n;j++){
            if(arr[i-j+1]!=arr[i+j]){c=1,drr[i]=j-1;break;}
        }
        if(!c)drr[i]=j-1;
    }
    for(auto i : brr){
        if((i.first+i.second)%2){
            if(drr[(i.first+i.second)/2]>(i.first+i.second)/2-i.first)cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else{
            if(crr[(i.first+i.second)/2]>=(i.first+i.second)/2-i.first)cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
    return 0;
}
