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

struct trie{
    int depth;
    map<string,trie*>mp;
    trie(int depth){
        this->depth=depth;
    }
};

ll n;
trie*root;
ll k;

ostream& operator<<(ostream& of,trie&x){
    if(x.mp.size()==0)return of;
    else{
        for(auto k:x.mp){
            for(int i=0;i<x.depth;i++){
                of<<"--";
            }
            of<<k.first<<'\n';
            of<<*(k.second);
        }
    }
    return of;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    root=new trie(0);
    for(i=0;i<n;i++){
        cin>>k;
        trie*now=root;
        for(j=0;j<k;j++){
            string s;
            cin>>s;
            if(now->mp.find(s)!=now->mp.end()){
                now=now->mp[s];
            }
            else{
                now->mp[s]=new trie(now->depth+1);
                now=now->mp[s];
            }
        }
    }
    cout<<(trie&)(*root);
    return 0;
}
