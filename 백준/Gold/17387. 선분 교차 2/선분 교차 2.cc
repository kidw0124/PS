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
pair<pll,pll>arr[2];
ll ccw (pll a, pll b, pll c){
    return ((b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second))==0?0:((b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second))/abs(((b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second)));
}
ll intersect(pair<pll,pll>x, pair<pll,pll>y){
    pll x_a=x.first,x_b=x.second,y_a=y.first,y_b=y.second;
    ll ccwx=ccw(x_a,x_b,y_a)*ccw(x_a,x_b,y_b);
    ll ccwy=ccw(y_a,y_b,x_a)*ccw(y_a,y_b,x_b);
    if(ccwx==0&&ccwy==0){
        return max(x_a,x_b)>=min(y_a,y_b)&&min(x_a,x_b)<=max(y_a,y_b);
    }
    else return ccwx<=0&&ccwy<=0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    for(i=0;i<2;i++){
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;
    }
    cout<<intersect(arr[0],arr[1]);
    return 0;
}
