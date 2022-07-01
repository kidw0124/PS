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
vl fibo;
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll i,j,ans=0;
    cin>>n;
    fibo.push_back(1);
    fibo.push_back(2);
    for(;*fibo.rbegin()<n;){
        fibo.push_back(*fibo.rbegin()+*(fibo.rbegin()+1));
    }
    if(n==*fibo.rbegin())cout<<-1;
    else{
        ll t=n-*(fibo.rbegin()+1);
        while(t){
            t-=ans=*(upper_bound(fibo.begin(),fibo.end(),t)-1);
        }
        cout<<ans;
    }

    return 0;
}
