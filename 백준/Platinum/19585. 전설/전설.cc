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

vector<bool>iii(2005),ii2(2005);

class Trie{
    class Node{
        bool fin=0;
        map<char,Node*>child;
        public: Node(){
            fin=0;
        }
        void insert(const string&str,ll n){
            if(str.size()==n){
                fin=1;
            }
            else{
                ll idx=str[n]-'a';
                if(child.find(idx)!=child.end()){
                    child[idx]->insert(str,n+1);
                }
                else{
                    child[idx]=new Node;
                    child[idx]->insert(str,n+1);
                }
            }
        }
        bool find(const string&str,ll n,bool t){
            if(fin){
                t?iii[n]=1:ii2[n]=1;
            }
            if(str.size()==n){
                return fin;
            }
            else{
                ll idx=str[n]-'a';
                if(child.find(idx)!=child.end()){
                    return child[idx]->find(str,n+1,t);
                }
                else{
                    return false;
                }
            }
        }
    };
    Node*root=new Node;
    public:void insert(const string&str){
        root->insert(str,0);
    }
    bool find(const string&str,ll n,bool t){
        return root->find(str,n,t);
    }
};

Trie color,nick;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll c,n;
    cin>>c>>n;
    vector<string>col(c);
    for(i=0;i<c;i++){
        string str;
        cin>>str;
        color.insert(str);
    }
    for(i=0;i<n;i++){
        string str;
        cin>>str;
        reverse(all(str));
        nick.insert(str);
    }
    ll q;
    cin>>q;
    for(i=0;i<q;i++){
        string str;
        cin>>str;
        fill(all(iii),0);
        fill(all(ii2),0);
        bool x=color.find(str,0,1);
        reverse(all(str));
        bool y=nick.find(str,0,0);
        for(j=0;j<str.size();j++){
            if(iii[j]&&ii2[str.size()-j]){
                cout<<"Yes\n";
                break;
            }
        }
        if(j==str.size())cout<<"No\n";
    }

    return 0;
}
