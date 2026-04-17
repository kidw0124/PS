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

pair<ll,ll>softing(ll a,ll b,ll x, ll y){
    ll t=(y-x)/(a+b);
    return {x+b*t,y-a*t};
}

pair<ll,ll> eea(ll a, ll b){
    if(b==0){
        if(a>1){
            return {0,0};
        }
        else{
            return {1,0};
        }
    }
    else{
        ll x0,y0;
        tie(x0,y0)=eea(b,a%b);
        if(!x0&&!y0)return{0,0};
        tie(x0,y0)=make_pair(y0,x0-(a/b)*y0);
        return softing(a,b,x0,y0);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t;
    cin>>t;
    ll a,b;
    while(t--){
        cin>>a>>b;
        ll x,y;
        tie(x,y)=eea(a,b);
        if(!x&&!y){
            cout<<"IMPOSSIBLE\n";
        }
        else{
            ll z;
            y=y+(z=(max((x/b),(y/a))+1))*a;
            if(y>a&&x-z*b+b<0)y-=a;
            if(y>1'000'000'000)cout<<"IMPOSSIBLE\n";
            else cout<<y<<'\n';
        }
    }

    return 0;
}
