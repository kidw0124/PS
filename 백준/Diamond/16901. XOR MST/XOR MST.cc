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

ll n;
struct Trie{
    vector<int>elements;
    Trie*children[2];
    int depth;
    Trie(int dep){
        elements.clear();
        children[0]=children[1]=nullptr;
        depth=dep;
    }
    void insert(int val){
        int tmp=val;
        Trie*now=this;
        this->elements.push_back(val);
        for(int i=0;i<32;i++){
            if(now->children[__builtin_clz(tmp)==0]==nullptr)now->children[__builtin_clz(tmp)==0]=new Trie(now->depth+1);
            now->children[__builtin_clz(tmp)==0]->elements.push_back(val);
            now=now->children[__builtin_clz(tmp)==0];
            tmp<<=1;
        }
    }

    int find(int val){
        int tmp=val;
        Trie*now=this;
        int ans=1<<(31-this->depth);
        tmp<<=this->depth+1;
        for(int i=this->depth+1;i<32;i++){
            if(now->children[__builtin_clz(tmp)==0]!=nullptr){
                now=now->children[__builtin_clz(tmp)==0];
            }
            else{
                now=now->children[__builtin_clz(tmp)>0];
                ans^=1<<(31-i);
            }
            tmp<<=1;
        }
        return ans;
    }

    ll mst(){
        if(this->elements.size()==0){
            return 0;
        }
        else{
            ll ans=0;
            if(this->children[0]!=nullptr&&this->children[1]!=nullptr){
                ans=INT_MAX;

                for(auto k:this->children[0]->elements){
                    ans=min(ans,(ll)this->children[1]->find(k));
                }
//                for(auto k:this->children[0]->elements){
//                    cout<<k<<' ';
//                }
//                cout<<'\n';
//                for(auto k:this->children[1]->elements){
//                    cout<<k<<' ';
//                }
//                cout<<'\n';
            }
            if(this->children[0]!=nullptr){
                ans+=this->children[0]->mst();
            }
            if(this->children[1]!=nullptr){
                ans+=this->children[1]->mst();
            }
            return ans;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    Trie*root=new Trie(-1);
    rep(i,0,n){
        cin>>j;
        root->insert(j);
    }
    cout<<root->mst();
    return 0;
}
