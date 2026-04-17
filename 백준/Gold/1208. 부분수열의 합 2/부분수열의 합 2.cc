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

ll n, s;
vector<ll> suma,sumb;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>s;
    vl arr,brr;
    for(i=0;i<n/2;i++){
        ll t;
        cin>>t;
        arr.push_back(t);
    }
    for(i=n/2;i<n;i++){
        ll t;
        cin>>t;
        brr.push_back(t);
    }
    ll cnt=0;
    ll maxa=1<<arr.size();
    ll maxb=1<<brr.size();
    for(i=1;i<maxa;i++){
        ll ss=0;
        for(j=0;j<arr.size();j++){
            if((i>>j)&1)ss+=arr[j];
        }
        suma.push_back(ss);
        if(ss==s)cnt++;
    }
    for(i=1;i<maxb;i++){
        ll ss=0;
        for(j=0;j<brr.size();j++){
            if((i>>j)&1)ss+=brr[j];
        }
        sumb.push_back(ss);
        if(ss==s)cnt++;
    }
    sort(suma.begin(),suma.end());
    sort(sumb.begin(),sumb.end());
    for(i=0;i<suma.size();i++){
        ll t=s-suma[i];
        cnt+=upper_bound(sumb.begin(),sumb.end(),t)-lower_bound(sumb.begin(),sumb.end(),t);
    }
    cout<<cnt;
    return 0;
}
