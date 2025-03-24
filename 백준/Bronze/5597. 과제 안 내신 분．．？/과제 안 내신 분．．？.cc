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
    ll i,j;vector<bool>arr(30);
for(i=0;i<28;i++)cin>>j,arr[j-1]=true;
auto it=ranges::find(arr,false);
cout<<it-arr.begin()+1<<' ';
it=find(it+1,arr.end(),false);
cout<<it-arr.begin()+1<<' ';

    return 0;
}
