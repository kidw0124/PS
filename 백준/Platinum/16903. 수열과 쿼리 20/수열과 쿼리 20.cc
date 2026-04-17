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

struct Trie{
    int cnt;
    vector<Trie*>arr;
    Trie(){
        cnt=0;
        arr.resize(2,nullptr);
    }
};

struct Tree{
    Trie* root;
    Tree(){
        root=new Trie;
        Trie*x=root;
        for(int i=0;i<=30;i++){
            if(x->arr[0]==nullptr){
                x->arr[0]=new Trie;
            }
            x=x->arr[0];
            x->cnt=1;
        }
    }

    void push(int val){
        Trie*x=root;
        val&=~(1<<31);
        val<<=1;
        for(int i=0;i<=30;i++){
            val<<=1;
            if(__builtin_clz(val)==0){
                if(x->arr[1]==nullptr){
                    x->arr[1]=new Trie;
                }
                x=x->arr[1];
            }
            else{
                if(x->arr[0]==nullptr){
                    x->arr[0]=new Trie;
                }
                x=x->arr[0];
            }
            x->cnt++;
        }
    }

    void pop(int val){
        Trie*x=root;
        val&=~(1<<31);
        val<<=1;
        for(ll i=0;i<=30;i++){
            val<<=1;
            if(__builtin_clz(val)==0){
                x=x->arr[1];
            }
            else{
                x=x->arr[0];
            }
            x->cnt--;
        }
    }

    int find(int val){
        Trie*x=root;
        int ans=0;
        val&=~(1<<31);
        val<<=1;
        for(ll i=0;i<=30;i++){
            val<<=1;
            if(__builtin_clz(val)==0){
                if(x->arr[0]!=nullptr&&x->arr[0]->cnt>0){
                    x=x->arr[0];
                    ans|=1<<(30-i);
                }
                else x=x->arr[1];
            }
            else{
                if(x->arr[1]!=nullptr&&x->arr[1]->cnt>0){
                    x=x->arr[1];
                    ans|=1<<(30-i);
                }
                else x=x->arr[0];
            }
        }
        return ans>>1;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    Tree*tree=new Tree;
    for(i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        switch(a){
        case 1:
            tree->push(b);
            break;
        case 2:
            tree->pop(b);
            break;
        case 3:
            cout<<tree->find(b)<<'\n';;
        }
    }

    return 0;
}
