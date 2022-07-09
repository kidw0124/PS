#include<bits/stdc++.h>
#include<math.h>
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
struct triangle{
    pair<long double,long double>points[3];
    long double area(){
        return 0.5*abs(points[0].first*points[1].second+points[1].first*points[2].second+points[2].first*points[0].second-(points[0].second*points[1].first+points[1].second*points[2].first+points[2].second*points[0].first));
    }
    pair<long double,long double> centroid(){
        return{(points[0].first+points[1].first+points[2].first)/3.0,(points[0].second+points[1].second+points[2].second)/3.0};
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    triangle x;
    for(i=0;i<3;i++){
        cin>>x.points[i].first>>x.points[i].second;
    }
    cout<<fixed<<setprecision(7)<<M_PI*2*x.centroid().second*x.area()<<' '<<M_PI*2*x.centroid().first*x.area();

    return 0;
}
