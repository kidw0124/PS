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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++)cout<<'*';
    for(i=0;i<2*n-3;i++)cout<<' ';
    for(i=0;i<n;i++)cout<<'*';
    cout<<'\n';
    for(j=0;j<n-1;j++){
        for(i=0;i<=j;i++)cout<<' ';
        cout<<'*';
        for(i=0;i<n-2;i++)cout<<' ';
        cout<<'*';
        for(i=2*n-5;i>2*j;i--)cout<<' ';
        if(j!=n-2)cout<<'*';
        for(i=0;i<n-2;i++)cout<<' ';
        cout<<'*';
        cout<<'\n';
    }
    for(j=n-3;j>=0;j--){
        for(i=0;i<=j;i++)cout<<' ';
        cout<<'*';
        for(i=0;i<n-2;i++)cout<<' ';
        cout<<'*';
        for(i=2*n-5;i>2*j;i--)cout<<' ';
        if(j!=n-2)cout<<'*';
        for(i=0;i<n-2;i++)cout<<' ';
        cout<<'*';
        cout<<'\n';
    }
    for(i=0;i<n;i++)cout<<'*';
    for(i=0;i<2*n-3;i++)cout<<' ';
    for(i=0;i<n;i++)cout<<'*';
    cout<<'\n';
    return 0;
}
