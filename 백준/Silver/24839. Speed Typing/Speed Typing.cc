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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t=1;

    cin>>t;

    for(ll tt=1;tt<=t;tt++){
        cout<<"Case #"<<tt<<": ";
        string p,c;
        cin>>p>>c;
        j=0;
        bool b=0;
        for(i=0;i<p.size();i++,j++){
            while(j<c.size()&&c[j]!=p[i])j++;
            if(j==c.size())b=1;
        }
        if(b)cout<<"IMPOSSIBLE\n";
        else{
            cout<<c.size()-p.size()<<'\n';
        }
    }

    return 0;
}
