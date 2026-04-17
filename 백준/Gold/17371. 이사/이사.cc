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
vector<pair<double,double>>arr;
vector<double>len;
double length(pair<double,double> a, pair<double,double> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    ll x=0;
    for(i=0;i<n;i++){
        len.push_back(0);
        for(j=0;j<n;j++){
            double k=length(arr[i],arr[j]);
            len[i]=max(len[i],k);
        }
        if(len[i]<len[x])x=i;
    }
    cout<<fixed<<setprecision(8)<<arr[x].first<<' '<<arr[x].second;
    return 0;
}
