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
ll n;

string ans(ll n){
    switch(n){
    case 0:
        return "0";
    case 1:
        return "1";
    case -1:
        return "T";
    default:
        switch (n%3)
        {
        case 0:
            return ans(n/3)+"0";
        case 1:
            return ans(n/3)+"1";
        case -1:
            return ans(n/3)+"T";
        case 2:
            return ans((n+1)/3)+"T";
        case -2:
            return ans((n-1)/3)+"1";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    string s=ans(n);
    cout<<s;
    return 0;
}
