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
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
vector<tuple<ll,ll,ll,ll>>arr;

bool cmp(const tuple<ll,ll,ll,ll>&a,const tuple<ll,ll,ll,ll>&b){
    if(get<0>(a)*get<1>(a)*get<2>(a)==get<0>(b)*get<1>(b)*get<2>(b)){
        if(get<0>(a)+get<1>(a)+get<2>(a)==get<0>(b)+get<1>(b)+get<2>(b)){
            return get<3>(a)<get<3>(b);
        }
        else return get<0>(a)+get<1>(a)+get<2>(a)<get<0>(b)+get<1>(b)+get<2>(b);
    }
    else return get<0>(a)*get<1>(a)*get<2>(a)<get<0>(b)*get<1>(b)*get<2>(b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        arr.push_back({b,c,d,a});
    }
    sort(arr.begin(),arr.end(),cmp);
    cout<<get<3>(arr[0])<<' ';
    cout<<get<3>(arr[1])<<' ';
    cout<<get<3>(arr[2])<<' ';
    return 0;
}
