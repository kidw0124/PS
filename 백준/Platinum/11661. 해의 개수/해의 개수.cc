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
        return {y0,x0-(a/b)*y0};
    }
}
ll min(ll a,double b){
    return (ll)min((double)a,b);
}
ll max(ll a,double b){
    return (ll)max((double)a,b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t;
    ll n;
    ll a,b,c,x1,x2,y1,y2;
    cin>>a>>b>>c>>x1>>x2>>y1>>y2;
    ll x0,y0;
    if(x1>x2||y1>y2){
        cout<<0;
    }
    else if(a==0&&b==0&&c==0){
        cout<<(x2-x1+1)*(y2-y1+1);
    }
    else if(a==0&&b==0){
        cout<<0;
    }
    else if(a==0){
        cout<<(x2-x1+1)*(c%b==0&&-c/b<=y2&&-c/b>=y1);
    }
    else if(b==0){
        cout<<(y2-y1+1)*(c%a==0&&-c/a<=x2&&-c/a>=x1);
    }
    else if(abs(c)%gcd(abs(a),abs(b))!=0){
        cout<<0;
    }
    else{
        ll g=gcd(abs(a),abs(b));
        a/=g,b/=g,c/=g;
        tie(x0,y0)=eea(abs(a),abs(b));
        if(a<0)x0*=-1;
        if(b<0)y0*=-1;
        x0*=-c,y0*=-c;
        ll mt1,mt2;
        if(b<0){
            mt2=floor((x1-x0)/(double)b);
            mt1=ceil((x2-x0)/(double)b);
        }
        else{
            mt2=floor((x2-x0)/(double)b);
            mt1=ceil((x1-x0)/(double)b);
        }
        if(-a<0){
            mt2=min(mt2,floor((y1-y0)/(double)-a));
            mt1=max(mt1,ceil((y2-y0)/(double)-a));
        }
        else{
            mt2=min(mt2,floor((y2-y0)/(double)-a));
            mt1=max(mt1,ceil((y1-y0)/(double)-a));
        }
        if(mt2>=mt1){
            cout<<mt2-mt1+1;
        }
        else cout<<0;
    }

    return 0;
}
