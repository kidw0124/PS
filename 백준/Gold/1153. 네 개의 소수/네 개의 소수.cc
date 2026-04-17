#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    if(n<7){
        cout<<-1;
        return 0;
    }
    vector<bool>isprime(n,true);
    isprime[0]=isprime[1]=false;
    if(n&1){
        cout<<"2 3 ";
        n-=5;
    }
    else{
        cout<<"2 2 ";
        n-=4;
    }
    for(i=2;i<=n;i++){
        if(isprime[i]){
            if(i>=n/2&&isprime[n-i]){
                cout<<n-i<<' '<<i;
                return 0;
            }
            for(j=i*i;j<=n;j+=i)isprime[j]=false;
        }
    }
    return 0;
}
