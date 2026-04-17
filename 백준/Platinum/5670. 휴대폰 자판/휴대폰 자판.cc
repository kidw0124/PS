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

class trie{
    public:
    vector<trie*>child;
    int cnt;
    bool end;
    trie(){
        child.resize(26,NULL);
        cnt=0;
        end=false;
    }
    ~trie(){
        for(auto k:child){
            if(k)delete k;
        }
        child.clear();
    }
    void insert(string::iterator it,string::iterator en){
        if(it==en){
            end=true;
            return;
        }
        else{
            int x=(*it)-'a';
            if(!child[x]){
                cnt++;
                child[x]=new trie();
            }
            child[x]->insert(it+1,en);
        }
    }
    int count(string::iterator it,string::iterator en){
        if(it==en){
            return 0;
        }
        int ret=(cnt>=2||(cnt==1&&end));
        return ret+child[(*it)-'a']->count(it+1,en);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t;
        ll n;
    while(cin>>n){
        trie*arr=new trie();
        vector<string>brr(n);
        for(i=0;i<n;i++){
            cin>>brr[i];
            arr->insert(brr[i].begin(),brr[i].end());
        }
        ll x=0;
        for(i=0;i<n;i++){
            x+=arr->count(brr[i].begin(),brr[i].end());
        }
        if(arr->cnt==1)x+=n;
        cout<<fixed<<setprecision(2)<<x/(double)n<<'\n';
        delete arr;
    }


    return 0;
}
