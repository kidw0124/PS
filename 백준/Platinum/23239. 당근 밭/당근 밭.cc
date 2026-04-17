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
ll w,h,l;
ll my_srt(ll x)
{
    if(x<=0)return 0;
    ll st=0, md, ed=1e9;
    while(st<ed){
        md=(st+ed+1)/2;
        if(md*md>x)ed=md-1;
        else st=md;
    }
    return st;
}

ll inside(ll r){
    ll ans=0;
    for(ll i=1;i<r;i++){
        ans+=my_srt(r*r-i*i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>w>>h>>l;
    if(w<h)swap(w,h);
    if(l<h){
        cout<<3*inside(l)+2*l;
    }
    else if(l<w){
        cout<<3*inside(l)+2*l+l-h+inside(l-h);
    }
    else if(l<w+h){
        cout<<3*inside(l)+2*l+l-h+l-w+inside(l-h)+inside(l-w);
    }
    else {
        ll ans=3*inside(l)+2*l+l-h+l-w+inside(l-h)+inside(l-w);
        for(ll i=1;i<l-w-h;i++){
            ans-=max(0ll,min(my_srt((l-h)*(l-h)-(w+i)*(w+i)),my_srt((l-w)*(l-w)-i*i)-h));
        }
        cout<<ans;
    }
    return 0;
}
