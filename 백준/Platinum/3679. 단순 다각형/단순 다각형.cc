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
vector<pair<pll,ll>>points;
template<typename T1,typename T2,typename T3>
ll ccw(T1 a, T2 b, T3 c){
    return (b.first-a.first)*(c.second-b.second)-(c.first-b.first)*(b.second-a.second);
}
template<typename T1,typename T2>
ll dist(T1 a, T2 b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

bool cmp(pair<pll,ll> a, pair<pll,ll> b){
    if(ccw(points[0].first,a.first,b.first))return ccw(points[0].first,a.first,b.first)>0;
    else return dist(points[0].first,a.first)<dist(points[0].first,b.first);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        points.resize(n);
        for(i=0;i<n;i++){
            cin>>points[i].first.first>>points[i].first.second;
            points[i].second=i;
        }
        sort(all(points));
        sort(points.begin()+1,points.end(),cmp);
        i=n-1;
        while(!ccw(points[0].first,points[i-1].first,points[n-1].first))i--;
        reverse(points.begin()+i,points.end());
        for(i=0;i<n;i++){
            cout<<points[i].second<<' ';
        }
        cout<<'\n';
    }


    return 0;
}
