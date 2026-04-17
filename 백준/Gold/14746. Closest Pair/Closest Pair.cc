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
vector<pll> arr;
ll c1,c2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m>>c1>>c2;
    for(i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back({t,1});
    }
    for(i=0;i<m;i++){
        int t;
        cin>>t;
        arr.push_back({t,2});
    }
    sort(arr.begin(),arr.end());
    ll M=1e9;
    ll num=0;
    for(auto i=arr.begin();i+1<arr.end();i++){
        auto j=i+1;
        if(i->second!=j->second){
            if(M>j->first-i->first){
                M=j->first-i->first;
                num=1;
            }
            else if(M==j->first-i->first){
                num++;
            }
        }
    }
    cout<<M+abs(c1-c2)<<' '<<num;


    return 0;
}
