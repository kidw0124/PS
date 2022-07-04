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

vector<pll> points;
set<pll> st;
ll dist(pll a, pll b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
ll n,d=INT_MAX, sw;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        points.push_back({a,b});
    }
    sort(points.begin(),points.end());
    for(i=0;i<n;i++){
        if(d==0)break;
        while(sw<i){
            if((points[i].first-points[sw].first)*(points[i].first-points[sw].first)>=d){
                st.erase({points[sw].second,points[sw++].first});
            }
            else break;
        }
        ll dd=(ll)sqrt(d)+1;
        auto k=st.upper_bound({points[i].second+dd+1,10000});
        for(auto j=st.lower_bound({points[i].second-dd-1,-10000}); j!=k;j++){
            d=min(d,dist(points[i],{j->second,j->first}));
        }
        st.insert({points[i].second,points[i].first});
    }
    cout<<d;
    return 0;
}
