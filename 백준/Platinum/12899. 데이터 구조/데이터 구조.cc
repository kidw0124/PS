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

const ll MAXN=1<<21;

class Segtree{
private:
public:
    vector<ll>data;
    Segtree(){
        data.resize(MAXN<<1);
    }
    ~Segtree(){
        data.clear();
    }
    void insert(ll x, ll node=1, ll l=1, ll r=MAXN){
        data[node]++;
        if(l==r){
            return;
        }
        else{
            ll mid=(l+r)>>1;
            if(x<=mid){
                insert(x,node<<1,l,mid);
            }
            else insert(x,node<<1|1,mid+1,r);
        }
    }
    void remove(ll x, ll node=1, ll l=1, ll r=MAXN){
        data[node]--;
        if(l==r){
            return;
        }
        else{
            ll mid=(l+r)>>1;
            if(x<=mid){
                remove(x,node<<1,l,mid);
            }
            else remove(x,node<<1|1,mid+1,r);
        }
    }
    int query(ll s,ll e, ll node=1, ll l=1, ll r=MAXN){
        if(s<=l&&r<=e){
            //cout<<node<<' '<<s<<' '<<e<<' '<<l<<' '<<r<<'\n';
            return data[node];
        }
        else if(e<l||r<s){
            return 0;
        }
        else{
            return query(s,e,node<<1,l,(l+r)>>1)+query(s,e,node<<1|1,((l+r)>>1)+1,r);
        }
    }
    int find(ll x, ll node=1, ll l=1, ll r=MAXN){
        if(l==r){
            return l;
        }
        else if(data[node<<1]>x){
            return find(x,node<<1,l,(l+r)>>1);
        }
        else{
            return find(x-data[node<<1],node<<1|1,((l+r)>>1)+1,r);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    Segtree arr;
    while(n--){
        ll q,t;
        cin>>q>>t;
        switch(q){
        case 1:
            arr.insert(t);
            break;
        case 2:
            ll s;
            cout<<(s=arr.find(t-1))<<'\n';
            arr.remove(s);
        }
    }


    return 0;
}
