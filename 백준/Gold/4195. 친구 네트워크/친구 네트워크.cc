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
ll n,m,t;
map<string,string> par;
map<string,ll>cnt;

string _find(string t){
    if(par[t]==t)return t;
    else {
        //cnt[par[t]]+=cnt[t];
        return par[t]=_find(par[t]);
    }
}

ll _union(string a, string b){
    a=_find(a);
    b=_find(b);
    if(a!=b){
        par[b]=a;
        cnt[a]+=cnt[b];
    }
    return cnt[a];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        par.clear();
        cnt.clear();
        cin>>n;
        for(i=0;i<n;i++){
            string x, y;
            cin>>x>>y;
            if(par.find(x)==par.end()){
                par[x]=x;
                cnt[x]=1;
            }
            if(par.find(y)==par.end()){
                par[y]=y;
                cnt[y]=1;
            }
            cout<<_union(x,y)<<'\n';


        }
    }
    return 0;
}
