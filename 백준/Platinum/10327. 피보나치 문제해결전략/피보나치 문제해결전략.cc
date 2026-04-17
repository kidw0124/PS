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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t;
    cin>>t;
    ll n;
    vector<ll>fibo;
    fibo.push_back(1);
    fibo.push_back(2);
    while(t--){
        cin>>n;
        while(*fibo.rbegin()<n)fibo.push_back(fibo[fibo.size()-1]+fibo[fibo.size()-2]);
        pll ans={n/2+n%2,n/2};
        for(i=0;i<fibo.size()-2;i++){
            ll a,b;
            tie(a,b)=eea(fibo[i],fibo[i+1]);
            a*=n;
            b*=n;
            ll maxt=floor((double)(b-a)/(fibo[i]+fibo[i+1]));
            tie(a,b)=make_pair(a+fibo[i+1]*maxt,b-fibo[i]*maxt);
            if(a<=0||a>b||b<=0)continue;
            else ans=min(ans,{b,a});
        }
        cout<<max(ans.second,1ll)<<' '<<max(ans.first,1ll)<<'\n';
    }

    return 0;
}
